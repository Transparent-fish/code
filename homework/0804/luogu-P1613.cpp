#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, m, dis[N][N], vis[N][N][65];
vector<int>e[N];

void floyd() {
    for (int i = 1;i <= n;i++)dis[i][i] = 0;
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    memset(dis, 10, sizeof dis);
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        dis[u][v] = 1, vis[u][v][0] = 1;
    }
    for (int k = 1;k <= 64;k++) {
        for (int i = 1;i <= n;i++) {
            for (int l = 1;l <= n;l++) {
                for (int j = 1;j <= n;j++) {
                    if (vis[i][l][k - 1] && vis[l][j][k - 1]) {
                        vis[i][j][k] = 1, dis[i][j] = 1;
                    }
                }
            }
        }
    }
    floyd();
    cout << dis[1][n];
    return 0;
}