#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], tree[N];

int lowbit(int x) { return x & -x; }

void update(int x, int v) {
    for (int i = x;i <= n;i += lowbit(i))tree[i] += v;
}

int query(int l) {
    int sum = 0;
    for (int i = l;i >= 1;i -= lowbit(i))sum += tree[i];
    return sum;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        update(i, a[i]);
    }
    for (;m--;) {
        int op, x, k;
        cin >> op >> x >> k;
        if (op == 1)update(x, k);
        else cout << query(k) - query(x - 1) << "\n";
    }
    return 0;
}