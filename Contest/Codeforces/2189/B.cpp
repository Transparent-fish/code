#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, x, a[N], b[N], c[N];

bool check(int x, int y, int z, int Max) {
    if (y <= z)return 1;
    else if (Max <= 0)return 0;
    else if (x >= (y - z + Max - 1) / Max)return 1;
    else return 0;
}

signed main() {
    cin >> T;
    for (;T--;) {
        int sum = 0, Max = LLONG_MIN;
        cin >> n >> x;
        for (int i = 1;i <= n;i++) {
            cin >> a[i] >> b[i] >> c[i];
            sum += (b[i] - 1) * a[i], Max = max(Max, b[i] * a[i] - c[i]);
        }
        int l = 0, r = 2e18, ans = -1;
        for (;l <= r;) {
            int mid = l + r >> 1;
            if (check(mid, x, sum, Max)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}