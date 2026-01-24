#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m, _;
int d[4][2] = { 1,0,-1,0,0,1,0,-1 };
char a[N][N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (a[i][j] == '#') {
                _ = 0;
                for (int k = 0, nx, ny;k < 4;k++) {
                    nx = i + d[k][0], ny = j + d[k][1];
                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '#') {
                        _++;
                    }
                }
                if (_ != 2 && _ != 4) {
                    cout << "No";
                    exit(0);
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}