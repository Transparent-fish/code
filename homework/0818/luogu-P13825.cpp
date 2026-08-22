#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 5e6 + 5;
int n, m, cnt, rt, tree[N], tag[N], ls[N], rs[N], c[N];

void pushup(int rt) {
    tree[rt] = tree[ls[rt]] + tree[rs[rt]];
}

void pushdown(int x, int l, int r, int mid) {
    if (c[x]) {
        if (!ls[x])ls[x] = ++cnt;
        if (!rs[x])rs[x] = ++cnt;
        tree[ls[x]] += (mid - l + 1) * c[x], tree[rs[x]] += (r - mid) * c[x];
        c[ls[x]] += c[x], c[rs[x]] += c[x];c[x] = 0;
    }
}

void build(int& p, int l, int r) {
    p = ++cnt;
    if (l == r) {
        tree[p] = l;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls[p], l, mid);
    build(rs[p], mid + 1, r);
    pushup(p);
}

void update(int& p, int l, int r, int L, int R, int v) {
    if (!p)p = ++cnt;
    if (L <= l && r <= R) {
        tree[p] += (r - l + 1) * v, c[p] += v;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(p, l, r, mid);
    if (L <= mid)update(ls[p], l, mid, L, R, v);
    if (R > mid)update(rs[p], mid + 1, r, L, R, v);
    pushup(p);
}

int query(int x, int l, int r, int L, int R) {
    if (L <= l && r <= R)return tree[x];
    int mid = l + r >> 1, ans = 0;
    pushdown(x, l, r, mid);
    if (L <= mid)ans += query(ls[x], l, mid, L, R);
    if (R > mid)ans += query(rs[x], mid + 1, r, L, R);
    return ans;
}

signed main() {
    cin >> n >> m;
    // build(rt, 1, n);
    for (int i = 1;i <= m;i++) {
        int op, l, r, v;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> v;
            update(rt, 1, n, l, r, v);
        }
        else {
            cout << query(rt, 1, n, l, r) + ((l + r) * (r - l + 1) / 2) << "\n";
        }
    }
    return 0;
}