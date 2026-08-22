#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 5;

int n, q, cnt, root, a[N], rot[N], dep[N], f[20][N];
vector<int> e[N];

struct node {
    int l, r, v;
} tree[N * 25];

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
        tree[rt].r = tree[las].r;
        tree[rt].l = ++cnt;
        update(l, mid, tree[rt].l, tree[las].l, p, v);
    } else {
        tree[rt].l = tree[las].l;
        tree[rt].r = ++cnt;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p;
        f[0][i] = p;
        if (p == 0) {
            root = i;
        } else {
            e[p].push_back(i);
        }
    }

    if (!root) root = 1;

    for (int i = 1; i <= n; ++i) a[i] = 0;

    cin >> q;

    vector<int> qx, qy, qd;
    qx.reserve(q);
    qy.reserve(q);
    qd.reserve(q);

    for (int day = 1; day <= q; ++day) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, c;
            cin >> x >> y >> c;
            int d = day - c - 1;
            if (d < 0) d = 0;
            if (d > q) d = q;
            qx.push_back(x);
            qy.push_back(y);
            qd.push_back(d);
        } else {
            int t;
            cin >> t;
            if (!a[t]) a[t] = day;
        }
    }

    if (qx.empty() || !q) return 0;

    rot[0] = ++cnt;
    build(1, q, rot[0]);

    vector<int> st;
    st.reserve(n);
    st.push_back(root);

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        int p = f[0][u];
        rot[u] = rot[p];

        if (a[u]) {
            rot[u] = ++cnt;
            update(1, q, rot[u], rot[p], a[u], 1);
        }

        for (int v : e[u]) {
            dep[v] = dep[u] + 1;
            for (int j = 1; j < 20; ++j) {
                f[j][v] = f[j - 1][f[j - 1][v]];
            }
            st.push_back(v);
        }
    }

    for (int i = 0; i < (int)qx.size(); ++i) {
        int x = qx[i], y = qy[i];
        int z = lca(x, y);
        int len = dep[x] + dep[y] - 2 * dep[z] + 1;
        int d = qd[i];
        int ans = 0;

        if (d > 0) {
            ans = query(1, q, rot[x], d)
                + query(1, q, rot[y], d)
                - query(1, q, rot[z], d)
                - query(1, q, rot[f[0][z]], d);
        }

        cout << len << ' ' << ans << '\n';
    }

    return 0;
}