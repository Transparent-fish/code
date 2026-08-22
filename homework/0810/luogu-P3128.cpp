#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, tot, Max, fa[N], siz[N], dep[N];
int top[N], V[N], son[N], id[N], a[N], s[N];
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

void dfs2(int x, int fa) {
    for (auto c : e[x]) {
        if (c == fa) continue;
        dfs2(c, x);
        s[x] += s[c];
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
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0), dfs1(1, 1);
    for (int i = 1;i <= k;i++) {
        int u, v;
        cin >> u >> v;
        s[u]++, s[v]++, s[lca(u, v)]--, s[fa[lca(u, v)]]--;
    }
    dfs2(1, 0);
    for (int i = 1;i <= n;i++) {
        Max = max(Max, s[i]);
    }
    cout << Max;
    return 0;
}

// @pid 176 @tid 6a7836f3f80e134e7821926a @lang cc.cc14o2
