#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second

using ll = long long;
using pii = pair<ll, ll>;
const int N = 2e5 + 5;

int a[N];
vector<int> adj[N];
pii node[N];

bool dfs(int u) {
     if (a[u]) {
          node[u] = {a[u], a[u]}; return true;
     }
     vector<pii> childs;
     int idx = 0, mn = 1e8;
     for (int v : adj[u]) {
          if (!dfs(v)) return false;
          childs.push_back(node[v]);
          if (childs.back().fi < mn) {
               mn = childs.back().fi;
               idx = sz(childs)-1;
          }
     }
     
     for (int i = 0; i < sz(childs)-1; i++) {
          int curIdx = (idx + i) % sz(childs);
          int nxtIdx = (idx + i + 1) % sz(childs);
          if (childs[curIdx].se >= childs[nxtIdx].fi) return false;
     }
     int lstIdx = (idx + sz(childs) - 1) % sz(childs);
     node[u] = {childs[idx].fi, childs[lstIdx].se};
     return true;
}

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
          for (int i = 1; i <= n; i++) {
               adj[i].clear();
               node[i] = {1e8, -1e8};
          }
          for (int i = 2; i <= n; i++) {
               int p; cin >> p;
               adj[p].push_back(i);
          }
          for (int i = 1; i <= n; i++) {
               cin >> a[i];
          }
          cout << (dfs(1) ? "YES" : "NO") << "\n";
     }

     return 0;
}
