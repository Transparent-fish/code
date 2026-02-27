#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], tree[N], id[N], ans[N];
vector<int> e[N];

int lowbit(int x) { return x & -x; }

void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tree[i] += c;
  }
}

int query(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    res += tree[i];
  }
  return res;
}
void dfs(int x, int fa) {
  ans[x] -= query(n) - query(id[a[x]]);
  for (auto i : e[x]) {
    if (i == fa) continue;
    dfs(i, x), update(a[i], 1);
  }
  ans[x] - query(n) - query(id[a[x]]);
}

signed main() {
  cin >> n;
  return 0;
}