#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, ans, a[N];

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int l = 1; l <= n; l++) {
    for (int r = 1; r <= n; r++) {
      if (l <= r) {
        unordered_set<int>s;
        for (int i = l; i <= r; i++) {
          s.insert(a[i]);
        }
        if (s.size() <= k) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}