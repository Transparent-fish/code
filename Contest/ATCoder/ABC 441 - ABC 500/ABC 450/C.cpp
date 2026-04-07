#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m, cnt;
int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
char a[N][N];
bool vis[N][N];

void bfs() {
    queue<pair<int, int>>q;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if ((i == 1 || i == n || j == 1 || j == m) && a[i][j] == '.') {
                q.push({ i,j });
                vis[i][j] = 1;
            }
        }
    }
    for (;!q.empty();) {
        auto now = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = now.first + d[i][0], ny = now.second + d[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0 && a[nx][ny] == '.') {
                vis[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
}

void bffs(int x, int y) {
    queue<pair<int, int>>q;
    q.push({ x,y });
    vis[x][y] = 1;
    for (;!q.empty();) {
        auto now = q.front();
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = now.first + d[i][0], ny = now.second + d[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny] == 0 && a[nx][ny] == '.') {
                vis[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    bfs();
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (a[i][j] == '.' && vis[i][j] == 0) {
                cnt++;
                bffs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}