#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int dp[MAXN], mx[MAXN];

void dfs(int u) {
     dp[u] = 1; mx[u] = 0;
     int child = 0, mx1 = 0, mx2 = 0;
     for (int v : adj[u]) {
          dfs(v);
          child++;
          if (mx[v] + 1 >= mx1) {
               mx2 = mx1; mx1 = mx[v] + 1;
          } else if (mx[v] + 1 >= mx2) {
               mx2 = mx[v] + 1;
          }
     }
     mx[u] = mx1;
     if (child > 1) {
          dp[u] += mx2;
     }
}

void solve() {
     int N; cin >> N;
     for (int i = 1; i <= N; i++) {
          adj[i].clear();
     }
     for (int i = 2; i <= N; i++) {
          int p; cin >> p; 
          adj[p].push_back(i);
     }
     dfs(1);
     int64_t ans = 0;
     for (int i = 1; i <= N; i++) ans += dp[i];
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
