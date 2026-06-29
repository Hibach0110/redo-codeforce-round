#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e2 + 5;
const int INF = 1e9;

void solve() {
     int N; cin >> N; string S; cin >> S;
     
     int ans = 0;
     for (int K = 0; K <= N; K++) {
          vector<int> dp(K+1, -INF);
          dp[0] = 0;
          for (int i = 0; i < N; i++) {
               vector<int> nxt(K+1, -INF);     
               for (int d = 0; d <= K; d++) {
                    if (S[i] != 'T') {
                         if (d+1 <= K) nxt[d+1] = max(nxt[d+1], dp[d] + 1);
                    }
                    if (S[i] != 'F') {
                         int next_d = max(0, d-1);
                         nxt[next_d] = max(nxt[next_d], dp[d]);
                    }
               }
               dp = nxt;
          }
          int max_F = -INF;
          for (int d = 0; d <= K; d++) max_F = max(max_F, dp[d]);
          if (max_F != -INF) ans = max(ans, max_F - K);
     }
     cout << ans << "\n";
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);

     int tc; cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
