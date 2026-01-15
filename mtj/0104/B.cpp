#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, ans, Min = 1e9, a[N], b[N];
string s;

signed main() {
  cin >> n >> s;
  s = " " + s;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      a[i] = a[i - 1] + 1;
      b[i] = b[i - 1];
    } else {
      a[i] = a[i - 1];
      b[i] = b[i - 1] + 1;
    }
  }
  for (int k = 1; k <= n; k++) {
    int now = 0, cnt = 0, i = 1;
    for (i = 1; i + k <= n; i += k) {
      if (now == 0) {
        cnt += a[i + k - 1] - a[i - 1];
        now = 1;
      } else if (now == 1) {
        cnt += b[i + k - 1] - b[i - 1];
        now = 0;
      }
    }
    if (now == 0) {
      cnt += a[n] - a[i - 1];
      now = 1;
    } else if (now == 1) {
      cnt += b[n] - b[i - 1];
      now = 0;
    }
    if (cnt < Min) {
      Min = cnt;
      ans = k;
    }
  }
  cout << ans;
  return 0;
}