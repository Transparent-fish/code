#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 35005;
int n, m, tree[N << 2], tag[N << 2], a[N], f[55][N];
map<int, int>mp, las;

void pushup(int rt) {
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void pushdown(int l, int r, int rt) {
    if (tag[rt]) {
        int mid = l + r >> 1;
        tag[rt << 1] += tag[rt];
        tag[rt << 1 | 1] += tag[rt];
        tree[rt << 1] += tag[rt];
        tree[rt << 1 | 1] += tag[rt];
        tag[rt] = 0;
    }
}

void build(int l, int r, int rt, int v) {
    tag[rt] = 0;
    if (l == r) {
        tree[rt] = f[v][l - 1];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1, v);
    build(mid + 1, r, rt << 1 | 1, v);
    pushup(rt);
}

void update(int l, int r, int rt, int L, int R, int p) {
    if (L <= l && r <= R) {
        tree[rt] += p;
        tag[rt] += p;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, rt);
    if (L <= mid)update(l, mid, rt << 1, L, R, p);
    if (R > mid)update(mid + 1, r, rt << 1 | 1, L, R, p);
    pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return tree[rt];
    }
    int mid = (l + r) >> 1, Max = 0;
    pushdown(l, r, rt);
    if (L <= mid)Max = max(Max, query(l, mid, rt << 1, L, R));
    if (R > mid)Max = max(Max, query(mid + 1, r, rt << 1 | 1, L, R));
    return Max;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[i] = las[a[i]] + 1, las[a[i]] = i;
    }
    for (int i = 1;i <= m;i++) {
        build(1, n, 1, i - 1);
        for (int j = 1;j <= n;j++) {
            update(1, n, 1, mp[j], j, 1);
            f[i][j] = query(1, n, 1, 1, j);
        }
    }
    cout << f[m][n];
    return 0;
}