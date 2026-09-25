#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int n, a[N][N];
int d[4][2] = { 0,1,0,-1,1,0,-1,0 };
bool vis[N][N];

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0;i < 4;i++) {
        int nx = x + d[i][0], ny = y + d[i][1];
        if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= n + 1 && !vis[nx][ny] && a[nx][ny] != 1) {
            dfs(nx, ny);
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (vis[i][j] != 1 && a[i][j] == 0)cout << "2 ";
            else cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}