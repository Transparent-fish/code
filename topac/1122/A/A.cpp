#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], k[N], dp[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("chess.in", "r", stdin);
  // freopen("chess.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 0x3f3f3f3f;
  }
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  dp[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= min(n - i, k[i]); j++) {
      if (i + j == n)
        dp[i + j] = min(dp[i + j], dp[i] + 1);
      else
        dp[i + j - a[j]] = min(dp[i + j - a[j]], dp[i] + 1);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << dp[i] << "\n";
  // }
  if (dp[n] == 0x3f3f3f3f)
    cout << "-1";
  else
    cout << dp[n];
  return 0;
}