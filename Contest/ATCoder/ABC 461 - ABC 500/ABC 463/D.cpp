#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;

struct node {
    int l, r;
    friend bool operator<(node a, node b) {
        return a.r < b.r;
    }
}a[N];

bool check(int x) {
    int cnt = 0, las = -1e18;
    for (int i = 1;i <= n;i++) {
        if (a[i].l >= las + x)cnt++, las = a[i].r;
        if (cnt >= k)return 1;
    }
    return cnt >= k;
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e9, ans = -1;
    for (;l <= r;) {
        
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid + 1, ans = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}