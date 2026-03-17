#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, mod = 998244353;
int n, m, a[N], b[N], f[N][N];

void dfs(int x, int y) {
  f[x][y] = 0;
  if (f[x + 1][y] == 1) dfs(x + 1, y);
  if (f[x - 1][y] == 1) dfs(x - 1, y);
  if (f[x][y + 1] == 1) dfs(x, y + 1);
  if (f[x][y - 1] == 1) dfs(x, y - 1);
}

signed main() {
#ifdef __linux__
  freopen("black.in", "r", stdin);
  freopen("black.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  
  return 0;
}