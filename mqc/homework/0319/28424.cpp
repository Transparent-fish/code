#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e4 + 5;
int n, k, ans, dp[N][505];
vector<int> e[N];

void dfs(int u, int fa) {
  dp[u][0] = 1;
  for (auto c : e[u]) {
    if (c == fa) continue;
    dfs(c, u);
    for (int i = 0; i < k; i++) ans += dp[c][i] * dp[u][k - i - 1];
    for (int i = 1; i <= k; i++) dp[u][i] += dp[c][i - 1];
  }
}

signed main() {
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans;
  return 0;
}