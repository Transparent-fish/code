#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, x, pan;
int a[N], cnt[3];

struct node {
    int l, r;
    mutable int v;
    friend bool operator<(node a, node b) { return a.l < b.l; }
};
set<node> s;

auto split(int pos) {
    auto it = s.lower_bound({ pos, 0, 0 });
    if (it != s.end() && it->l == pos) {
        return it;
    }
    it--;
    int l = it->l, r = it->r, v = it->v;
    s.erase(it);
    s.insert({ l, pos - 1, v });
    return s.insert({ pos, r, v }).first;
}

void query(int l, int r) {
    auto itr = split(r + 1), itl = split(l);
    auto tmp = itl;
    cnt[0] = cnt[1] = cnt[2] = 0;
    for (; itl != itr; itl++) {
        cnt[itl->v] += (itl->r - itl->l + 1);
    }
    s.erase(tmp, itr);
}

signed main() {
    cin >> n >> m >> x;
    s.insert({ 0, 0, 0 }), s.insert({ n + 1, n + 1, 0 });
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == x) a[i] = 1;
        else if (a[i] < x) a[i] = 0;
        else a[i] = 2;
        s.insert({ i, i, a[i] });
    }
    for (; m--;) {
        int opt, l, r;
        cin >> opt >> l >> r;
        query(l, r);
        if (opt == 1) {
            if (cnt[0]) { s.insert({ l, l + cnt[0] - 1, 0 });l += cnt[0]; }
            if (cnt[1]) { s.insert({ l, l + cnt[1] - 1, 1 });l += cnt[1]; }
            if (cnt[2]) { s.insert({ l, l + cnt[2] - 1, 2 });l += cnt[2]; }
        }
        else {
            if (cnt[2]) { s.insert({ l, l + cnt[2] - 1, 2 });l += cnt[2]; }
            if (cnt[1]) { s.insert({ l, l + cnt[1] - 1, 1 });l += cnt[1]; }
            if (cnt[0]) { s.insert({ l, l + cnt[0] - 1, 0 }); l += cnt[0]; }
        }
    }
    for (auto i : s) {
        if (i.v == 1) cout << i.l << " ";
    }
    return 0;
}