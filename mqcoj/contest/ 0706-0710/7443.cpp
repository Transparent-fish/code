#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], ans[N], dep[N], fa[N][20];
vector<int>e[N];

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) {
        if (dep[x] - (1 << i) >= dep[y]) x = fa[x][i];
    }
    if (x == y) return y;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    }
    return fa[x][0];
}


void dfs(int x) {
    for (auto c : e[x]) {
        if (c == fa[x][0])continue;
        dfs(c);
        ans[x] += ans[c];
    }
}

void bfs() {
    queue<int>q;
    q.push(1);
    dep[1] = 1;
    for (;!q.empty();) {
        auto now = q.front();
        q.pop();
        for (auto c : e[now]) {
            if (dep[c] != 0)continue;
            dep[c] = dep[now] + 1, fa[c][0] = now;
            q.push(c);
        }
    }
    for (int j = 1;j <= 19;j++) {
        for (int i = 1;i <= n;i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs();
    for (int i = 1;i < n;i++) {
        ans[a[i]]++, ans[a[i + 1]]++;
        ans[lca(a[i], a[i + 1])]--, ans[fa[lca(a[i], a[i + 1])][0]]--;
    }
    dfs(1);
    for (int i = 2;i <= n;i++)ans[a[i]]--;
    for (int i = 1;i <= n;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}