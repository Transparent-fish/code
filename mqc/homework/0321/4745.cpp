#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, res, f[N], siz[N], dis[N];
vector<int>e[N];

void dfs(int x, int fa) {
    siz[x] = 1;
    for (auto c : e[x]) {
        if (c == fa)continue;
        dis[c] = dis[x] + 1;
        dfs(c, x);
        siz[x] += siz[c];
    }
}

void dfs1(int x, int fa) {
    for (auto c : e[x]) {
        if (c == fa)continue;
        f[c] = f[x] - siz[c] + (n - siz[c]);
        dfs1(c, x);
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1;i <= n; i++) {
        f[1] += dis[i];
    }
    dfs1(1, 0);
    for (int i = 1;i <= n;i++) {
        cout << f[i] << " ";
    }
    return 0;
}