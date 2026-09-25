#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, S, K, a[N];

signed main() {
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    cin >> n >> S >> K;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int L = a[1], R = a[n], l = -1, r = -1;
    for (int i = 1;i <= n;i++) {
        if (a[i] < S) l = a[i];
        if (a[i] > S && r == -1) r = a[i];
    }
    if (l == -1) {
        cout << R - S;
        exit(0);
    }
    if (r == -1) {
        cout << S - L;
        exit(0);
    }
    if (K == 0) {
        int ans = min(2 * (S - L) + (R - S), 2 * (R - S) + (S - L));
        cout << ans;
        exit(0);
    }
    int ans = min(S + R - L - l, R - S + r - L);
    cout << ans;
    return 0;
}