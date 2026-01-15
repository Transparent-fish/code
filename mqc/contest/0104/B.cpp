//B 砍竹子1 (bamboo) 
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n;

int fpow(int a, int b) {
  if (b == 0) return 1;
  int c = fpow(a, b / 2);
  if (b % 2 == 0) return c * c % mod;
  return c * c % mod * a % mod;
}

signed main() {
  cin >> n;
  if (n <= 3) {
    cout << n;
    exit(0);
  }
  if (n % 3 == 0) {
    cout << fpow(3, (n / 3)) % mod;
  } else if (n % 3 == 2) {
    cout << fpow(3, (n / 3)) * 2 % mod;
  } else if (n % 3 == 1) {
    cout << fpow(3, (n / 3 - 1)) * 4 % mod;
  }
  return 0;
}
// 1 1
// 2 2
// 3 3
// 4 4
// 5 6