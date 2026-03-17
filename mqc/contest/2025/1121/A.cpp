#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, ans, Max = -1e18, cnt, fa[N];

struct node {
  int u, v, w;
  friend bool operator<(node a, node b) { return a.w < b.w; }
} a[N];

int find(int x) {
  if (fa[x] == x) return x;
  return fa[x] = find(fa[x]);
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
    cin >> a[i].u >> a[i].v >> a[i].w;
  }
  sort(a + 1, a + m + 1);
  init();
  for (int i = 1; i <= m; i++) {
    if (find(a[i].u) != find(a[i].v)) {
      if (a[i].w > k) {
        ans += a[i].w - k;
        Max = max(Max, a[i].w);
      }
      cnt++;
      int fx = find(a[i].u), fy = find(a[i].v);
      if (fx != fy) {
        fa[fx] = fy;
      }
    }
  }
  if (cnt == n - 1)
    if (Max < k)
      cout << k - Max;
    else
      cout << ans;
  else
    cout << "-1";
  return 0;
}