#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e2 + 5;
int a[MAXN], b[MAXN];

void solve() {
     int N, C; cin >> N >> C;
     vector<int> a(N), b(N);
     for (int &x : a) cin >> x;
     for (int &x : b) cin >> x;
     int ans = 0;
     for (int i = 0; i < N; i++) {
          if (a[i] < b[i]) {ans = INT_MAX; break;}
          ans += a[i] - b[i];
     }
     if (ans == INT_MAX) {
          ans = 0;
          sort(a.begin(), a.end()); sort(b.begin(), b.end());
          for (int i = 0; i < N; i++) {
               if (a[i] < b[i]) {cout << -1 << "\n"; return;}
               ans += a[i] - b[i];
          }
          ans += C;
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
