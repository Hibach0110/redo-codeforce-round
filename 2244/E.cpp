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
          int n, q; cin >> n >> q;
          string s; cin >> s;
          
          vector<int> pfs(n+1, 0);
          for (int i = 1; i < n; i++) {
               pfs[i] = pfs[i-1] + (s[i-1] == s[i] ? 1 : 0);
          }

          while (q--) {
               int l, r, k; cin >> l >> r >> k;
               if (l == r) {
                    cout << "YES\n"; continue;
               }
               int ans = pfs[r-1] - pfs[l-1];
               cout << ((ans + 1) / 2 <= k ? "YES" : "NO") << "\n"; 
          }
     }

     return 0;
}
