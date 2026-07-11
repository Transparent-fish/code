#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, ans[N];

struct node {
    int u, w;
};
vector<node>e[N];

void dfs(int x, int fa) {
    ans[x] = fa;
    for (auto c : e[x]) {
        if (ans[c.u] != 0)continue;
        dfs(c.u, fa ^ c.w);
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({ v,w });
        e[v].push_back({ u,w });
    }
    cin >> q;
    dfs(1, 0);
    for (;q--;) {
        int u, v;
        cin >> u >> v;
        cout << (ans[u] ^ ans[v]) << "\n";
    }
    return 0;
}