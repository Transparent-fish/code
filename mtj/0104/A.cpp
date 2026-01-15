#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define int128 __int128_t
const int N = 1e6 + 5;
int n, m, cnt, a[N];
int128 s[N];

signed main() {
  cin >> n >> m;
  s[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = int128(s[i - 1] * int128(a[i]));
  }
  for (int i = 0; i <= n; i++) {
    int128 now = s[i], noow = s[n] / s[i];
    if (max(now, noow) - min(now, noow) <= m) cnt++;
  }
  cout << cnt;
  return 0;
}