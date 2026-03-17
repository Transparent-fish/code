#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, a[N], dp[N];

signed main() {
  cin >> T;
  for (; T--;) {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i], dp[i] = a[i];
      for (int j = 1; j < i; j++) {
        if (a[j] <= a[i]) {
          dp[i] = max(dp[i], dp[j] + a[i]);
        }
      }
      ans = max(ans, dp[i]);
    }
    cout << sum - ans << "\n";
  }
  return 0;
}