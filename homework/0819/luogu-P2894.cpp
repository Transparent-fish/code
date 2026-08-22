#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
set<int> rec;

struct node {
    int l, r;
    mutable int v; node(int _l, int _r = -1, int _v = 0) :l(_l), r(_r), v(_v) {}
    friend bool operator<(node a, node b) {
        return a.l < b.l;
    }
};
set<node>s;

auto split(int pos) {
    auto it = s.lower_bound(node(pos, 0, 0));
    if (it != s.end() && it->l == pos) {
        return it;
    }
    it--;
    int l = it->l, t = it->r, v = it->v;
    s.erase(it), s.insert(node(l, pos - 1, v));
    return s.insert(node(pos, t, v)).first;
}

void assign(int l, int r, int v) {
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr);
    auto it = s.insert(node(l, r, v)).first;
    auto nx = next(it);
    if (nx != s.end() && nx->v == v) {
        r = nx->r;
        s.erase(nx), s.erase(it);
        it = s.insert(node(l, r, v)).first;
    }
    if (it != s.begin()) {
        auto pv = prev(it);
        if (pv->v == v) {
            l = pv->l;
            s.erase(pv), s.erase(it);
            s.insert(node(l, r, v));
        }
    }
}

int query(int x) {
    int ans = 0, st = -1, now = 0;
    for (auto it = s.begin(); it != s.end(); it++) {
        int len = it->r - it->l + 1;
        if (it->v == 0) {
            if (now == 0) st = it->l;
            now += len;
            if (now >= x) {
                ans = st;
                break;
            }
        }
        else {
            now = 0;
            st = -1;
        }
    }
    if (ans != 0) {
        assign(ans, ans + x - 1, 1);
        rec.clear();
    }
    else {
        rec.insert(x);
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    s.insert(node{ 1,n,0 });
    for (;m--;) {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) {
            if (rec.find(x) != rec.end()) {
                cout << 0 << "\n";
                continue;
            }
            cout << query(x) << "\n";
        }
        else {
            cin >> y;
            assign(x, x + y - 1, 0);
            rec.clear();
        }
    }
    return 0;
}