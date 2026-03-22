#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, dis[N][3], son[N][3], g[N], f[N];
vector<int> e[N];

void dfs(int x, int fa) {
  for (auto c : e[x]) {
    if (c == fa) continue;
    dfs(c, x);
    f[x] = max(f[x], f[c] + 1);
    if (dis[c][0] + 1 > dis[x][1]) {
      dis[x][1] = dis[c][0] + 1;
      son[x][1] = c;
    }
    if (dis[x][1] > dis[x][0]) {
      swap(dis[x][1], dis[x][0]);
      swap(son[x][1], son[x][0]);
    }
  }
}

void dfs1(int x, int fa) {
  if (x == 1) {
    g[x] = 0;
  } else {
    g[x] = g[fa] + 1;
    if (son[fa][0] == x)
      g[x] = max(g[x], dis[fa][1] + 1);
    else
      g[x] = max(g[x], dis[fa][0] + 1);
  }
  for (auto c : e[x]) {
    if (c == fa) continue;
    dfs1(c, x);
  }
}

signed main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0), dfs1(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << max(f[i], g[i]) << " ";
  }
  return 0;
}