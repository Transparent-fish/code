#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, k, w, a[N];
bool vis[N * 2];

struct node {
  int v, w;
};
vector<node> e[N * 2];

struct noode {
  int dis, x;
  friend nool operator<(noode a, noode b) { return a.dis > b.dis; }
};

void dij() {
  priority_queue<noode> q;
  memset(vis, 0, sizeof(vis));
  q.push({0, 1});
  for (;!q.empty();) {
    noode now = q.top();
    q.pop();
    if (vis[now.x]) continue;
    vis[now.x] = 1;
    if (now.x == n || now.x == n + n) {
      cout << now.dis;
      exit(0);
    }
    for (auto edge : e[now.x]) {
      q.push({now.dis + edge.w, edge.v});
    }
  }
}

signed main() {
  cin >> n >> m >> k >> w;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
    vis[a[i]] = 1;
    e[a[i]].push_back({a[i] + n, w});
  }
  for (int i = 1; i <= m; i++) {
    int u, v, z;
    cin >> u >> v >> z;
    e[u].push_back({v, z});
    e[v].push_back({u, z});
    if (vis[u] && vis[v]) {
      e[u + n].push_back({v + n, (z + 1) / 2});
      e[v + n].push_back({u + n, (z + 1) / 2});
    } else {
      e[u + n].push_back({v + n, z});
      e[v + n].push_back({u + n, z});
    }
  }
  dij();
  return 0;
}