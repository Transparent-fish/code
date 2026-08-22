#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, a[N], tree1[N], tree2[N];

int lb(int x) {
    return x & (-x);
}

void add(int x, int c, int who) {
    for (int i = x;i <= n;i += lb(i)) {
        if (who == 1) tree1[i] += c;
        else tree2[i] += c;
    }
}

int ask(int x, int who) {
    int now = 0;
    for (int i = x;i >= 1;i -= lb(i)) {
        if (who == 1) now += tree1[i];
        else now += tree2[i];
    }
    return now;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        add(i, a[i], 1), add(i, a[i] * i, 2);
    }
    for (;m--;) {
        string s;
        cin >> s;
        if (s == "Query") {
            int x;
            cin >> x;
            cout << (x + 1) * ask(x, 1) - ask(x, 2) << "\n";
        }
        else {
            int x, y;
            cin >> x >> y;
            add(x, y - a[x], 1), add(x, (y - a[x]) * x, 2);
            a[x] = y;
        }
    }
    return 0;
}