#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, x, y, cnt, a[N];

bool check(int c) {
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] > c * x)sum += (a[i] - x * c + y - 1) / y;
    }
    return sum <= c;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifdef __linux__
    freopen("clean.in", "r", stdin);
    freopen("clean.out", "w", stdout);
#endif
    cin >> n >> x >> y;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int l = 0, r = 1e9, ans = 0;
    for (;l <= r;) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1, ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}