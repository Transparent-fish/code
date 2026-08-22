#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, a[N], mp[N], dp[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int c = n;c >= 1;c--) {
        int i = mp[c], win = 0;
        for (int j = i - a[i];j >= 1;j -= a[i]) {
            if (a[j] > a[i] && dp[j] == 0) {
                win = 1;
                break;
            }
        }
        if (!win) {
            for (int j = i + a[i];j <= n;j += a[i]) {
                if (a[j] > a[i] && dp[j] == 0) {
                    win = 1;
                    break;
                }
            }
        }
        dp[i] = (win ? 1 : 0);
    }
    for (int i = 1;i <= n;i++) {
        cout << (dp[i] ? "A" : "B");
    }
    return 0;
}