#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3005;
int T, n, m;
bool dp[N][N], vis[N][N], now[N];
char a[N][N];

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n >> m;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                cin >> a[i][j];
                dp[i][j] = vis[i][j] = 0;
                now[i] = 1;
            }
        }
        dp[n][m] = vis[n][m] = 1;
        for (int i = n;i >= 2;i--) {
            for (int j = 1;j <= n;j++) {
                if (a[i][j] == '#')now[j] = 0;
                // cout << now[j] << " ";
                bool pan = 0;
                if ((j > 1 && dp[i][j - 1] == 1) || (j < n && dp[i][j + 1] == 1))pan = 1;
                if (a[i - 1][j] == '.') {
                    if (pan == 1 || dp[i][j] == 1)dp[i - 1][j] = 1;
                    if (vis[i][j] == 1 || (pan && now[j] == 1))vis[i - 1][j] = 1;
                    // cout << dp[i - 1][j] << " ";
                }
                else {
                    if ((vis[i][j] == 1) || (pan == 1 && now[j] == 1)) dp[i - 1][j] = vis[i - 1][j] = 1;
                    // cout << dp[i - 1][j] << " ";
                }
            }
        }
        // for (int i = 1;i <= n;i++) {
        //     for (int j = 1;j <= n;j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        for (int i = 1;i <= n;i++) {
            cout << dp[1][i];
        }
        cout << "\n";
    }
    return 0;
}