#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt, a[N], rot[N];

struct node {
    int l, r, v;
}tree[(N << 2) + N * 25];

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt].v = a[l];
        return;
    }
    int mid = l + r >> 1;
    tree[rt].l = ++cnt;
    build(l, mid, tree[rt].l);
    tree[rt].r = ++cnt;
    build(mid + 1, r, tree[rt].r);
}

void update(int l, int r, int rt, int las, int p, int v) {
    if (l == r) {
        tree[rt].v = v;
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) {
        tree[rt].r = tree[las].r, tree[rt].l = ++cnt;
        update(l, mid, tree[rt].l, tree[las].l, p, v);
    }
    else {
        tree[rt].l = tree[las].l, tree[rt].r = ++cnt;
        update(mid + 1, r, tree[rt].r, tree[las].r, p, v);
    }
}

int query(int l, int r, int rt, int v) {
    if (l == r)return tree[rt].v;
    int mid = l + r >> 1;
    if (v <= mid)return query(l, mid, tree[rt].l, v);
    else return query(mid + 1, r, tree[rt].r, v);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    rot[0] = ++cnt;
    build(1, n, 1);
    for (int i = 1;i <= m;i++) {
        int op, l, r, v;
        cin >> v >> op >> l;
        if (op == 1) {
            cin >> r;
            rot[i] = ++cnt;
            update(1, n, rot[i], rot[v], l, r);
        }
        else {
            rot[i] = rot[v];
            cout << query(1, n, rot[i], l) << "\n";
        }
    }
    return 0;
}