#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, n, mod = 1e9 + 7;

signed main() {
  cin >> T;
  for (; T--;) {
    cin >> n;
    int a = (n * (n + 1) / 2) % mod;
    cout << (a * a) % mod << " " << (a * 2) % mod - 1 << " " << a % mod << "\n";
  }
  return 0;
}