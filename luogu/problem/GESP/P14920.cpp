#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, sum, a[N], c[N], dp[N];

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }
    memset(dp, 1e9, sizeof(dp));
    for (int i = 1;i <= n;i++) {
        for (int j = sum;j >= a[i];j--) {
            dp[j] = min(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    for (int i = sum;i >= 0;i--) {
        if (k >= dp[i]) { cout << i;exit(0); }
    }
    return 0;
}