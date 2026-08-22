#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, mod = 1e9 + 7, M = 1e6 + 5;
int n, k, a[N], s[M], dp[N][M];

int Sum(int l, int r) {
    return (l == 0 ? s[r] : (s[r] + mod - s[l - 1]) % mod);
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1;i <= n;i++) {
        s[0] = dp[i - 1][0];
        for (int j = 1;j <= k;j++) {
            s[j] = (s[j - 1] + dp[i - 1][j]) % mod;
        }
        dp[i][0] = dp[i - 1][0];
        for (int j = 1;j <= k;j++) {
            dp[i][j] = Sum(max(0LL, j - a[i]), j);
        }
    }
    cout << dp[n][k] % mod;
    return 0;
}