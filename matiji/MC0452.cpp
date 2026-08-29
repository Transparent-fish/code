#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, fa[N];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    for (;m--;) {
        int op, x, y, fx, fy;
        cin >> op >> x >> y;
        fx = find(x), fy = find(y);
        if (op == 1) fa[fx] = fy;
        else cout << (fx == fy ? "YES\n" : "NO\n");
    }
    return 0;
}