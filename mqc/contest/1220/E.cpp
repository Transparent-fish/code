#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, Max, fa[N];

struct node {
  int a, b, c;
  friend bool operator<(node a, node b) { return a.c > b.c; }
} a[N];

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
}

void init() {
  for (int i = 1; i <= m; i++) {
    fa[i] = i;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].a >> a[i].b >> a[i].c;
  }
  sort(a + 1, a + m + 1);
  init();
  for (int i = 1; i <= m; i++) {
    if (find(a[i].a) != find(a[i].b)) {
      fa[find(a[i].b)] = fa[find(a[i].a + n)];
      fa[find(a[i].a)] = fa[find(a[i].b + n)];
    } else {
      Max = max(Max, a[i].c);
    }
  }
  cout << Max;
  return 0;
}