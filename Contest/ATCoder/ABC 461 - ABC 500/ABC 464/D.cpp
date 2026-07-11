#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int T, n, dp[N][2], a[N], b[N];
string s;

signed main() {
    cin >> T;
    for (; T--;) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> b[i];
        }
        if (s[0] == 'S') dp[1][1] = 0, dp[1][0] = -a[1];
        else dp[1][0] = 0, dp[1][1] = -a[1];
        for (int i = 2; i <= n; i++) {
            int now = (s[i - 1] == 'S' ? -a[i] : 0), noow = (s[i - 1] == 'R' ? -a[i] : 0);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + now;
            dp[i][1] = max(dp[i - 1][0] + b[i - 1], dp[i - 1][1]) + noow;
        }
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}