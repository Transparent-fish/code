#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e8 - 3;
int n, m, res, tree[N], c[N], now[N], id[N];

struct node {
    int v, id;
    friend bool operator<(node a, node b) {
        return a.v < b.v;
    }
}a[N], b[N];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int c) {
    for (int i = x; i <= n; i += (i & -i)) tree[i] += c;
}

int query(int x) {
    int res = 0;
    for (int i = x; i >= 1; i -= (i & -i)) {
        res += tree[i];
    }
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].v;
        a[i].id = i;
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i].v;
        b[i].id = i;
    }
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
    for (int i = 1;i <= n;i++) {
        now[a[i].id] = b[i].id;
    }
    memcpy(c, now, sizeof c), sort(c + 1, c + n + 1);
    for (int i = 1;i <= n;i++) {
        id[i] = lower_bound(c + 1, c + n + 1, now[i]) - c;
    }
    for (int i = 1; i <= n; i++) {
        res += query(n) - query(id[i]);
        res %= mod;
        update(id[i], 1);
    }
    cout << res % mod;
    return 0;
}