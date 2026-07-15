#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second

using ll = long long;
using pii = pair<ll, ll>;
const int N = 2e5 + 5;

int main() {
     ios_base::sync_with_stdio(false); cin.tie(NULL);  
     #ifndef ONLINE_JUDGE
     // freopen("input.txt", "r", stdin);
     // freopen("output.txt", "w", stdout);
     #endif
     // cout << fixed << setprecision(12);

     int tc; cin >> tc;
     while (tc--) {
          int n, m; cin >> n >> m;
          vector<int> a(n), b(m);
          vector<ll> sum(n+5, 0);
          for (int i = 0; i < n; i++) {
               cin >> a[i]; 
               sum[i+1] = sum[i] + a[i];
          }
          for (int i = 0; i < m; i++) {
               cin >> b[i];
          }
          sort(all(b));
          
          ll ans = 0;
          for (int i = 0; i < m; i++) {
               int prvIdx = (i == 0 ? 0 : b[i-1]);
               ans += abs(sum[b[i]] - sum[prvIdx]);
          }
          ans += sum[n] - sum[b[m-1]];
          cout << ans << "\n";
     }

     return 0;
}
