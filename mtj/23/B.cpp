#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Max, sum[N], a[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sum[i] > (sum[n] >> 1))
      Max = max(Max, sum[n] - sum[i]);
    else
      Max = max(Max, sum[i]);
  }
  cout << Max;
  return 0;
}