#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, dfn[N], low[N], son[N], ans[N], cnt = -1, tot, res, head[N];

struct node {
  int nex, to;
} e[N * 2];

void add(int x, int y) {
  e[++cnt].nex = head[x];
  e[cnt].to = y;
  head[x] = cnt;
}

void tarjan(int x, int las, int root) {
  dfn[x] = low[x] = ++tot;
  int son = 0;
  for (int i = head[x]; i != -1; i = e[i].nex) {
    int v = e[i].to;
    if (i == (las ^ 1)) continue;
    if (!dfn[v]) {
      son++;
      tarjan(v, i, root);
      low[x] = min(low[x], low[v]);
      if (x != root && low[v] >= dfn[x]) ans[x] = 1;
      if (x == root && son >= 2) ans[x] = 1;
    } else
      low[x] = min(low[x], dfn[v]);
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    head[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    add(x, y);
    add(y, x);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, -1, i);
  }
  int now = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] != 0) now++;
  }
  cout << now << "\n";
  for (int i = 1; i <= n; i++) {
    if (ans[i] == 1) cout << i << " ";
  }
  return 0;
}