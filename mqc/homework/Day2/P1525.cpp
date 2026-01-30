#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, fa[N];

struct node {
  int x, y, z;
  friend bool operator<(node a, node b) { return a.z > b.z; }
} a[N];

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
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  sort(a + 1, a + m + 1);
  for (int i = 1; i <= m; i++) {
    int u = a[i].x, v = a[i].y;
    update(u, v + n), update(v, u + n);
    if (find(u) == find(u + n) || find(v) == find(v + n)) {
      cout << a[i].z;
      exit(0);
    }
  }
  cout << 0;
  return 0;
}