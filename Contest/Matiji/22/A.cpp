#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25;
int n, m, k;
bool vis[N][N];

signed main() {
    cin >> n >> m >> k;
    for (;k--;) {
        int x = 1, yy, y, d;
        cin >> y >> d;
        yy = y;
        if (d == -1) {
            for (;x <= n && yy >= 1;) {
                vis[x][yy] = 1;
                x++, yy--;
            }
        }
        else {
            for (;x <= n && yy <= m;) {
                vis[x][yy] = 1;
                x++, yy++;
            }
        }
    }
    int cnt = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (vis[i][j] == 1) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}