#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int T;

signed main() {
  cin >> T;
  for (; T--;) {
    int l, r;
    cin >> l >> r;
    __int128_t ans = __int128_t(__int128_t(l + r) * __int128_t(r - l + 1)/ 2 ) % 9;
    cout << (int)ans << "\n";
  }
  return 0;
}