#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int t, Max, w, dp[N][N], q[N << 2];

struct node {
    int ap, bp, as, bs;
}a[N];

signed main() {
    cin >> t >> Max >> w;
    for (int i = 1;i <= t;i++) {
        cin >> a[i].ap >> a[i].bp >> a[i].as >> a[i].bs;
    }
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            dp[i][j] = -1e18;
        }
    }
    dp[0][0] = 0;
    for (int i = 1;i <= t;i++) {
        for (int j = 0;j <= Max;j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j <= a[i].as)dp[i][j] = max(dp[i][j], -j * a[i].ap);
        }
        if (i <= w || i - w - 1 < 0)continue;
        int l = 1, r = 0;
        for (int j = 0;j <= Max;j++) {
            for (;l <= r && q[l] < j - a[i].as;)l++;
            for (;l <= r && dp[i - w - 1][q[r]] + q[r] * a[i].ap <= dp[i - w - 1][j] + j * a[i].ap;)r--;
            q[++r] = j;
            if (l <= r)dp[i][j] = max(dp[i][j], dp[i - w - 1][q[l]] + q[l] * a[i].ap - j * a[i].ap);
        }
        l = 1, r = 0;
        for (int j = Max;j >= 0; j--) {
            for (;l <= r && q[l] > j + a[i].bs;)l++;
            for (;l <= r && dp[i - w - 1][q[r]] + q[r] * a[i].bp <= dp[i - w - 1][j] + j * a[i].bp;)r--;
            q[++r] = j;
            if (l <= r)dp[i][j] = max(dp[i][j], dp[i - w - 1][q[l]] + q[l] * a[i].bp - j * a[i].bp);
        }
    }
    int ans = 0;
    for (int i = 0;i <= Max;i++) {
        ans = max(ans, dp[t][i]);
    }
    cout << ans;
    return 0;
}