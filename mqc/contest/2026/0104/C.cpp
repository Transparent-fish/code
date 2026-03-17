#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, hp, a[N], b[N];

bool check(int x) {
  int sum = 0;
  for (int i = 1; i <= min(n, x); i++) {
    sum += max(a[i], b[i] * (x - i));
  }
  return sum >= hp;
}

signed main() {
  cin >> n >> hp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  int l = 1, r = 1e9 + 7, ans = 0;
  for (; l <= r;) {
    int mid = l + r >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
  return 0;
}