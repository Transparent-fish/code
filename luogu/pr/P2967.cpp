#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, f[N], tmp[N];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int cnt, tot;
    cin >> cnt >> tot;
    memset(f, 0xcfcfcfcf, sizeof(f));
    for (int j = cnt; j <= m; j++) {
      f[j] = tmp[j - cnt];
    }
    for (; tot--;) {
      int x, y;
      cin >> x >> y;
      for (int j = m; j >= x; j--) {
        f[j] = max(f[j], f[j - x] + y);
      }
    }
    for (int j = 0; j <= m; j++) {
      f[j] = max(f[j], tmp[j]);
      tmp[j] = f[j];
    }
  }
  cout << f[m];
  return 0;
}