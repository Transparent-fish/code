#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, Maxx, ans, Max[N], l[N], r[N];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    Max[r[i]] = max(Max[r[i]], l[i]);
  }
  for (int i = 1; i <= m; i++) {
    Maxx = max(Maxx, Max[i]);
    ans += i - Maxx;
  }
  cout << ans;
  return 0;
}