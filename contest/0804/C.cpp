#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, m, q, cnt, num, dfn[N], low[N], siz[N], st[N][30], b[N];
stack<int>sk;
vector<int>e[N], g[N];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    sk.push(u);
    for (auto c : e[u]) {
        if (!dfn[c]) tarjan(c, u), low[u] = min(low[u], low[c]);
        else if (c != fa) low[u] = min(low[u], dfn[c]);
    }
    if (dfn[u] == low[u]) {
        int v = 0;
        for (;v != u;) {
            v = sk.top();sk.pop();
            b[v] = u, siz[u]++;
        }
    }
}

void dfs(int x, int fa) {

}

int lca(int u, int v) {
    if (u == v) return u;
    u = dfn[u], v = dfn[v];
    if (u > v) swap(u, v);
    int dis = log2(v - u);u++;
    return min(st[dis][u], st[dis][v - (1 << dis) + 1]);
}

void input() {
    cin >> n >> m >> q;
    for (int i = 1;i <= max(n, m);i++) {
        e[i].clear(), g[i].clear();
        dfn[i] = low[i] = 0;
        cnt = num = 0;
        for (int j = 0;j <= 30;j++) {
            st[i][j] = 0;
        }
    }
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1;i <= q;i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
}

void solve() {
    input(), tarjan(1, 0);
}

signed main() {
#ifdef __linux__
    freopen("confluere.in", "r", stdin);
    freopen("confluere.out", "w", stdout);
#endif
    cin >> T;
    for (;T--;) {
        solve();
    }
    return 0;
}