#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5005;
int n, m, ans, dp[N];

struct node {
  int t, x, y;
} a[N];

signed main() {
#ifdef __linux__
  freopen("num.in", "r", stdin);
  freopen("num.out", "w", stdout);
#endif

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].t >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == j) continue;
      int now = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
      if (abs(a[i].t - a[j].t) >= now) dp[i] = max(dp[i], dp[j] + 1);
      ans = max(ans, dp[i]);
    }
  }
  cout << ans;
  return 0;
}