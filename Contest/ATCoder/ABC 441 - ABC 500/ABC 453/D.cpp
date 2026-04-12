#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m;
int sx, sy, ex, ey;
int d[4][2] = { -1,0,1,0,0,-1,0,1 };
bool vis[N][N][5];
char a[N][N];
char dd[4] = { 'U','D','L','R' };

struct node {
    int x, y, f;
};

struct Node {
    int x, y, f;
    char op;
}b[N][N][4];


void bfs(int sx, int sy, int ex, int ey) {
    queue<node>q;
    for (int i = 0;i < 4;i++) {
        int nx = sx + d[i][0], ny = sy + d[i][1];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#') {
            vis[nx][ny][i] = 1;
            b[nx][ny][i] = { sx, sy, -1, dd[i] };
            q.push({ nx,ny,i });
        }
    }
    for (;!q.empty();) {
        auto now = q.front();
        q.pop();
        if (now.x == ex && now.y == ey) {
            cout << "Yes\n";
            string ans = "";
            int nx = now.x, ny = now.y, nf = now.f;
            for (;nf != -1;) {
                Node noow = b[nx][ny][nf];
                ans += noow.op;
                nx = noow.x, ny = noow.y, nf = noow.f;
            }
            reverse (ans.begin(), ans.end());
            cout << ans << "\n";
            return;
        }

        char op = a[now.x][now.y];
        for (int i = 0;i < 4;i++) {
            if (op == 'o' && i != now.f)continue;
            else if (op == 'x' && i == now.f)continue;
            int nx = now.x + d[i][0], ny = now.y + d[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && !vis[nx][ny][i]) {
                vis[nx][ny][i] = 1;
                b[nx][ny][i] = { now.x, now.y, now.f, dd[i] };
                q.push({ nx, ny, i });
            }
        }
    }
    cout << "No\n";
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S')sx = i, sy = j;
            if (a[i][j] == 'G')ex = i, ey = j;
        }
    }
    bfs(sx, sy, ex, ey);
    return 0;
}