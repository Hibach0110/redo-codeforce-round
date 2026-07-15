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
          int n, x, y; cin >> n >> x >> y;
          vector<int> a(n);
          for (int i = 0; i < n; i++) {
               cin >> a[i];
          } 
          int g = __gcd(x, y);
          bool can = true;
          for (int i = 0; i < n; i++) {
               int curPos = i+1;
               int need = abs(a[i] - curPos);
               need %= g;
               if (need != 0) {
                    can = false; break;
               }
          }
          cout << (can ? "YES" : "NO") << "\n";
     }

     return 0;
}
