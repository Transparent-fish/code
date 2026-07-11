#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int n, m, rt, f[N];
struct node { int u, v, w; } a[N * 5];
struct nodee { int v, w; };
vector<nodee> e[N];
int fa[N][21], dep[N], g[N][21];

bool cmp(node a, node b) {
    return a.w > b.w;
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y); if (fx != fy) f[fx] = fy;
}

void bfs() {
    queue<int> q;
    dep[rt] = 1;
    fa[rt][0] = 0;
    g[rt][0] = 0;
    q.push(rt);
    for (;!q.empty();) {
        int u = q.front(); q.pop();
        for (auto c : e[u]) {
            int v = c.v, w = c.w;
            if (dep[v] != -1) continue;
            dep[v] = dep[u] + 1;
            fa[v][0] = u, g[v][0] = w;
            q.push(v);
        }
    }
}

int lca(int x, int y) {
    int res = 1e18;
    if (dep[x] > dep[y]) swap(x, y);
    for (int j = 20; j >= 0; j--) {
        if (dep[fa[y][j]] >= dep[x]) {
            res = min(res, g[y][j]), y = fa[y][j];
        }
    }
    if (x == y) return res;
    for (int j = 20; j >= 0; j--) {
        if (fa[x][j] != fa[y][j]) {
            res = min(res, g[x][j]), res = min(res, g[y][j]);
            x = fa[x][j], y = fa[y][j];
        }
    }
    res = min(res, min(g[x][0], g[y][0]));
    return res;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++) {
        int u = a[i].u, v = a[i].v, w = a[i].w;
        if (find(u) != find(v)) {
            merge(u, v);
            e[u].push_back({ v, w });
            e[v].push_back({ u, w });
        }
    }
    memset(dep, -1, sizeof dep);
    for (int i = 1; i <= n; i++) {
        if (dep[i] == -1) rt = i; bfs();
    }
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            g[i][j] = min(g[i][j - 1], g[fa[i][j - 1]][j - 1]);
        }
    }
    cin >> m;
    for (; m--;) {
        int u, v; cin >> u >> v;
        if (find(u) != find(v)) cout << -1 << "\n";
        else cout << lca(u, v) << "\n";
    }
    return 0;
}

// @pid 6048 @tid 6a4de16add325655d82dc196 @lang cc.cc17o2
