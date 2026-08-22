#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5, V = 1e8 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n, m, tot, rt, a[N], siz[N], Max[N], vis[N];
int cnt, ed, dis[N], viss[N], had[N], que[N];
vector<pair<int, int>>e[N];

void dfs(int x, int fa, int d) {
    dis[++cnt] = d;
    for (auto c : e[x]) {
        int v = c.first, w = c.second;
        if (vis[v] || v == fa) continue;
        dfs(v, x, d + w);
    }
}

void getRoot(int u, int fa) {
    siz[u] = 1, Max[u] = 0;
    for (auto c : e[u]) {
        int v = c.first;
        if (v == fa || vis[v]) continue;
        getRoot(v, u);
        siz[u] += siz[v];
        Max[u] = max(Max[u], siz[v]);
    }
    Max[u] = max(Max[u], tot - siz[u]);
    if (Max[u] < Max[rt]) rt = u;
}

void getAns(int u) {
    had[0] = 1;
    ed = 0;
    for (auto c : e[u]) {
        int v = c.first, w = c.second;
        if (vis[v]) continue;
        cnt = 0;
        dfs(v, u, w);
        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[j] >= dis[i]) viss[j] |= had[a[j] - dis[i]];
            }
        }
        for (int i = 1; i <= cnt; i++) {
            had[dis[i]] = 1;
            que[++ed] = dis[i];
        }
    }
    for (int i = 1; i <= ed; i++) had[que[i]] = 0;
}

void divide(int u) {
    vis[u] = 1;
    getAns(u);
    for (auto c : e[u]) {
        int v = c.first;
        if (vis[v]) continue;
        tot = siz[v];
        rt = 0;
        getRoot(v, u), getRoot(rt, 0), divide(rt);
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({ v, w });
        e[v].push_back({ u, w });
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    Max[rt = 0] = inf, tot = n;
    getRoot(1, 0), getRoot(rt, 0), divide(rt);
    for (int i = 1; i <= m; i++) {
        cout << (viss[i] ? "AYE\n" : "NAY\n");
    }
    return 0;
}