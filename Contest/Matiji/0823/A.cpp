#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int t, a[N], b[N], dp[N][0];
priority_queue<int>q;

signed main() {
    cin >> t;
    for (;t--;) {
        int n, k, s, now = 0, cnt = 0;
        cin >> n >> k >> s;
        now = s;
        for (int i = 1;i <= n;i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 1;i <= n;i++) {
            dp[i][0] = dp[i][1] = 0;
        }
        dp[1][0] = dp[1][1] = s;
        for (int i = 1;i <= n;i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i][0] + b[i]);
            if (cnt < k) {
                dp[i][1] = max(dp[i - 1][0], dp[i][1] + (dp[i - 1][0] * 2 + b[i]));
            }
            if (dp[i][1] > dp[i][0])cnt++;
        }
        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
    return 0;
}