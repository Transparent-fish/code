#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans = LLONG_MIN, a, b, x[N];

signed main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      if (l <= r && abs(l - r) <= abs(a - b)) {
        int sum = 0;
        for (int i = l; i <= r; i++) sum += x[i];
        ans = max(ans, sum);
      }
    }
  }
  cout << ans;
  return 0;
}