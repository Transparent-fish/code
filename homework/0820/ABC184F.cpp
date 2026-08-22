#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = (1 << 20) + 5;
int n, t, cnt, cntt, Max, a[N], b[N], c[N];

void dfs(int x, int sum) {
    if (sum > t)return;
    if (x > (n >> 1)) {
        b[++cnt] = sum;
        return;
    }
    dfs(x + 1, sum + a[x]), dfs(x + 1, sum);
}

void dfs2(int x, int sum) {
    if (sum > t)return;
    if (x > n) {
        c[++cntt] = sum;
        return;
    }
    dfs2(x + 1, sum + a[x]), dfs2(x + 1, sum);
}

signed main() {
    cin >> n >> t;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dfs(1, 0), dfs2(n / 2 + 1, 0);
    sort(b + 1, b + cnt + 1), sort(c + 1, c + cntt + 1);
    for (int i = 1;i <= cnt;i++) {
        Max = max(Max, c[upper_bound(c + 1, c + cntt + 1, t - b[i]) - c - 1] + b[i]);
    }
    cout << Max;
    return 0;
}