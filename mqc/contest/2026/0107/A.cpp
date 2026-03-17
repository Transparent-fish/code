#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int now;
    cin >> now;
    ans ^= now;
  }
  cout << ans;
  return 0;
}