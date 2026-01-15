#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, Min = 1e18, cnt, ans, fa[N];

struct node {
  int u, v, w;
  friend bool operator<(node a, node b) { return a.w < b.w; }
} e[N];

int Get(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Get(fa[x]);
}

void init() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}

signed main() {
  freopen("speed.in", "r", stdin);
  freopen("speed.out", "w", stdout);
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> e[i].u >> e[i].v >> e[i].w;
    Min = min(Min, abs(e[i].w - k));
  }
  init();
  sort(e + 1, e + m + 1);
  for (int i = 1; i <= m; i++) {
    if (Get(e[i].u) != Get(e[i].v)) {
      fa[Get(e[i].u)] = Get(e[i].v);
      if (e[i].w > k) ans += e[i].w - k;
      cnt++;
      if (cnt == n - 1) {
        if (e[i].w >= k) {
          cout << ans;
        } else {
          cout << Min;
        }
        exit(0);
      }
    }
  }
  return 0;
}