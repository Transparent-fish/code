#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, now;
bool vis[N];

signed main() {
  cin >> n >> k;
  now = 1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (; cnt != k + 1;) {
      now++;
      if (now > n) now %= n;
      if (!vis[now]) cnt++;
    }
    vis[now] = 1;
    if (now == 1)
      cout << n << " ";
    else
      cout << now - 1 << " ";
  }
  return 0;
}