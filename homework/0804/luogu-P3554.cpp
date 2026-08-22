#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], f[N];
vector<int>e[N];

void dfs(int u, int fa, int mid) {
    int sum = 0;
    for (auto c : e[u]) {
        if (c == fa)continue;
        dfs(c, u, mid);
        sum += f[c] + 1;
    }
    f[u] = max(sum - mid, 0LL);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1;i < n;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int l = 1, r = n - 1, ans = 0;
    for (;l <= r;) {
        int mid = l + r >> 1;
        memset(f, 0, sizeof f);
        dfs(1, 0, mid);
        if (!f[1])r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}