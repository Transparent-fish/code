#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 1e6 + 5;
int n;
d l, r, a[N];

d f(d x) {
    d ans = 0;
    for (int i = 0;i <= n;i++) {
        ans = ans * x + a[i];
    }
    return ans;
}

signed main() {
    cin >> n >> l >> r;
    for (int i = 0;i <= n;i++) {
        cin >> a[i];
    }
    d x = (l + r) / 2, s = (r - l) / 2;
    for (;s > 1e-8;) {
        d xl = max(x - s, l), xr = min(x + s, r);
        if (f(xl) > f(x)) x = xl;
        else if (f(xr) > f(x)) x = xr;
        s *= 0.99;
    }
    printf("%.10f", x);
    return 0;
}