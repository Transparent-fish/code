#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, w, sum, ans, a[N], b[N];

void init() {
    sum = ans = 0;
    for (int i = 0; i <= 2 * w; i++) b[i] = 0;
}

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n >> w;
        init();
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            b[(i - 1) % (2 * w)] += a[i];
        }
        for (int i = 0; i < w; i++) sum += b[i];
        ans = sum;
        for (int i = 1; i < 2 * w; i++) {
            sum = sum - b[(i - 1) % (2 * w)] + b[(i + w - 1) % (2 * w)];
            if (sum < ans) ans = sum;
        }
        cout << ans << "\n";
    }
    return 0;
}