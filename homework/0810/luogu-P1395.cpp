#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt = 1, siz[N], f[N], dep[N];
vector<int>e[N];

void dfs(int x, int fa) {
    int Max = 0, tmp = 0;
    siz[x] = 1;
    for (auto v : e[x]) {
        if (v == fa)continue;
        dep[v] = dep[x] + 1;
        dfs(v, x);
        siz[x] += siz[v], tmp += siz[v];
        Max = max(Max, siz[v]);
    }
}
void dfs1(int x, int fa) {
    for (auto v : e[x]) {
        if (v == fa) continue;
        f[v] = f[x] + n - 2 * siz[v];
        dfs1(v, x);
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
    for (int i = 1;i <= n;i++) {
        f[1] += dep[i];
    }
    dfs1(1, 0);
    for (int i = 2;i <= n;i++) {
        if (f[i] < f[cnt])cnt = i;
    }
    cout << cnt << " " << f[cnt];
    return 0;
}

// @pid 170 @tid 6a7836f3f80e134e7821926a @lang cc.cc14o2
