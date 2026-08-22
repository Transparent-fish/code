#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, q, ans;

struct node {
    int l, r;
    mutable int v; node(int _l, int _r = -1, int _v = 0) :l(_l), r(_r), v(_v) {}
    friend bool operator<(node a, node b) {
        return a.l < b.l;
    }
};
set<node>s;

auto split(int pos) {
    if (pos > n)return s.end();
    auto it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos)return it;
    --it;
    int l = it->l, r = it->r, v = it->v;s.erase(it);
    s.insert(node(l, pos - 1, v));
    return s.insert(node(pos, r, v)).first;
}

void assign(int l, int r, int v) {
    auto itr = split(r + 1), itl = split(l);
    for (auto it = itl;it != itr;it++) {
        if (it->v == 1)ans -= (it->r - it->l + 1);
    }
    s.erase(itl, itr), s.insert(node(l, r, v));
    if (v == 1)ans += (r - l + 1);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    s.insert(node(1, n, 1));
    ans = n;
    for (;q--;) {
        int op, l, r;
        cin >> l >> r >> op;
        if (op == 1) assign(l, r, 0);
        else assign(l, r, 1);
        cout << ans << "\n";
    }
    return 0;
}
