#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, n;

signed main() {
  cin >> x >> n;
  if (x > n)
    cout << "-1";
  else
    cout << n - x;
  return 0;
}