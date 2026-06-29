#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 5;

void solve() {
     int N; cin >> N;
     int64_t ans = 0;
     for (int i = 1; i <= N; i++) { // fix b
          int x = N / i;
          ans += 1ll * x * x;
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
