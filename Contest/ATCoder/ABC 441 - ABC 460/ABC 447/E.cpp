#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 998244353;
int n, m, now, fa[N], a[N], b[N];

struct node {
    int u, v, w;
} e[N];

struct nodee {
    int to, w;
};
vector<nodee> ee[N];

int find(int x) {
    if (fa[x] == x) return fa[x];
    return fa[x] = find(fa[x]);
}

void init() {
    a[0] = 1;
    for (int i = 1; i <= m; i++) { a[i] = (a[i - 1] * 2) % mod; }
    for (int i = 1; i <= n; i++) { fa[i] = i; }
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
        e[i].w = i;
    }
    init();
    for (int i = m; i >= 1; i--) {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx != fy) {
            fa[fx] = fy;
            ee[e[i].u].push_back({ e[i].v, i });ee[e[i].v].push_back({ e[i].u, i });
            now = i;
        }
    }
    queue<int> q;
    q.push(e[now].u);
    b[e[now].u] = 1;
    for (;!q.empty();) {
        int u = q.front();
        q.pop();
        for (auto i : ee[u]) {
            if (i.w == now) continue;
            if (!b[i.to]) {
                b[i.to] = 1;
                q.push(i.to);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (b[e[i].u] != b[e[i].v]) {
            ans = (ans + a[i]) % mod;
        }
    }
    cout << ans;
    return 0;
}