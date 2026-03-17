#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k1, k2, Min, a[N];

int lowbit(int x) { return x & -x; }

signed main() {
  cin >> n >> k1 >> k2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Min = 1e18;
  for (int i = 0; i <= 30; i++) {
    int now = i * k1;
    for (int j = 1; j <= n; j++) {
      int noow = a[j] / (1 << i), cnt = 0;
      for (; noow > k2;) {
        noow -= lowbit(noow);
        cnt++;
      }
      now += cnt;
    }
    Min = min(Min, now);
  }
  cout << Min;
  return 0;
}