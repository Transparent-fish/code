#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, cnt;

signed main() {
  cin >> a >> b;
  if (a == b) {
    cout << 1;
  } else if (((a + b) & 1) == 0) {
    cout << 3;
  } else {
    cout << 2;
  }
  return 0;
}