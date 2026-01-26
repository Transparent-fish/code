#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt = -1, tot, res, now;
int head[N], low[N], dfn[N], vis[N], f[N], book[N];

struct node {
  int nex, to;
} e[N << 1];

void add(int x, int y) {
  e[++cnt].nex = head[x];
  e[cnt].to = y;
  head[x] = cnt;
}

void tarjan(int x, int las) {
  dfn[x] = low[x] = ++tot;
  for (int i = head[x]; i != -1; i = e[i].nex) {
    if (i == (las ^ 1)) continue;
    int v = e[i].to;
    if (!dfn[v]) {
      tarjan(v, i);
      low[x] = min(low[x], low[v]);
      if (low[v] > dfn[x]) {
        res++;
        vis[i] = vis[i ^ 1] = 1;
      }
    } else
      low[x] = min(low[x], dfn[v]);
  }
}

void dfs(int x, int fa) {
  book[x] = 1;
  for (int i = head[x]; i != -1; i = e[i].nex) {
    int v = e[i].to;
    if (v == fa || book[v] == 1) continue;
    dfs(v, x);
    now = max(f[x] + f[v] + vis[i], now);
    f[x] = max(f[x], f[v] + vis[i]);
  }
}

signed main() {
  for (; cin >> n >> m;) {
    cnt = -1, tot = 0, res = 0;
    for (int i = 1; i <= n; i++) {
      head[i] = -1;
      low[i] = dfn[i] = vis[i] = f[i] = book[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) tarjan(i, -1);
    }
    dfs(1, 0);
    cout << res - now << "\n";
  }
  return 0;
}