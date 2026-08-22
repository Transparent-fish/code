#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4e+5;
int n, l, r, ans = -1e18;
int t = -1, h;
int a[N], f[N], q[N];

signed main() {
    cin >> n >> l >> r;
    for (int i = 0;i <= n;i++) {
        cin >> a[i];
    }
    memset(f, 0xcf, sizeof(f));
    f[0] = a[0];
    for (int i = l;i <= n + r;i++) {
        for (;t >= h && f[i - l] >= f[q[t]];) {
            --t;
        }
        q[++t] = i - l;
        for (;t >= h && q[h] < i - r;) {
            h++;
        }
        f[i] = f[q[h]] + a[i];
        if (i >= n) ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}