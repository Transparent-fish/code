#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m;
int sx, sy, ex, ey;
int tim[N][N];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char a[N][N];
bool vis[N][N];

struct node {
  int x, y, v;
  friend bool operator<(node a, node b) { return a.v > b.v; }
};

void bfs() {
  priority_queue<node> q;
  q.push({sx, sy, 0});
  vis[sx][sy] = 1;
  for (; !q.empty();) {
    node now = q.top();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = now.x + d[i][0], ny = now.y + d[i][1], nv = now.v;
      if (nx == ex && ny == ey) {
        cout << nv + 1;
        exit(0);
      }
      if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0) {
        vis[nx][ny] = 1;
        tim[nx][ny]--;
        if (a[nx][ny] == 'O') {
          q.push({nx, ny, nv + 1});
        } else if (a[nx][ny] == 'S') {
          if (tim[nx][ny] <= 0) {
            q.push({nx, ny, nv + 2});
            tim[nx][ny] = 5;
          }
        } else if (a[nx][ny] == 'D') {
          if (tim[nx][ny] <= 0) {
            q.push({nx, ny, nv + 3});
            tim[nx][ny] = 10;
          }
        }
      }
    }
  }
  cout << "-1";
}

signed main() {
  freopen("maze.in", "r", stdin);
  freopen("maze.out", "w", stdout);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A') {
        sx = i, sy = j;
      } else if (a[i][j] == 'B') {
        ex = i, ey = j;
      }
    }
  }
  bfs();
  return 0;
}