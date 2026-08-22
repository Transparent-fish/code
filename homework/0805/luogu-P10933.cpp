#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, s, t[N], c[N], dp[N], q[N];

signed main() {
    cin >> n >> s;
    for (int i = 1;i <= n;i++) {
        cin >> t[i] >> c[i];
        t[i] += t[i - 1], c[i] += c[i - 1];
    }
    memset(dp, 0x3f, sizeof dp);
    int l = 1, r = 1;
    dp[0] = q[1] = 0;
    for (int i = 1;i <= n;i++) {
        for (;l < r && dp[q[l + 1]] - dp[q[l]] <= (s + t[i]) * (c[q[l + 1]] - c[q[l]]);)l++;
        int k = q[l];
        dp[i] = dp[k] + s * (c[n] - c[k]) + t[i] * (c[i] - c[k]);
        for (;l < r && (dp[q[r]] - dp[q[r - 1]]) * (c[i] - c[q[r]]) >= (dp[i] - dp[q[r]]) * (c[q[r]] - c[q[r - 1]]);)r--;
        q[++r] = i;
    }
    cout << dp[n];
    return 0;
}

// @pid 80 @tid 6a72d3367c64e169ce051ea9 @lang cc.cc14o2
