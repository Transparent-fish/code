#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, m, tot, dfn[N], low[N], book[N], id[N], num;
stack<int> sk;
vector<int> e[N];

void tarjan(int x) {
  low[x] = dfn[x] = ++tot;
  sk.push(x);
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
    ++num;
    do {
      v = sk.top();
      sk.pop();
      book[v] = 0;
      id[v] = num;
    } while (x != v);
  }
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c, d;
    cin >> a >> c >> b >> d;
    if (c == 1 && d == 1) {
      e[a + n].push_back(b);
      e[b + n].push_back(a);
    } else if (c == 1 && d == 0) {
      e[a + n].push_back(b + n);
      e[b].push_back(a);
    } else if (c == 0 && d == 1) {
      e[a].push_back(b);
      e[b + n].push_back(a + n);
    } else {
      e[a].push_back(b + n);
      e[b].push_back(a + n);
    }
  }
  for (int i = 1; i <= (n << 1); i++) {
    if (!dfn[i]) tarjan(i);
  }
  for (int i = 1; i <= n; i++) {
    if (id[i] == id[i + n]) {
      cout << "IMPOSSIBLE";
      exit(0);
    }
  }
  cout << "POSSIBLE\n";
  for (int i = 1; i <= n; i++) {
    if (id[i] > id[i + n])
      cout << "0 ";
    else
      cout << "1 ";
  }
  return 0;
}