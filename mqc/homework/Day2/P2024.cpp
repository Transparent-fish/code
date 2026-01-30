#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, fa[N];

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
  for (int i = 1; i <= (n << 2); i++) {
    fa[i] = i;
  }
}

signed main() {
  cin >> n >> k;
  init();
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    int op, x, y;
    cin >> op >> x >> y;
    if ((x > n || y > n) || (op == 2 && x == y)) {
      cnt++;
      continue;
    }
    if (op == 1) {
      if (find(x) == find(y + n) || find(x + n) == find(y + (n << 1)) ||
          (find(x) == find(y + (n << 1)))) {
        cnt++;
        continue;
      }
      update(x, y), update(x + n, y + n), update(x + (n << 1), y + (n << 1));
    } else if (op == 2) {
      if (find(x) == find(y) || find(x + n) == find(y + n) ||
          (find(y + (n << 1)) == find(x + (n << 1))) ||
          (find(y) == find(x + n)) || (find(y + n) == find(x + (n << 1))) ||
          find(y + (n << 1) == find(x))) {
        cnt++;
        continue;
      }
      update(x, y + n), update(x + n, y + (n << 1)), update(x + (n << 1), y);
    }
  }
  cout << cnt;
  return 0;
}