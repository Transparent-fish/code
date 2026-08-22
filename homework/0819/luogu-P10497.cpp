#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], ans[N], tree[N << 2];

int lobit(int x) {
    return x & -x;
}

void add(int x, int c) {
    for (int i = x;i <= n;i += lobit(i)) {
        tree[i] += c;
    }
}

int query(int x) {
    int ans = 0;
    for (int i = x;i >= 1;i -= lobit(i)) {
        ans += tree[i];
    }
    return ans;
}

int kth(int k) {
    int l = 1, r = n;
    for (;l < r;) {
        int mid = (l + r) / 2;
        if (query(mid) >= k) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        add(i, 1);
    }
    for (int i = 2;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = n;i >= 1;i--) {
        int tmp = a[i] + 1;
        ans[i] = kth(tmp);
        add(kth(tmp), -1);
    }
    for (int i = 1;i <= n;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}