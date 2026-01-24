#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 998244353;
int n, m, sum, ans, a[N], b[N], s[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
        sum = (sum + b[i]) % mod;
    }
    sort(b + 1, b + m + 1);
    for (int i = 1;i <= m;i++) {
        s[i] = (s[i - 1] + b[i]) % mod;
    }
    for (int i = 1;i <= n;i++) {
        int now = lower_bound(b + 1, b + m + 1, a[i]) - b;
        ans = ((ans + (((2 * (now - 1) - m) % mod + mod) % mod * (a[i] % mod) % mod) + ((sum - 2 * s[now - 1] % mod + mod) % mod))) % mod;
    }
    cout << ans % mod;
    return 0;
}