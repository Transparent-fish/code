#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N];
vector<int> e[N];
int dp[N];

signed main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        e[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (e[i].empty()) {
            dp[i] = a[i];
        }
        else {
            int ans = 0;
            for (auto child : e[i]) {
                ans += dp[child];
            }
            dp[i] = min(a[i], ans);
        }
    }
    cout << dp[1] << "\n";
    return 0;
}