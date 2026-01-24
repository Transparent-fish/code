#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], tree[N];

int lowbit(int x) {
    return x & (-x);
}

void add(int i, int c) {
    for (; i <= n; i += lowbit(i)) {
        tree[i] += c;
    }
}

int sum(int i) {
    int Sum = 0;
    for (; i > 0; i -= lowbit(i)) {
        Sum += tree[i];
    }
    return Sum;
}

void Swap(int x) {
    int now = a[x + 1] - a[x], noow = a[x] - a[x + 1];
    add(x, now), add(x + 1, noow);
    swap(a[x], a[x + 1]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    for (;q--;) {
        int op, l, r, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            Swap(x);
        }
        else {
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << "\n";
        }
    }
    return 0;
}