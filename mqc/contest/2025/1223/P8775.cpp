#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, x, a[N], vis[N];

bool ck(int _) {
  for (int i = 1; i <= _; i++) {
    vis[i] = 1e9;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    vis[i % _] = min(vis[i % _], a[i]);
  }
  for (int i = 0; i < _; i++) {
    ans += vis[i];
  }
  return ans >= (x << 1);
}

void Scanf() {
  cin >> n >> x;
  n--;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}

void Printf() {
	int l = 1, r = n, ans = -1;
  for (; l <= r;) {
    int mid = l + r >> 1;
    if (ck(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
}

signed main() {
  Scanf(), Printf();
  return 0;
}