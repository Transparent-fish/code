#include<bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 1e6 + 5;
int n, cnt, x[N], p[N], c[N], s[N], spc[N], f[N], q[N];

d check(int i, int j) {
    d dy = f[i] + spc[i] - f[j] - spc[j];
    d dx = s[i] - s[j];
    if (!dx) {
        if (!dy)return 0;
        if (dy > 0)return 1e18;
        if (dy < 0) return -1e18;
    }
    return (d)1.0 * dy / dx;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> x[i] >> p[i] >> c[i];
        s[i] = s[i - 1] + p[i];
        spc[i] = spc[i - 1] + p[i] * x[i];
    }
    int l = 1;
    q[++cnt] = 0;
    for (int i = 1;i <= n;i++) {
        for (;l < cnt && check(q[l], q[l + 1]) <= x[i];)l++;
        f[i] = f[q[l]] + c[i] + x[i] * (s[i] - s[q[l]]) - (spc[i] - spc[q[l]]);
        if (!p[i])f[i] = min(f[i], f[i - 1]);
        for (;l < cnt && check(q[cnt], q[cnt - 1]) >= check(q[cnt - 1], i);)cnt--;
        q[++cnt] = i;
    }
    int now = n, ans = f[n];
    for (;now && s[now] == s[now - 1];) {
        ans = min(ans, f[now]);
        now--;
    }
    cout << ans;
    return 0;
}

// @pid 81 @tid 6a72d3367c64e169ce051ea9 @lang cc.cc14o2
