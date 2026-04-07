#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, L, R, now, t[N], l[N], u[N], r[N], vis = 1;

signed main() {
    cin >> T;
    for (;T--;) {
        int n, h;
        vis = 1;
        cin >> n >> h;
        for (int i = 1;i <= n;i++) {
            cin >> t[i] >> l[i] >> u[i];
        }
        L = h, R = h, now = 0;
        for (int i = 1;i <= n;i++) {
            L -= t[i] - now, R += t[i] - now;
            L = max(L, l[i]), R = min(R, u[i]);
            if (L > R) {
                vis = 0;
                break;
            }
            now = t[i];
        }
        if (vis)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}