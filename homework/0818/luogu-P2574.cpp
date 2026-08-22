#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, a[N];
int tree[N << 2], tag[N << 2];
string str;

void pushup(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void pushdown(int l, int r, int rt) {
    if (tag[rt]) {
        int mid = l + r >> 1;
        tag[rt << 1] ^= 1, tag[rt << 1 | 1] ^= 1;
        tree[rt << 1] = (mid - l + 1) - tree[rt << 1];
        tree[rt << 1 | 1] = (r - mid) - tree[rt << 1 | 1];
        tag[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        tree[rt] = (r - l + 1) - tree[rt];
        tag[rt] ^= 1;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, rt);
    if (L <= mid)update(l, mid, rt << 1, L, R);
    if (R > mid)update(mid + 1, r, rt << 1 | 1, L, R);
    pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return tree[rt];
    }
    int mid = (l + r) >> 1, sum = 0;
    pushdown(l, r, rt);
    if (L <= mid)sum += query(l, mid, rt << 1, L, R);
    if (R > mid)sum += query(mid + 1, r, rt << 1 | 1, L, R);
    return sum;
}

signed main() {
    cin >> n >> m >> str;
    for (int i = 1;i <= n;i++) {
        a[i] = str[i - 1] - '0';
    }
    build(1, n, 1);
    for (;m--;) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 0) {
            update(1, n, 1, l, r);
        }
        else {
            cout << query(1, n, 1, l, r) << "\n";
        }
    }
    return 0;
}
