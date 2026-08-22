#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];

struct node {
    int sum, lmx, rmx, Max;
    friend node operator+(node a, node b) {
        node c;
        c.sum = a.sum + b.sum;
        c.lmx = max(a.sum + b.lmx, a.lmx);
        c.rmx = max(b.sum + a.rmx, b.rmx);
        c.Max = max(a.sum + b.lmx, b.sum + a.rmx);
        c.Max = max(c.Max, max(a.Max, b.Max));
        c.Max = max(c.Max, a.sum + b.sum);
        c.Max = max(c.Max, a.rmx + b.lmx);
        return c;
    }
} tree[N];

void pushup(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = { a[l], a[l], a[l], a[l] };
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int l, int r, int rt, int p, int c) {
    if (l == r) {
        tree[rt] = { c, c, c, c };
        return;
    }
    int mid = l + r >> 1;
    if (p <= mid) update(l, mid, rt << 1, p, c);
    else update(mid + 1, r, rt << 1 | 1, p, c);
    pushup(rt);
}

node query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return tree[rt];
    int mid = l + r >> 1;
    if (R <= mid) return query(l, mid, rt << 1, L, R);
    else if (L > mid) return query(mid + 1, r, rt << 1 | 1, L, R);
    return query(l, mid, rt << 1, L, R) + query(mid + 1, r, rt << 1 | 1, L, R);
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    for (; m--;) {
        int op, l, r, p, c;
        cin >> op >> l >> r;
        if (op == 1) {
            if (l > r) swap(l, r);
            cout << query(1, n, 1, l, r).Max << "\n";
        }
        else {
            update(1, n, 1, l, r);
        }
    }
    return 0;
}