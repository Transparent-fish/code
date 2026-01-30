#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m, fa[N << 1];
set<int> s;

int find(int x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

void update(int x, int y) {
  int fx = find(x), fy = find(y);
  if (fx != fy) {
    if (fx < fy) swap(fx, fy);
    fa[fx] = fy;
  }
}

void init() {
  for (int i = 1; i <= (n << 1); i++) {
    fa[i] = i;
  }
}

signed main() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= m; i++) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'E') {
      update(x, y + n);
      update(y, x + n);
    } else {
      update(x, y);
      // update(x + n, y + n);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == find(i)) cnt++;
  }
  cout << cnt;
  return 0;
}