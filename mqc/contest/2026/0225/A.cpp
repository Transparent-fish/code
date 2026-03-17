#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, s, Max, a[N];
bool dp[N][N];

signed main() {
#ifdef __linux__
  freopen("max.in", "r", stdin);
  freopen("max.out", "w", stdout);
#endif

  cin >> n >> s >> Max;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][s] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= Max; j++) {
      if (dp[i - 1][j] == 1) {
        if (j - a[i] >= 0) dp[i][j - a[i]] = 1;
        if (a[i] + j <= Max) dp[i][a[i] + j] = 1;
      }
    }
  }
  for (int i = Max; i >= 0; i--) {
    if (dp[n][i] == 1) {
      cout << i;
      exit(0);
    }
  }
  cout << -1;
  return 0;
}