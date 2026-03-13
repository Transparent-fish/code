#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], b[N], dp[N];

signed main() {
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) {
        cin >> b[i];
    }
    for (int i = 0;i < n + n;i++)dp[i] = LLONG_MIN;
    dp[0] = 0;
    for (int j = 0;j < n * 2;j++) {
        for (int i = 0;i < m;i++) {
            if (j >= a[i]) dp[j] = max(dp[j], dp[j - a[i]] + b[j - a[i]]);
        }
    }
    int Max = 0;
    for (int i = n + 1;i < n * 2;i++) {
        Max = max(Max, dp[i]);
    }
    cout << Max;
    return 0;
}