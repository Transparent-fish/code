#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int, pair<int, int>>> e[1000005];
int n, m, dfn[100005], low[100005], tot, ans = 1e9;

void dfs(int x, int last) {
  tot++;
  dfn[x] = low[x] = tot;
  for (int i = 0; i < e[x].size(); i++) {
    int v = e[x][i].first;
    int cnt = e[x][i].second.first;
    if (cnt == last) continue;
    if (dfn[v] == 0) {
      dfs(v, cnt);
      low[x] = min(low[x], low[v]);
      if (low[v] > dfn[x]) ans = min(ans, e[x][i].second.second);
    } else {
      low[x] = min(low[x], dfn[v]);
    }
  }
}

signed main() {
  for (; cin >> n >> m;) {
    if (n + m == 0) break;
    for (int i = 1; i <= n; i++) {
      dfn[i] = low[i] = 0;
      e[i].clear();
    }
    int cnt = 0;
    tot = 0;
    ans = 1e9;
    for (int i = 1; i <= m; i++) {
      int x, y, w;
      cin >> x >> y >> w;
      e[x].push_back({y, {++cnt, w}});
      e[y].push_back({x, {cnt, w}});
    }
    for (int i = 1; i <= n; i++) {
      if (dfn[i] == 0) {
        dfs(i, 0);
      }
    }
    if (ans != 1e9)
      cout << ans << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
