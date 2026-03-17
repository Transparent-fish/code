#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int a, ans, b, vis[N];

bool pan(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}

int bfs() {
  queue<pair<int, int>> q;
  memset(vis, 0, sizeof(vis));
  q.push({a, 0});
  for (; !q.empty();) {
    int fi = q.front().first, sec = q.front().second, now, cnt = 0;
    q.pop();
    if (fi == b) {
      return sec;
    }
    now = fi, cnt = 0;
    for (; now > 0;) {
      for (int i = 0; i <= 9; i++) {
        int noow = fi - ((now % 10) * pow(10, cnt)) + (i * pow(10, cnt));
        if (pan(noow) && vis[noow] == 0) {
          q.push({noow, sec + 1}), vis[noow] = 1;
        }
      }
      now /= 10, cnt++;
    }
  }
  return -1;
}

signed main() {
  int T;
  cin >> T;
  for (; T--;) {
    cin >> a >> b;
    ans = bfs();
    if (ans == -1) {
      cout << "Impossible\n";
    } else {
      cout << ans << "\n";
    }
  }
  return 0;
}