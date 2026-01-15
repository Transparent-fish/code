#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;

bool ck(int a, int b, int c, int d) {
  if ((a + b) + c == d || (a - b) + c == d || (a * b) + c == d ||
          (a / b) + c == d || (a + b) - c == d || (a - b) - c == d ||
          (a * b) - c == d || (a / b) - c == d || /*times*/ (a + b) * c == d ||
          (a - b) * c == d || (a * b) * c == d || (a / b) * c == d ||
          /*/*/ (a + b) / c == d || (a - b) / c == d || (a * b) / c == d ||
          (a / b) / c == d)
    return 1;
  return 0;
}

int main() {
  cin >> a >> b >> c >> d;
  if (ck(a, b, c, d) == 1)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}