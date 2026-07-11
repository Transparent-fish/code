#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], fa[N], b[N], ans[N];

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = 0;
        b[i] = 0;
        ans[i] = 0;
    }
    for (; q--;) {
        int c, p;
        cin >> c >> p;
        if (fa[c]) {
            b[fa[c]] = 0;
        }
        fa[c] = p;
        b[p] = c;
    }
    for (int i = 1; i <= n; i++) {
        if (fa[i] != 0) {
            ans[i] = 0;
        }
        else {
            int now = i;
            for (;now;) {
                ans[i]++;
                now = b[now];
            }
        }
        cout << ans[i] << " ";
    }
    return 0;
}