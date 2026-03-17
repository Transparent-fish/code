#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, ans, a[N];

bool ck(int r) {
  int sum = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    sum += r * a[i];
    sum += a[i];
    if (sum > m) {
      sum = 0;
      cnt++;
    }
  }
  return cnt <= k;
}

signed main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int l = 0, r = 1e13;
  for (; l <= r;) {
    int mid = (l + r) >> 1;
    if (ck(mid)) {
      // cout << mid << "\n";
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}