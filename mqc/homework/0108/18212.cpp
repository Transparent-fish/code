#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 1e6 + 5;
int n, m;
d f[N];

signed main() {
  cin >> n >> m;
  for (int i = m - 1; i >= 0; i--) {
    f[i] = f[i + 1] + (d)n / (d)(n - i);
  }
  printf("%.6lf", f[0]);
  return 0;
}