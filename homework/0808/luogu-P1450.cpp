#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, c[10], f[N];

struct node {
    int s, d[10];
}a[N];

signed main() {
    for (int i = 1;i <= 4;i++) {
        cin >> c[i];
    }
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= 4;j++) {
            cin >> a[i].d[j];
        }
        cin >> a[i].s;
    }
    f[0] = 1;
    for (int i = 1;i <= 4;i++) {
        for (int j = c[i];j <= N;j++) {
            f[j] += f[j - c[i]];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j <= 15;j++) {
            int now = a[i].s, cnt = 0;
            for (int k = 1;k <= 4;k++) {
                if (j >> (k - 1) & 1) {
                    cnt = 1 - cnt;
                    now -= c[k] * (a[i].d[k] + 1);
                }
            }
            if (cnt == 1)ans -= f[now];
            else ans += f[now];
        }
        cout << ans << "\n";
        ans = 0;
    }
    return 0;
}

// @pid 36 @tid 6a6c7f23bdb36af2d80fa4cd @lang cc.cc14o2
