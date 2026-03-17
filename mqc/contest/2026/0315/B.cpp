#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int n, t[N], c[N], dp[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> c[i];
    dp[i] = LLONG_MAX;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = t[i]; j >= 1; j--) {
      dp[j] = min(dp[j ], dp[j - c[i] - 1] + c[i]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  return 0;
}