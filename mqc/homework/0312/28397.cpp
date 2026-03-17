#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int t, k, dp[N];

void init() {
  dp[0] = 1;
  for (int i = 1; i <= N; i++) {
    if (i - k >= 0)
      dp[i] = (dp[i - 1] + dp[i - k]) % mod;
    else
      dp[i] = dp[i - 1];
  }
  for (int i = 1; i <= N; i++) {
    dp[i] += dp[i - 1];
    dp[i] %= mod;
  }
}

signed main() {
  cin >> t >> k;
  init();
  for (; t--;) {
    int a, b;
    cin >> a >> b;
    cout << (dp[b] - dp[a - 1] + mod) % mod << "\n";
  }
  return 0;
}