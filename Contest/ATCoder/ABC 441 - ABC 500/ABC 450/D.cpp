#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, ans, a[N];

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] %= k;
    }
    sort(a + 1, a + n + 1);
    ans = a[n] - a[1];
    for (int i = 1;i <= n;i++) {
        ans = min(ans, a[i] + k - a[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}