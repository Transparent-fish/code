#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, y, z, asd;

signed main() {
  cin >> x >> y >> z;
  if (x <= y) {
    if (z <= x) {
      asd = 1;
    } else {
      asd = (1 + (z + x - 1) / x);
    }
  } else {
    if (z <= x) {
      asd = 1;
    } else {
      asd = (z - x + (x - y) - 1) / (x - y) + 1;
    }
  }
  cout << min((1 + (z + x - 1) / x), asd);
  return 0;
}