#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 9999973, N = 1000005;
int l, r, cnt, a[N], vis[N];
int ans;

void dfs(int x) {
    if (x > r) return;
    if (x) a[++cnt] = x;
    dfs(x * 10 + 6), dfs(x * 10 + 8);
}

void dfs(int pos, int dep, int lc) {
    if (dep) {
        if (dep & 1) ans += r / lc;
        else ans -= r / lc;
    }
    for (int i = pos + 1; i <= cnt; i++) {
        if (a[i] > r) continue;
        int g = __gcd(lc, a[i]);
        if (a[i] / g > r / lc) continue;
        dfs(i, dep + 1, lc / g * a[i]);
    }
}

signed main() {
    cin >> l >> r;
    dfs(0);
    sort(a + 1, a + cnt + 1);
    int k = 0;
    for (int i = 1; i <= cnt; i++) {
        if (vis[i]) continue;
        a[++k] = a[i];
        for (int j = i + 1; j <= cnt; j++) {
            if (a[j] % a[i] == 0) vis[j] = 1;
        }
    }
    cnt = k, ans = 0;
    reverse(a + 1, a + cnt + 1);
    dfs(0, 0, 1);
    k = ans, ans = 0, r = l - 1;
    dfs(0, 0, 1);
    cout << k - ans;
    return 0;
}

// @pid 112 @tid 6a6c7f23bdb36af2d80fa4cd @lang cc.cc14o2
