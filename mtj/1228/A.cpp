#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 1e6 + 5;
int n;
d a[N], b[N], sum, sum1;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sum += b[i] * a[i], sum1 += b[i];
  }
  printf("%.3lf", sum / sum1);
  return 0;
}