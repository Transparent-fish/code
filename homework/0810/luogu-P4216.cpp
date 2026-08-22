#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, cnt, root, a[N], rot[N], dep[N], f[20][N];
int qc, qx[N], qy[N], qd[N];
vector<int>sk, e[N];

struct node {
    int l, r, v;
}tree[N * 22];

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt].v = 0;
        return;
    }
    int mid = l + r >> 1;
    tree[rt].l = ++cnt;
    build(l, mid, tree[rt].l);
    tree[rt].r = ++cnt;
    build(mid + 1, r, tree[rt].r);
}

void update(int l, int r, int rt, int las, int p, int v) {
    tree[rt].v = tree[las].v + v;
    if (l == r) return;
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
    if (!rt || v < l) return 0;
    if (r <= v) return tree[rt].v;
    int mid = l + r >> 1;
    int res = query(l, mid, tree[rt].l, v);
    if (v > mid) res += query(mid + 1, r, tree[rt].r, v);
    return res;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int diff = dep[u] - dep[v];
    for (int j = 0; j < 20; ++j) {
        if (diff & (1 << j)) u = f[j][u];
    }
    if (u == v) return u;
    for (int j = 19; j >= 0; --j) {
        if (f[j][u] != f[j][v]) {
            u = f[j][u];
            v = f[j][v];
        }
    }
    return f[0][u];
}

void init() {
    sk.push_back(root);
    for (;!sk.empty();) {
        int u = sk.back(), p = f[0][u];
        sk.pop_back();
        rot[u] = rot[p];
        if (a[u]) {
            rot[u] = ++cnt;
            update(1, q, rot[u], rot[p], a[u], 1);
        }
        for (auto v : e[u]) {
            dep[v] = dep[u] + 1;
            for (int j = 1; j < 20; ++j) {
                f[j][v] = f[j - 1][f[j - 1][v]];
            }
            sk.push_back(v);
        }
    }
}

signed main() {
    if (!(cin >> n)) return 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f[0][i] = a[i];
        if (a[i] == 0) root = i;
        else e[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) a[i] = 0;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int k, x, y, c, d, t;
        cin >> k;
        if (k == 1) {
            cin >> x >> y >> c;
            d = i - c - 1;
            if (d < 0) d = 0;
            if (d > q) d = q;
            ++qc;
            qx[qc] = x, qy[qc] = y, qd[qc] = d;
        }
        else {
            cin >> t;
            if (!a[t]) a[t] = i;
        }
    }
    if (!qc) return 0;
    rot[0] = ++cnt;
    build(1, q, rot[0]);
    init();
    for (int i = 1; i <= qc; ++i) {
        int Lca = lca(qx[i], qy[i]);
        cout << dep[qx[i]] + dep[qy[i]] - 2 * dep[Lca] + 1 << " ";
        cout << query(1, q, rot[qx[i]], qd[i])
            + query(1, q, rot[qy[i]], qd[i])
            - query(1, q, rot[Lca], qd[i])
            - query(1, q, rot[f[0][Lca]], qd[i]) << "\n";
    }
    return 0;
}

// @pid 180 @tid 6a7836f3f80e134e7821926a @lang cc.cc14o2
