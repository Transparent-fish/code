#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int n, m;
int dfn[N], low[N], book[N], cnt, tot;
int id[N];
stack<int> stk;
vector<int> e[N];
vector<int> g[N];

void tarjan(int x) {
  low[x] = dfn[x] = ++cnt;
  stk.push(x);
  book[x] = 1;
  for (int v : e[x]) {
    if (!dfn[v]) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (book[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (low[x] == dfn[x]) {
    int v;
    ++tot;
    do {
      v = stk.top();
      stk.pop();
      book[v] = 0;
      id[v] = tot;
      g[tot].push_back(v);
    } while (x != v);
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, t;
    cin >> u >> v >> t;
    e[u].push_back(v);
    if (t == 2) e[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  int Max = 0, cnt = 0;
  for (int i = 1; i <= tot; i++) {
    sort(g[i].begin(), g[i].end());
    int now = g[i].size();
    if (now > Max) {
      Max = now;
      cnt = i;
    } else if (now == Max) {
      if (cnt == 0 || g[i][0] < g[cnt][0]) {
        cnt = i;
      }
    }
  }
  cout << Max << "\n";
  for (int i = 0; i < g[cnt].size(); i++) {
    cout << g[cnt][i] << " ";
  }
  return 0;
}