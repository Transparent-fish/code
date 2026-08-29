#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], tree[N];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int k) {
    for (int i = x;i <= n;i += lowbit(i)) {
        tree[i] += k;
    }
}

int query(int x) {
    int sum = 0;
    for (int i = x;i >= 1;i -= lowbit(i)) {
        sum += tree[i];
    }
    return sum;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    for (;m--;) {
    int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            update(l, r);
        }
        else {
            cout << query(r) - query(l - 1) << "\n";
        }
    }
    return 0;
}