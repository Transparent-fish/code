#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int T, n, ans, a[N], b[N];

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n;
        ans = 0;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        for (int i = 2;i <= n;i++) {
            b[i] = min(b[i], b[i - 1] + 1);
        }
        for (int i = n - 1;i >= 1;i--) {
            b[i] = min(b[i], b[i + 1] + 1);
        }
        for (int i = 1;i <= n;i++) {
            ans += a[i] - b[i];
        }
        cout << ans << "\n";
    }
    return 0;
}