#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, M = 20005;
int n, m, s, a[N][N], f[M];

struct node {
  int x, y;
  friend bool operator<(node a, node b) { return a.x < a.y; }
};
vector<node> e[N];

signed main() {
  cin >> s >> n >> m;
  for (int i = 1; i <= s; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= n; j++) {
    vector<int> now;
    now.push_back(0);
    for (int i = 1; i <= s; i++) {
      now.push_back(a[i][j]);
    }
    sort(now.begin(), now.end());
    for (int i = 1; i < now.size(); i++) {
      e[j].push_back({now[i] * 2 + 1, i * j});
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 0; j--) {
      for (int k = 0; k < e[i].size(); k++) {
        if (j - e[i][k].x >= 0) {
          f[j] = max(f[j], f[j - e[i][k].x] + e[i][k].y);
        }
      }
    }
  }
  cout << f[m];
  return 0;
}