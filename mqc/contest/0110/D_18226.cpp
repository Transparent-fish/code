#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 998244353;
int n, m, x, cnt, a[N], b[N];
map<pair<int, int>, int> f;

void dfs(int x, int y) {
  if (x >= 1 && x <= n && y >= 1 && y <= m) {
    f[{x, y}] = 0;
    if (f[{x + 1, y}] == 1) dfs(x + 1, y);
    if (f[{x - 1, y}] == 1) dfs(x - 1, y);
    if (f[{x, y + 1}] == 1) dfs(x, y + 1);
    if (f[{x, y - 1}] == 1) dfs(x, y - 1);
  }
}

signed main() {
#ifdef __linux__
  freopen("black.in", "r", stdin);
  freopen("black.out", "w", stdout);
#endif
  cin >> n >> m >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i] + b[j] <= x) f[{i, j}] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (f[{i, j}] == 1) {
        dfs(i, j), cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}