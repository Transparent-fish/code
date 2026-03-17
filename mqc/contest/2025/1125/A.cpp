#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], g[N];

void init() {
  for (int i = 1; i <= n; i++) {
    a[i] = i;
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> g[i];
  }
  init();
  return 0;
}