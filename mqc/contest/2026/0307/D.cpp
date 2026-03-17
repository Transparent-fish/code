#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, sum, a[N], dp[N][20];

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= 1; j--) {
      dp[i][j] = max(dp[i][j - 1], dp[i][j] + a[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] != -1) sum += dp[i][j];
    }
  }
  cout << sum;
  return 0;
}
/*
dp[i] = max(dp[i])
*/