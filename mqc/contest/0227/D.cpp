#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 305, M = 105;
int n, m, q, a[N][N], tree[M][N][N];

int lowbit(int x) { return x & -x; }

void update(int v, int x, int y, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) {
      tree[v][i][j] += c;
    }
  }
}

int query(int c, int x, int y) {
  int ans = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    for (int j = y; j >= 1; j -= lowbit(j)) {
      ans += tree[c][i][j];
    }
  }
  return ans;
}

int op2(int x, int y, int xx, int yy, int c) {
  return query(c, xx, yy) - query(c, xx, y - 1) - query(c, x - 1, yy) +
         query(c, x - 1, y - 1);
}

signed main() {
#ifdef __linux__
  freopen("cnt.in", "r", stdin);
  freopen("cnt.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      update(a[i][j], i, j, 1);
    }
  }
  cin >> q;
  for (; q--;) {
    int op, x, y, x_1, y_1, c;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> c;
      if (a[x][y] != c) {
        update(a[x][y], x, y, -1);
        a[x][y] = c;
        update(a[x][y], x, y, 1);
      }
    } else {
      cin >> x >> x_1 >> y >> y_1 >> c;
      cout << op2(x, y, x_1, y_1, c) << "\n";
    }
  }
  return 0;
}