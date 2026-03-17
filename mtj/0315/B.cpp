#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 25;
int x, y;
d dp[N];

signed main() {
  cin >> x >> y;
  dp[0] = 0;
  for (int i = 1; i <= y; i++) {
    dp[i] = dp[i - 1] + x;
    if (i >= 2) {
      dp[i] = min(dp[i], dp[i - 2] + 9.9 + x);
    }
    if (i >= 6) {
      dp[i] = min(dp[i], dp[i - 6] + 5 * x);
    }
  }
  d ans = dp[y];
  if (ans == (int)ans) {
    cout << (int)ans << '\n';
  } else {
    cout << fixed << setprecision(1) << ans << '\n';
  }
  return 0;
}