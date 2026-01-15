#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, cntt, ans, a[N], b[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (i >= 3) {
      if (a[i] == a[i - 1] && a[i - 1] == a[i - 2] + 1) {
        cnt = cntt + 1;
      }
      if (a[i - 1] == a[i - 2] && a[i] == a[i - 1] + 1) {
        cntt = cnt + 1;
      } else {
        cntt = 0;
      }
      if (!(a[i] == a[i - 1] && a[i - 1] == a[i - 2] + 1)) cnt = 0;
      ans = ans + cnt + cntt;
    }
  }
  cout << ans;
  return 0;
}