#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, r, mod, a[N], dep[N], fa[N], son[N];
int cnt, siz[N], top[N], V[N], id[N], tree[N], tag[N];
vector<int>e[N];

void dfs(int x, int f, int Dep) {
    dep[x] = dep[f] + 1, fa[x] = f, siz[x] = 1;
    int Max = 0;
    for (auto v : e[x]) {
        if (v == fa[x]) continue;
        dfs(v, x, Dep + 1);
        siz[x] += siz[v];
        if (siz[v] > Max) Max = siz[v], son[x] = v;
    }
}

void dfs1(int x, int f) {
    id[x] = ++cnt, top[x] = f;
    V[cnt] = a[x];
    if (!son[x]) return;
    dfs1(son[x], f);
    for (auto v : e[x]) {
        if (v == fa[x] || v == son[x]) continue;
        dfs1(v, v);
    }
}

void pushup(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1], tree[rt] %= mod;
}

void pushdown(int l, int r, int rt) {
    if (tag[rt]) {
        int mid = (l + r) >> 1;
        (tag[rt << 1] += tag[rt]) %= mod;
        (tag[rt << 1 | 1] += tag[rt]) %= mod;
        (tree[rt << 1] += tag[rt] * (mid - l + 1)) %= mod;
        (tree[rt << 1 | 1] += tag[rt] * (r - mid)) %= mod;
        tag[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = V[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1), pushup(rt);
}

void update(int l, int r, int rt, int L, int R, int v) {
    if (L <= l && r <= R) {
        tag[rt] = (tag[rt] + v) % mod;
        tree[rt] = (tree[rt] + (v * (r - l + 1))) % mod;
        return;
    }
    pushdown(l, r, rt);
    int mid = l + r >> 1;
    if (L <= mid) update(l, mid, rt << 1, L, R, v);
    if (R > mid) update(mid + 1, r, rt << 1 | 1, L, R, v);
    pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return tree[rt] % mod;
    int mid = l + r >> 1;
    pushdown(l, r, rt);
    int res = 0;
    if (L <= mid) res += (query(l, mid, rt << 1, L, R)) % mod;
    if (R > mid) res += (query(mid + 1, r, rt << 1 | 1, L, R)) % mod;
    return res;
}

void update_add(int x, int y, int v) {
    v %= mod;
    for (; top[x] != top[y];) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, n, 1, id[top[x]], id[x], v);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, n, 1, id[x], id[y], v);
}

int query_sum(int x, int y) {
    int res = 0;
    for (; top[x] != top[y];) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        (res += query(1, n, 1, id[top[x]], id[x])) %= mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    (res += query(1, n, 1, id[x], id[y])) %= mod;
    return res;
}

signed main() {
    cin >> n >> m >> r >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(r, 0, 1), dfs1(r, r), build(1, n, 1);
    int _ = m;
    for (; _--;) {
        int op, x, y, z;
        cin >> op >> x;
        if (op == 1) {
            cin >> y >> z;
            update_add(x, y, z);
        }
        else if (op == 2) {
            cin >> y;
            cout << query_sum(x, y) << "\n";
        }
        else if (op == 3) {
            cin >> z;
            update(1, n, 1, id[x], id[x] + siz[x] - 1, z);
        }
        else cout << query(1, n, 1, id[x], id[x] + siz[x] - 1) % mod << "\n";
    }
    return 0;
}