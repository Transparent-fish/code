#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N = 1e6 + 5;
int n, m, tot, a[N], rot[N];

struct node {
    int l, r, sum;
} tree[N * 20];

void build(int& p, int l, int r) {
    p = ++tot;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(tree[p].l, l, mid), build(tree[p].r, mid + 1, r);
}

void update(int& p, int pre, int l, int r, int pos) {
    p = ++tot;
    tree[p] = tree[pre], tree[p].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(tree[p].l, tree[pre].l, l, mid, pos);
    else update(tree[p].r, tree[pre].r, mid + 1, r, pos);
}

int query(int u, int v, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (tree[tree[v].l].sum - tree[tree[u].l].sum > k) return query(tree[u].l, tree[v].l, l, mid, k);
    if (tree[tree[v].r].sum - tree[tree[u].r].sum > k) return query(tree[u].r, tree[v].r, mid + 1, r, k);
    return 0;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    build(rot[0], 1, n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(rot[i], rot[i - 1], 1, n, a[i]);
    }
    for (;m--;) {
        int l, r;
        cin >> l >> r;
        cout << query(rot[l - 1], rot[r], 1, n, ((r - l + 1) >> 1)) << "\n";
    }
    return 0;
}