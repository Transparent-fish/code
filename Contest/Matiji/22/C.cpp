#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, l, a[N], b[N];
int tree[N], tree1[N];

int lowbit(int x) {
    return x & -x;
}

void update(int x, int y) {
    for (int i = x;i <= n;i += lowbit(i))tree[i] += y;
}

int query(int x) {
    int sum = 0;
    for (int i = x;i >= 1;i -= lowbit(i))sum += tree[i];
    return sum;
}

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }
    for (int i = 1;i <= n;i++) {
        
    }
    for (;q--;) {
        int x, y;
        cin >> x >> y;
        update(x, y);
    }
    return 0;
}