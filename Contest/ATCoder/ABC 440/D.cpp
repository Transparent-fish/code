#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], x[N], y[N];

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= q;i++) {
        cin >> x[i] >> y[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= q;i++) {
        int l = x[i], r = x[i] + y[i] + n, ans = r;
        for (;l <= r;) {
            int mid = l + r >> 1;
            if ((mid - x[i] + 1) - ((upper_bound(a + 1, a + n + 1, mid) - a) - (lower_bound(a + 1, a + n + 1, x[i]) - a)) >= y[i]) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }cout << ans << "\n";
    }
    return 0;
}