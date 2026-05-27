#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 10007;
int n, ans, a[N];

bool pan(int q, int w, int e, int r) {
    return (1 <= q && q < w && w < e && e < r && r <= n) && (a[q]<a[w] && a[w] == a[e] && a[e]>a[r]);
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (int w = 1;w <= n;w++) {
        for (int e = 1;e <= n;e++) {
            if (a[w] == a[e]) {
                for (int q = 1;q <= n;q++) {
                    for (int r = 1;r <= n;r++) {
                        if (pan(q, w, e, r))ans++, ans %= mod;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}