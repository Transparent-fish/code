#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, Min = 1e18, sum, a[N];

signed main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    Min = min(Min, a[i]);
  }
  for (int i = 1; i <= n; i++) {
    sum = __gcd(a[i] - Min, sum);
  }
  for (int i = 1; i <= q; i++) {
    cout << __gcd(Min + i, sum) << "\n";
  }
  return 0;
}