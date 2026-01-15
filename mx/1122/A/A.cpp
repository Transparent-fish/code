#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DYL
const int N = 1e6 + 5;
int T, n, a[N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef DYL
  freopen("mod4.in", "r", stdin);
  freopen("a.ans", "w", stdout);
#endif
  cin >> T;
  for (; T--;) {
    cin >> n;
    int Max = -1e18, Min = 1e18;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      Max = max(Max, a[i]), Min = min(Min, a[i]);
    }
    sort(a + 1, a + n + 1);
    cout << max(a[n] - a[1], a[n - 1]) << "\n";
  }
  return 0;
}