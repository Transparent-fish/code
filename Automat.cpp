#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, x, y, a[N], b[N];
int pre[N], pree[N];

void init() {
    sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
    for (int i = 1;i <= n;i++) pre[i] = pre[i - 1] + a[i];
    for (int i = 1;i <= m;i++) pree[i] = pree[i - 1] + b[i];
}

signed main() {
    cin >> n >> m >> k >> x >> y;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    init();
    int ans = 0, t = 0;
    for (int i = 1;i <= m;i++) {
        t += (b[i] + k - 1) / k;
        if (t > y) break;
        int l = 0, r = n, mo = x + y * k - pree[i];
        for (;l < r;) {
            int mid = (l + r + 1) / 2;
            if (pre[mid] <= mo) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, i + l);
    }
    int l = 0, r = n, mo = x + y * k;
    for (;l < r;) {
        int mid = (l + r + 1) / 2;
        if (pre[mid] <= mo) l = mid;
        else r = mid - 1;
    }
    cout << max(ans, l);
    return 0;
}