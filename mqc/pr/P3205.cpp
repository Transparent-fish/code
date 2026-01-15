#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005, Mod = 19650827;
int n, a[N], f[N][N][2];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i][i][0] = 1;
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i + l - 1 <= n; i++) {
      int j = i + l - 1;
      if (a[i] < a[i + 1]) (f[i][j][0] += f[i + 1][j][0]) %= Mod;
      if (a[i] < a[j]) (f[i][j][0] += f[i + 1][j][1]) %= Mod;
      if (a[j] > a[i]) (f[i][j][1] += f[i][j - 1][0]) %= Mod;
      if (a[j] > a[j - 1]) (f[i][j][1] += f[i][j - 1][1]) %= Mod;
    }
  }
  cout << (f[1][n][0] + f[1][n][1]) % Mod;
  return 0;
}