#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG
const int N = 1e6 + 5;
int n, q, sum, dep[N], siz[N];

struct Node {
  int u, v, w;
} a[N];

struct node {
  int u, w;
};
vector<node> e[N];

void dfs(int x, int fa, int de) {
  dep[x] = de;
  siz[x] = 1;
  for (auto c : e[x]) {
    if (c.u == fa) continue;
    dfs(c.u, x, de + 1);
    siz[x] += siz[c.u];
  }
}

void init() {
  dfs(1, 0, 1);
  for (int i = 1; i < n; i++) {
    int now = 0;
    if (dep[a[i].u] > dep[a[i].v])
      now = a[i].u;
    else if (dep[a[i].u] < dep[a[i].v])
      now = a[i].v;
    sum += siz[now] * (n - siz[now]) * a[i].w;
  }
}

signed main() {
  freopen("tree.in", "r", stdin);
  freopen("tree.out", "w", stdout);
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[i] = {u, v, w};
    e[u].push_back({v, w});
    e[v].push_back({u, w});
  }
  init();
#ifdef DEBUG
  cout << sum << "\n";
#endif
  for (; q--;) {
    int id, w, now;
    cin >> id >> w;
    if (dep[a[id].u] > dep[a[id].v])
      now = a[id].u;
    else if (dep[a[id].u] < dep[a[id].v])
      now = a[id].v;
    if (a[id].w > w) {
      sum -= siz[now] * (n - siz[now]) * (a[id].w - w);
    } else {
      sum += siz[now] * (n - siz[now]) * (w - a[id].w);
    }
    cout << sum << "\n";
    a[id].w = w;
  }
  return 0;
}