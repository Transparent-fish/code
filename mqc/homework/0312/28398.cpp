#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, mod = 1e9 + 7;
int n, k, d, dp[N][2];

signed main() {
  cin >> n >> k >> d;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(i, k); j++) {
      if (j < d) {
        dp[i][0] += dp[i - j][0];
        dp[i][0] %= mod;
      }
      dp[i][1] += dp[i - j][1];
      dp[i][1] %= mod;
      if (j >= d) {
        dp[i][1] += dp[i - j][0];
        dp[i][1] %= mod;
      }
    }
  }
  cout << dp[n][1];
  return 0;
}