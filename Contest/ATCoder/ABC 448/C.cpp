#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int n, q, a[N], b[N], tree[N << 2];

void pushup(int rt) {
    tree[rt] = min(tree[rt << 1], tree[rt << 1 | 1]);
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

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return tree[rt];
    }
    int mid = (l + r) >> 1, Min = 1e18;
    if (L <= mid)Min = min(Min, query(l, mid, rt << 1, L, R));
    if (R > mid)Min = min(Min, query(mid + 1, r, rt << 1 | 1, L, R));
    return Min;
}

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    for (;q--;) {
        int k;
        cin >> k;
        for (int i = 1;i <= k;i++) {
            cin >> b[i];
        }
        sort(b + 1, b + k + 1);
        int Min = 1e18, las = 1;
        for (int i = 1;i <= k;i++) {
            if (b[i] > las)Min = min(Min, query(1, n, 1, las, b[i] - 1));
            las = b[i] + 1;
        }
        if (las <= n)Min = min(Min, query(1, n, 1, las, n));
        cout << Min << "\n";
    }
    return 0;
}