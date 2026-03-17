#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y, z, a[100010], b[100010];

signed main() {
  cin >> n >> x >> y >> z;
  b[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i >= j * x && b[i - j * x]) {
        b[i] = 1;
        a[i] = max(a[i - j * x] + 1, a[i]);
      }
      if (i >= j * y && b[i - j * y]) {
        b[i] = 1;
        a[i] = max(a[i - j * y] + 1, a[i]);
      }
      if (i >= j * z && b[i - j * z]) {
        b[i] = 1;
        a[i] = max(a[i - j * z] + 1, a[i]);
      }
    }
  }
  cout << a[n];
  return 0;
}