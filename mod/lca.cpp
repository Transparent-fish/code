#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, s, tot;
int a[N], siz[N], dep[N], top[N], son[N], fa[N], V[N], id[N];
vector<int>e[N];

void dfs(int x, int f) {
    fa[x] = f, siz[x] = 1, dep[x] = dep[f] + 1;
    int Max = 0;
    for (auto c : e[x]) {
        if (c == f)continue;
        dfs(c, x);
        siz[x] += siz[c];
        if (siz[c] > Max) Max = siz[c], son[x] = c;
    }
}

void dfs1(int x, int topfa) {
    top[x] = topfa;
    id[x] = ++tot, V[tot] = a[x];
    if (!son[x])return;
    dfs1(son[x], topfa);
    for (auto c : e[x]) {
        if (c == fa[x] || c == son[x])continue;
        dfs1(c, c);
    }
}

int lca(int x, int y) {
    for (;top[x] != top[y];) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    return x;
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(s, 0), dfs1(s, s);
    for (;m--;) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}

// @pid 172 @tid 6a7836f3f80e134e7821926a @lang cc.cc14o2
