#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e2 + 5;
int n, m, a[N], dp[N][N], f[N][N], l[N], r[N];

void Scanf() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    a[i + n] = a[i];
  }
  for (int i = 1; i < 2 * n; i++) {
    l[i] = a[i];
    r[i] = a[i + 1];
  }
}

void Printf() {
  for (int i = n * 2; i >= 1; i--) {
    for (int j = i + 1; j < min(i + n, 2 * n); j++) {
      for (int k = i; k < j; k++) {
        f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + l[i] * r[j] * r[k]);
      }
    }
  }
  int Ans = 1e9, ans = 0;
  for (int i = 1; i <= n; i++) {
    Ans = min(Ans, dp[i][i + n - 1]);
    ans = max(ans, f[i][i + n - 1]);
  }
  cout << ans;
}

signed main() {
  Scanf(), Printf();
  return 0;
}