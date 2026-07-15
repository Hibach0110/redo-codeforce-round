#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second

using ll = long long;
using pii = pair<ll, ll>;
const int N = 2e5 + 5;

struct Fenwick {
     int n; 
     vector<ll> t;

     Fenwick(int n) : n(n), t(n + 1, 0ll) {}

     int f(int x) {
          return x & -x;
     }

     void upd(int pos, ll val) {
          for (; pos <= n; pos += f(pos)) t[pos] = max(t[pos], val);
     }

     ll get(int pos) {
          ll ans = 0;
          for (; pos > 0; pos -= f(pos)) ans = max(ans, t[pos]);
          return ans;
     }
};

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);  
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     int tc; cin >> tc;
     while (tc--) {
          int n; cin >> n;
          vector<int> a(n);
          for (int i = 0; i < n; i++) {
               cin >> a[i];
          }
          Fenwick t(n);
          vector<vector<pii>> events(n+1);
          ll ans = 0;
          for (int i = 1; i <= n; i++) {
               for (pii event : events[i]) {
                    t.upd(event.fi, event.se);
               }
               int lim = i - a[i-1] - 1;
               ll mx = 0;
               if (lim > 0) mx = t.get(lim);
               ll dp_i = mx + a[i-1];
               ans = max(ans, dp_i);
               int act = i + a[i-1] + 1;
               if (act <= n) {
                    events[act].push_back({i, dp_i});
               }
          }
          cout << ans << "\n";
     }

     return 0;
}
