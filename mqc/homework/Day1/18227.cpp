#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, dfn[N], low[N], cnt = -1, tot, res, head[N];

struct node {
  int nex, to;
} e[N * 2];

void add(int x, int y) {
  e[++cnt].nex = head[x];
  e[cnt].to = y;
  head[x] = cnt;
}

void tarjan(int x, int las) {
  dfn[x] = low[x] = ++tot;
  for (int i = head[x]; i != -1; i = e[i].nex) {
    int v = e[i].to;
    if (i == (las ^ 1)) continue;
    if (!dfn[v]) {
      tarjan(v, i);
      low[x] = min(low[x], low[v]);
      if (low[v] > dfn[x]) res++;
    } else
      low[x] = min(low[x], dfn[v]);
  }
}

signed main() {
  for (; cin >> n >> m;) {
    if (n == 0 && m == 0) break;
    int x, y;
    cnt = -1, res = 0, tot = 0;
    for (int i = 1; i <= n; i++) {
      dfn[i] = low[i] = 0;
      head[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
      cin >> x >> y;
      add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++) {
      if (!dfn[i]) tarjan(i, -1);
    }
    cout << res << "\n";
  }
  return 0;
}