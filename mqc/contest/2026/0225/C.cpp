#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, a[N], s[N];

int js(int k, int l, int r) {
  if (k == 1) return s[r] - s[l];
  for (int i = l; i <= r; i++) {
    for (int j = i; j <= r; i++) {
      return js(k--, i, j);
    }
  }
}

signed main() {
#ifdef __linux__
  freopen("sum.in", "r", stdin);
  freopen("sum.out", "w", stdout);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << js(i, k, n) << " ";
  }
  return 0;
}

/*
123224
*/