#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], ans[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1])
      ans[i] = i - 1;
    else {
      int now = ans[i - 1];
      for (; now != 0;) {
        if (a[now] < a[i]) {
          ans[i] = now;
          break;
        }
        now = ans[now];
      }
    }
    cout << ans[i] << " ";
  }
  return 0;
}