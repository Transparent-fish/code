#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];
int lasl, lasr, lasans;

int query(int l, int r) {
  if (l == lasl && r == lasr) {
    return lasans;
  }
  int Max = -1;
  for (int i = l; i <= r; i++) {
    for (int j = l; j <= r; j++) {
      if (i != j && i <= j) Max = max(Max, __gcd(a[i], a[j]));
    }
  }
  lasl = l, lasr = r, lasans = Max;
  return Max;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
#ifdef __linux__
  freopen("gcd.in", "r", stdin);
  freopen("gcd.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (; m--;) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }
  return 0;
}