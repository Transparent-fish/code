#include <bits/stdc++.h>
using namespace std;
#define int long long
int t1, t2, p1, p2;

signed main() {
  cin >> t1 >> p1 >> t2 >> p2;
  if (p2 > p1) {
    cout << t2 + ((100 - p2) * (t2 - t1) / (p2 - p1));
  } else {
    cout << t2 + (p2 * (t2 - t1) / (p1 - p2));
  }
  return 0;
}