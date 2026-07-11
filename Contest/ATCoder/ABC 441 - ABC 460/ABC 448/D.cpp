#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cntt, a[N];
bool vis[N];
vector<int>e[N];
map<int, int>cnt;

void dfs(int u, int fa) {
    cnt[a[u]]++;
    if (cnt[a[u]] == 2)cntt++;
    if (cntt > 0)vis[u] = 1;
    else vis[u] = 0;
    for (auto c : e[u]) {
        if (c != fa)dfs(c, u);
    }
    if (cnt[a[u]] == 2) cntt--;
    cnt[a[u]]--;
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
    dfs(1, 0);
    for (int i = 1;i <= n;i++) {
        if (vis[i])cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}