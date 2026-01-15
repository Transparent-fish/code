#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, a[N], ans[N];

void dfs(int x, int sum) {
  if (x == n + 1) {
    if (sum % k == 0) {
      for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
      }
      cout << "\n";
    }
  }
  for (int i = 1; i <= a[x]; i++) {
    ans[x] = i;
    dfs(x + 1, sum + i);
  }
}

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1, 0);
  return 0;
}