#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, a[N];

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      f[i][i][0] = f[i][i][1] = 0;
      break;
    }
  }
  return 0;
}