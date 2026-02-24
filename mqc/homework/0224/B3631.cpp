#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int q, cnt, nex[N], a[N];
map<int, int>mp;

void insert(int x, int y) {
    a[++cnt] = y, nex[cnt] = nex[mp[x]], nex[mp[x]] = cnt, mp[y] = cnt;
}

int query(int x) {
    return a[nex[mp[x]]];
}

void del(int x) {
    mp[a[nex[mp[x]]]] = 0;
    nex[mp[x]] = nex[nex[mp[x]]];
}

signed main() {
    cin >> q;
    for (;q--;) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            cin >> y;
            insert(x, y);
        }
        else if (op == 2) {
            cout << query(x) << "\n";
        }
        else {
            del(x);
        }
    }
    return 0;
}