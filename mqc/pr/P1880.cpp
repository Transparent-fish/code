#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, a[N * 2], f[N * 2][N * 2], sum[N * 2], ff[N * 2][N * 2];

signed main() {
  cin >> n;
  memset(f, 0x3f, sizeof(f));
  memset(ff, 0xcf, sizeof(ff));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  for (int i = 1; i <= n * 2; i++) {
    for (int j = 1; j <= n * 2; j++) {
      if (i == j) f[i][j] = 0, ff[i][j] = 0;
    }
  }
  for (int i = 1; i <= n * 2; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n * 2; i++) {
      int j = i + len - 1;
      for (int k = i; k < j; k++) {
        f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + sum[j] - sum[i - 1]);
        ff[i][j] = max(ff[i][j], ff[i][k] + ff[k + 1][j] + sum[j] - sum[i - 1]);
      }
    }
  }
  int Min = 0x3f3f3f3f, Max = -1e9;
  for (int i = 1; i <= n; i++) {
    Min = min(Min, f[i][i + n - 1]);
    Max = max(Max, ff[i][i + n - 1]);
  }
  cout << Min << "\n" << Max;
  return 0;
}