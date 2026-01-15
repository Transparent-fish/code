#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, k;
int a[N][N], dis[N][N][20];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

int dfs(int x, int y, int cnt) {
  if (dis[x][y][cnt] != -1) {
    return dis[x][y][cnt];
  }
  int ans = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + d[i][0], ny = y + d[i][1];
    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
      if (a[nx][ny] > a[x][y]) {
        ans = max(ans, dfs(nx, ny, cnt) + 1);
      } else {
        if(cnt < k){
        	ans = max(ans, dfs(nx, ny, cnt + 1) + 1);
        }
      }
    }
  }
  dis[x][y][cnt] = ans;
  return ans;
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dis, -1, sizeof(dis));
  int ans = -1e9;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans = max(ans, dfs(i, j, 0));
    }
  }
  cout << ans;
  return 0;
}