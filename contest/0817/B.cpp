#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 305;
int n, m, v[N], w[N], f[N], r[1000005], l[N][N], dp[N][N][N], c[N][N][N];

signed main() {
#ifdef __linux__
    freopen("axis.in", "r", stdin);
    freopen("axis.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 0; k <= 200; k++) {
                dp[i][j][k] = dp[i][j - 1][k];
                if (k >= v[j]) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - v[j]] + w[j]);
                if (dp[i][j][k] == dp[i - 1][j][k] && l[j][k]) c[j][k][l[j][k]] = i;
                else c[j][k][++l[j][k]] = i;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> r[i];
        for (int j = n; j; j--) {
            for (int k = 1; k <= l[j][r[i]]; k++) {
                f[j] = max(f[j], f[c[j][r[i]][k] - 1] + dp[c[j][r[i]][k]][j][r[i]]);
            }
        }
        for (int j = 1; j <= n; j++) f[j] = max(f[j], f[j - 1]);
    }
    cout << f[n];
    return 0;
}