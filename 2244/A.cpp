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
          int n; cin >> n;
          string s; cin >> s;
          int len = (s[0] == '#' ? 1 : 0);
          int mxLen = len;
          for (int i = 1; i < n; i++) {
               if (s[i-1] != '#' && s[i] == '#') len = 1;
               if (s[i-1] == '#' && s[i] == '#') len++;
               mxLen = max(mxLen, len);
          }
          cout << (mxLen+1) / 2 << "\n";
     }

     return 0;
}
