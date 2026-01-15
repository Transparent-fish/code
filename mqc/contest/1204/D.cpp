#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      if (l <= r) {
        int sum = 0;
        for (int i = l; i <= r; i++) {
          sum += a[i];
        }
        if(sum % n == 0)ans++;
      }
    }
  }
  cout << ans;
  return 0;
}