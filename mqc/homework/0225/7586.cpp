#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N], p[N], id[N], ans[N], tree[N];
vector<int> e[N];

int lowbit(int x) { return x & -x; }

void update(int x, int k) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tree[i] += k;
  }
}

int query(int x) {
  int sum = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    sum += tree[i];
  }
  return sum;
}

void dfs(int u, int f) {
  ans[u] -= query(n) - query(id[u]);
  for (auto v : e[u]) {
    if (v == f) continue;
    dfs(v, u);
    update(id[v], 1);
  }
  ans[u] += query(n) - query(id[u]);
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    a[i] = p[i];
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    id[i] = lower_bound(p + 1, p + n + 1, a[i]) - p;
  }
  dfs(1, 0);
  for (int i = 2, x; i <= n; i++) {
    cin >> x;
    e[x].push_back(i);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}