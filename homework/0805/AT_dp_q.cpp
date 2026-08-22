#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], b[N], tree[N], tag[N], dp[N];

void pushup(int rt) {
    tree[rt] = max(tree[rt << 1], tree[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if (l == r) {
        tree[rt] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void update(int l, int r, int rt, int L, int R, int p) {
    if (L <= l && r <= R) {
        tree[rt] = max(tree[rt], p);
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(l, mid, rt << 1, L, R, p);
    if (R > mid) update(mid + 1, r, rt << 1 | 1, L, R, p);
    pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        return tree[rt];
    }
    int mid = (l + r) >> 1, sum = 0;
    if (L <= mid) sum = max(sum, query(l, mid, rt << 1, L, R));
    if (R > mid) sum = max(sum, query(mid + 1, r, rt << 1 | 1, L, R));
    return sum;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    for (int i = 1;i <= n;i++) {
        if (b[i] > 1) dp[i] = query(1, n, 1, 1, b[i] - 1) + a[i];
        else dp[i] = a[i];
        update(1, n, 1, b[i], b[i], dp[i]);
    }
    int Max = 0;
    for (int i = 1;i <= n;i++) {
        Max = max(Max, dp[i]);
    }
    cout << Max;
    return 0;
}