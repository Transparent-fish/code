#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k, a[N], f[N];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(f, 1e9, sizeof(f));
  f[0] = 0, f[1] = 0;
  for (int i = 1; i <= n; i++) {
    if (f[i] > a[i]) {
      if (k > 0) {
        f[i] = min(f[i], f[i - 1] + a[i]);
      } else {
        f[i] = min(f[i], f[i - 1]);
      }
    } else {
      f[i] = min(f[i], f[i - 1]);
    }
  }
  cout << 0;
  return 0;
}