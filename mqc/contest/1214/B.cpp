#include <bits/stdc++.h>
using namespace std;
int a, b, c, cnt;

int op(int x, int y, string s) {
  if (s == "nand") {
    return (!(x & y));
  } else if (s == "nor") {
    return (!(x | y));
  } else {
    return ((x & !y) | (!x & y));
  }
}

int main() {
  cin >> a >> b >> c;
  for (int x = 0; x <= 1; x++) {
    for (int y = 0; y <= 1; y++) {
      int A, B, C;
      A = op(x, y, "nand"), B = op(x, y, "nor"), C = op(x, y, "zzz");
      if (A == a && B == b && C == c) {
        cnt++;
      } else if (A == a && B != b && C == c) {
        cnt++;
      } else if (A == a && B == b && C != c) {
        cnt++;
      } else if (A != a && B == b && C == c) {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}