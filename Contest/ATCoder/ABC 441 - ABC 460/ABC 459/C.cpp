#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 600005;
int n, q, now, tree[M], a[M];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int c) {
    if (x <= 0) return;
    for (int i = x; i < M; i += lowbit(i)) tree[i] += c;
}

int query(int x) {
    int sum = 0;
    if (x >= M) x = M - 1;
    for (int i = x; i >= 1; i -= lowbit(i)) sum += tree[i];
    return sum;
}

signed main() {
    cin.tie(0);
    cin >> n >> q;
    update(1, n);
    for (;q--;) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
            update(a[x] + 1, -1);
            a[x]++;
            update(a[x] + 1, 1);
            if (query(now + 1) - query(now) == 0) now++;
        }
        else {
            cin >> x;
            cout << query(M - 1) - query(x + now) << "\n";
        }
    }
    return 0;
}