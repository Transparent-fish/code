#include <bits/stdc++.h>
using namespace std;
#define int long long
int l, r, now, noow, ans;

signed main() {
  cin >> l >> r;
  now = r - l, noow = now - l + 1;
  for (int i = 1; i <= noow; i++) {
    ans += i;
  }
  // cout << now << " " << noow << " " << ans;
  cout << ans;
  return 0;
}