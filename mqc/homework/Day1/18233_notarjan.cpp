#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, m;
int sx, sy, ex, ey, boxx, boxy;
char a[N][N];
bool vis[N][N][4], book[N][N];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct node {
  int x, y, dir, cnt;
};

bool bfs(int sx, int sy, int ex, int ey, int boxx, int boxy) {
  queue<pair<int, int>> q;
  q.push({sx, sy});
  memset(book, 0, sizeof(book));
  book[sx][sy] = book[boxx][boxy] = 1;
  for (; !q.empty();) {
    auto now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.first + d[i][0], ny = now.second + d[i][1];
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !book[nx][ny] &&
          a[nx][ny] != 'S') {
        if (nx == ex && ny == ey) return 1;
        book[nx][ny] = 1;
        q.push({nx, ny});
      }
    }
  }
  return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'M') sx = i, sy = j;
      if (a[i][j] == 'P') boxx = i, boxy = j;
      if (a[i][j] == 'K') ex = i, ey = j;
    }
  }
  queue<node> q;
  for (int i = 0; i < 4; i++) {
    int nx = boxx + d[i][0];
    int ny = boxy + d[i][1];
    if (bfs(sx, sy, nx, ny, boxx, boxy)) {
      q.push({boxx, boxy, i, 0});
      vis[boxx][boxy][i] = 1;
    }
  }
  for (; !q.empty();) {
    auto now = q.front();
    q.pop();
    if (now.x == ex && now.y == ey) {
      cout << now.cnt;
      exit(0);
    }
    int nx = now.x - d[now.dir][0], ny = now.y - d[now.dir][1];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny][now.dir] &&
        a[nx][ny] != 'S') {
      vis[nx][ny][now.dir] = 1;
      q.push({nx, ny, now.dir, now.cnt + 1});
    }
    for (int i = 0; i < 4; i++) {
      if (i == now.dir) continue;
      int tx = now.x + d[i][0], ty = now.y + d[i][1];
      if (!vis[now.x][now.y][i] &&
          bfs(now.x + d[now.dir][0], now.y + d[now.dir][1], tx, ty, now.x,
              now.y)) {
        vis[now.x][now.y][i] = 1;
        q.push({now.x, now.y, i, now.cnt});
      }
    }
  }
  cout << "NO";
  return 0;
}