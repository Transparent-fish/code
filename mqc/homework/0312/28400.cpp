#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5, Mod = 1e9 + 7;
int n, l, r, f[N][3], a[3];

void init() {
  a[0] = r / 3 - (l - 1) / 3;
  a[1] = (r + 2) / 3 - (l + 1) / 3;
  a[2] = (r + 1) / 3 - (l) / 3;
  f[1][0] = a[0];
  f[1][1] = a[1];
  f[1][2] = a[2];
}

void update(int i) {
  f[i][0] += (f[i - 1][0] * a[0]) % Mod;
  f[i][0] %= Mod;
  f[i][0] += (f[i - 1][1] * a[2]) % Mod;
  f[i][0] %= Mod;
  f[i][0] += (f[i - 1][2] * a[1]) % Mod;
  f[i][0] %= Mod;
  f[i][1] += (f[i - 1][1] * a[0]) % Mod;
  f[i][1] %= Mod;
  f[i][1] += (f[i - 1][2] * a[2]) % Mod;
  f[i][1] %= Mod;
  f[i][1] += (f[i - 1][0] * a[1]) % Mod;
  f[i][1] %= Mod;
  f[i][2] += (f[i - 1][2] * a[0]) % Mod;
  f[i][2] %= Mod;
  f[i][2] += (f[i - 1][0] * a[2]) % Mod;
  f[i][2] %= Mod;
  f[i][2] += (f[i - 1][1] * a[1]) % Mod;
  f[i][2] %= Mod;
}

signed main() {
  cin >> n >> l >> r;
  init();
  for (int i = 2; i <= n; i++) {
    update(i);
  }
  cout << f[n][0];
  return 0;
}
