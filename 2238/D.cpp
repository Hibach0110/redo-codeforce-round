#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int spf[MAXN];

void sieve() {
     for (int i = 1; i < MAXN; i++) spf[i] = i;
     for (int i = 2; i * i < MAXN; i++) {
          if (spf[i] == i) {
               for (int j = i * i; j < MAXN; j += i) {
                    if (spf[j] == j) spf[j] = i;
               }
          }
     }
}
vector<pair<int, int>> fct(int N) {
     vector<pair<int, int>> res;
     while (N > 1) {
          int p = spf[N];
          int cnt = 0;
          while (N % p == 0) {
               cnt++; N /= p;
          }
          res.push_back({p, cnt});
     }
     return res;
}

void solve() {
     int N; cin >> N;
     vector<pair<int, int>> fN = fct(N);
     int Np = fN.size();
     int ans = Np;
     for (int i = 0; i < Np; i++) ans += fN[i].second;
     cout << ans-1 << "\n";
}

int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     sieve();

     int tc; cin >> tc;
     while (tc--) {
          solve();
     }

     return 0;
}
