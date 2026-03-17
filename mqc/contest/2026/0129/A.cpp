#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int x, y, z, n;
int a[100005], dp[1000005], dis[N][N][N];

struct node {
  int a, b, c;
};

void bfs() {
  queue<node> q;
  q.push({0, 0, 0});
  memset(dis, -1, sizeof(dis));
  dis[0][0][0] = 0;
  for (int i = 1; i <= 400; i++) a[i] = 1e9;
  for (; !q.empty();) {
    auto now = q.front();
    q.pop();
    int asd = dis[now.a][now.b][now.c];
    if (now.a != 0) a[now.a] = min(a[now.a], asd + 1);
    if (now.b != 0) a[now.b] = min(a[now.b], asd + 1);
    if (now.c != 0) a[now.c] = min(a[now.c], asd + 1);
    if (now.a + now.b > 0 && now.a + now.b <= 300)
      a[now.a + now.b] = min(a[now.a + now.b], asd + 2);
    if (now.a + now.c > 0 && now.a + now.c <= 300)
      a[now.a + now.c] = min(a[now.a + now.c], asd + 2);
    if (now.b + now.c > 0 && now.b + now.c <= 300)
      a[now.b + now.c] = min(a[now.b + now.c], asd + 2);
    if (now.a + now.b + now.c > 0 && now.a + now.b + now.c <= 300)
      a[now.a + now.b + now.c] = min(a[now.a + now.b + now.c], asd + 3);
    int na[6], nb[6], nc[6];
    int tot;
    // a to b
    tot = min(now.a, y - now.b);
    na[0] = now.a - tot, nb[0] = now.b + tot, nc[0] = now.c;
    // a to c
    tot = min(now.a, z - now.c);
    na[1] = now.a - tot, nb[1] = now.b, nc[1] = now.c + tot;
    // b to a
    tot = min(now.b, x - now.a);
    na[2] = now.a + tot, nb[2] = now.b - tot, nc[2] = now.c;
    // b to c
    tot = min(now.b, z - now.c);
    na[3] = now.a, nb[3] = now.b - tot, nc[3] = now.c + tot;
    // c to a
    tot = min(now.c, x - now.a);
    na[4] = now.a + tot, nb[4] = now.b, nc[4] = now.c - tot;
    // c to b
    tot = min(now.c, y - now.b);
    na[5] = now.a, nb[5] = now.b + tot, nc[5] = now.c - tot;
    int ba[6] = {x, 0, now.a, now.a, now.a, now.a};
    int bb[6] = {now.b, now.b, y, 0, now.b, now.b};
    int bc[6] = {now.c, now.c, now.c, now.c, z, 0};
    for (int i = 0; i <= 5; i++) {
      if (dis[na[i]][nb[i]][nc[i]] == -1) {
        dis[na[i]][nb[i]][nc[i]] = asd + 1;
        q.push({na[i], nb[i], nc[i]});
      }
      if (dis[ba[i]][bb[i]][bc[i]] == -1) {
        dis[ba[i]][bb[i]][bc[i]] = asd + 1;
        q.push({ba[i], bb[i], bc[i]});
      }
    }
  }
}

signed main() {
#ifdef __linux__
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("water.in", "r", stdin);
  freopen("water.out", "w", stdout);
#endif
  cin >> x >> y >> z >> n;
  bfs();
  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << " ";
  // }
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int k = 1; k <= 300 && k <= i; k++) {
      if (a[k] != 1e9 && dp[i - k] != 1e9) {
        dp[i] = min(dp[i], dp[i - k] + a[k]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  return 0;
}