#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 100003;
int n, m;

int fpow(int a, int b, int q) {
  if (b == 0) {
    return 1;
  } else {
    int c = fpow(a, floor(b / 2), q);
    if (b % 2 != 0) {
      return c * c % q * a % q;
    } else if (b % 2 == 0) {
      return c * c % q;
    }
  }
}

signed main() {
#ifdef __linux__
  freopen("prison.in", "r", stdin);
  freopen("prison.out", "w", stdout);
#endif
  cin >> m >> n;
  cout << ((fpow(m, n, mod) + mod) - (m * fpow(m - 1, n - 1, mod) + mod) % mod) % mod;
  return 0;
}