#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 9;
int n, m, in, ra;

struct node {
    int l, r;
    mutable int v, sum;
    friend bool operator<(node a, node b) {
        return a.l < b.l;
    }
};
set<node>s;

int fpow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1ll * ans * a % mod;
        }
        b >>= 1, a = 1ll * a * a % mod;
    }
    return ans;
}

int Sum(int l) {
    if (l <= 0) return 0;
    if (l == 1) return 1;
    int pw = fpow(ra, l);
    return (1 - pw + mod) % mod * in % mod;
}


auto split(int pos) {
    if (pos > n) return s.end();
    auto it = s.lower_bound({ pos });
    if (it != s.end() && it->l == pos) return it;
    --it;
    int l = it->l, r = it->r, v = it->v, sum = it->sum;
    if (pos == l) return it;
    int len = pos - l;
    int now = 0, left = 0;
    if (v != 0) {
        now = v * fpow(ra, len) % mod;
        left = v * Sum(len) % mod;
    }
    int right = (sum - left + mod) % mod;
    s.erase(it);
    s.insert({ l, pos - 1, v, left });
    return s.insert({ pos, r, now, right }).first;
}


void assign(int l, int r, int v) {
    auto itr = split(r + 1), itl = split(l);
    s.erase(itl, itr), s.insert({ l, r, v, v * Sum(r - l + 1) % mod });
}

int ask(int l, int r) {
    int sum = 0;
    auto it = s.upper_bound({ l });
    --it;
    for (;it != s.end() && it->l <= r;it++) {
        int L = max(l, it->l), R = min(r, it->r);
        if (L <= R) {
            if (L == it->l && R == it->r) {
                sum += it->sum;
            }
            else {
                int now = it->v;
                int noow = L - it->l;
                if (now != 0) {
                    if (noow > 0) now = now * fpow(ra, noow) % mod;
                    if (now != 0) sum += now * Sum(R - L + 1) % mod;
                }
            }
            sum %= mod;
        }
    }
    return sum;
}

signed main() {
#ifdef __linux__
    freopen("series.in", "r", stdin);
    freopen("series.out", "w", stdout);
#endif
    cin >> n >> m;
    int las = 0;
    ra = 2 * fpow(5, mod - 2) % mod;
    in = fpow((1 - ra + mod) % mod, mod - 2);
    s.insert({ 1, n, 0, 0 });
    for (;m--;) {
        int l, r, op, v, p;
        cin >> op >> l >> r;
        l ^= las, r ^= las;
        if (op == 1) {
            cin >> v >> p;
            v *= fpow(ra, p) % mod;
            v %= mod;
            assign(l, r, v);
        }
        else {
            int now = ask(l, r);
            cout << now << "\n";
            las = now;
        }
    }
    return 0;
}