#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], b[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= m;i++)cin >> b[i];
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    int i = 1, j = 1, ans = 0;
    for (;i <= n && j <= m;) {
        if (b[j] <= 2 * a[i])ans++, i++, j++;
        else i++;
    }
    cout << ans;
    return 0;
}