#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, a[N];

bool check(int d) {
    int cnt = 1, last = a[1];
    for (int i = 2;i <= n;i++) {
        if (a[i] - last >= d) {
            cnt++;
            last = a[i];
        }
    }
    return cnt >= m;
}

signed main() {
    freopen("dis.in", "r", stdin);
    freopen("dis.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = a[n] - a[1];
    for (;l <= r;) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}