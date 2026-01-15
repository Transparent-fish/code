#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG
const int mod = 1e9 + 7;
int l, r, k, ans;

void Scanf() {
  cin >> l >> r >> k;
  ans = (r - l + 1) * k % mod +
        ((r - l) * ((r - l) + 1) / 2 % mod) % mod * l % mod;
}

void Printf() {
  for (int i = 1; i <= r - l - 1; i++) {
    ans += i * (i + 1) / 2;
    ans %= mod;
#if DEBUG
    cout << i << " " << ans << " ";
#endif
  }
  // cout << "\n";
  cout << ans;
}

signed main() {
  Scanf(), Printf();
  // int now = k;
  // ans = k;
  // for (int i = l - 1; i <= r; i++) {
  //   cnt += i - 1;
  //   ans += cnt;
  // }
  // cout << ans % mod;
  return 0;
}