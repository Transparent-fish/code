#include <bits/stdc++.h>
using namespace std;
#define int long long
int x;

signed main() {
  cin >> x;
  if (x % 2023 < 0)
    cout << x % 2023 + 2023;
  else
    cout << x % 2023;
  return 0;
}