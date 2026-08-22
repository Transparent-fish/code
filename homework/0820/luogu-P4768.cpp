#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int t, n, m, id, fa[N], dis[N], vis[N], dep[N], c[N];
int q, k, s, f[N][30];

struct node {
    int u, v, l, aa;
} a[N];

struct Node {
    int v, w;
    friend bool operator<(Node x, Node y) {
        return x.w > y.w;
    }
};
vector<Node>e[N];

struct Nodee {
    int val, l, r;
}tree[N << 1];

int find(int x) {
    if (fa[x] == x)return fa[x];
    else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)fa[fx] = fy;
}

bool cmp(node x, node y) {
    return x.aa > y.aa;
}

void dij() {
    fill(dis, dis + N, INT_MAX);
    memset(vis, 0, sizeof vis);
    priority_queue<Node> pq;
    dis[1] = 0;
    pq.push({ 1, 0 });
    for (;!pq.empty();) {
        int u = pq.top().v;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({ v,dis[v] });
            }
        }
    }
}

void dfs(int x, int fat) {
    f[x][0] = fat;
    dep[x] = dep[fat] + 1;
    for (int j = 1; j <= 20; j++) {
        f[x][j] = f[f[x][j - 1]][j - 1];
    }
    if (x <= n) {
        c[x] = dis[x];
        return;
    }
    dfs(tree[x].l, x);
    dfs(tree[x].r, x);
    c[x] = min(c[tree[x].l], c[tree[x].r]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    for (;t--;) {
        cin >> n >> m;
        id = n;
        for (int i = 1; i <= n * 2; i++) {
            fa[i] = i;
            e[i].clear();
            if (i <= n) {
                tree[i].val = 1e9;
            }
        }
        for (int i = 1; i <= m; i++) {
            int u, v, l, aa;
            cin >> u >> v >> l >> aa;
            a[i] = { u,v,l,aa };
            e[u].push_back({ v,l });
            e[v].push_back({ u,l });
        }
        sort(a + 1, a + m + 1, cmp);
        dij();
        for (int i = 1;i <= m;i++) {
            int fu = find(a[i].u), fv = find(a[i].v);
            if (fu != fv) {
                id++;
                tree[id].val = a[i].aa, tree[id].l = fu, tree[id].r = fv;
                fa[id] = fa[fu] = fa[fv] = id;
            }
        }
        dfs(id, 0);
        cin >> q >> k >> s;
        int la = 0;
        for (;q--;) {
            int v0, p0, dv, dp;
            cin >> v0 >> p0;
            dv = (v0 + k * la - 1) % n + 1, dp = (p0 + k * la) % (s + 1);
            for (int i = 20;i >= 0;i--) {
                if (f[dv][i] != 0 && tree[f[dv][i]].val > dp) {
                    dv = f[dv][i];
                }
            }
            la = c[dv];
            cout << la << "\n";
        }
    }
    return 0;
}