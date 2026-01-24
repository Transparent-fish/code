#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m;
int d[4][2] = { 0,1,0,-1,1,0,-1,0 };
char a[N][N];
bool vis[N][N], vvis[N];
vector<pair<int, int>>mp[N];

struct node {
    int x, y, dis;
};

void init(int i, int j) {
    if (a[i][j] >= 'a' && a[i][j] <= 'z') {
        mp[a[i][j] - 'a'].push_back({ i, j });
    }
}

void bfs() {
    queue<node>q;
    vis[1][1] = 1;
    q.push({ 1,1,0 });
    for (;!q.empty();) {
        node now = q.front();
        if (now.x == n && now.y == m) {
            cout << now.dis;
            exit(0);
        }
        q.pop();
        for (int i = 0;i < 4;i++) {
            int nx = now.x + d[i][0], ny = now.y + d[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && vis[nx][ny] == 0) {
                vis[nx][ny] = 1;
                q.push({ nx,ny,now.dis + 1 });
            }
        }
        if (a[now.x][now.y] >= 'a' && a[now.x][now.y] <= 'z') {
            if (vvis[a[now.x][now.y] - 'a'] == 0) {
                vvis[a[now.x][now.y] - 'a'] = 1;
                for (auto i : mp[a[now.x][now.y] - 'a']) {
                    if (vis[i.first][i.second] == 0) {
                        vis[i.first][i.second] = 1;
                        q.push({ i.first,i.second,now.dis + 1 });
                    }
                }
            }
        }
    }
    cout << -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            init(i, j);
        }
    }
    bfs();
    return 0;
}