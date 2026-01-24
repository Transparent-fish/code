#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int n, m;
int d[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
bool pan;
vector<vector<bool>>vis;

signed main() {
    cin >> n >> m;
    vis.resize(n + 1, vector<bool>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                vis[i][j] = 1;
            }
        }
    }
    pan = 1;
    for (;pan;) {
        pan = 0;int cnt = 0;
        vector<vector<bool>>asd = vis;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (vis[i][j]) continue;
                cnt = 0;
                for (int k = 0;k < 4;k++) {
                    int nx = i + d[k][0], ny = j + d[k][1];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && vis[nx][ny]) {
                        cnt++;
                    }
                }
                if (cnt == 1) {
                    asd[i][j] = 1;
                    pan = 1;
                }
            }
        }
        vis = asd;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (vis[i][j])ans++;
        }
    }
    cout << ans;
    return 0;
}