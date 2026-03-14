#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int l, r, d, u, Max, ans;

int f(int x) {
    int xl = max(l, -x), xr = min(r, x), yl = max(d, -x), yr = min(u, x);
    if (xl > xr || yl > yr)return 0;
    return (xr - xl + 1) * (yr - yl + 1);
}

signed main() {
    cin >> l >> r >> d >> u;
    Max = max({ Max,abs(l),abs(r),abs(d),abs(u) });
    for (int i = 0;i <= Max;i += 2) {
        ans += f(i) - f(i - 1);
    }
    cout << ans;
    return 0;
}