#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Max, f[N], d[N], d2[N];
vector<int>e[N];

void dfs(int x, int fa) {
    for (auto v : e[x]) {
        if (v == fa) continue;
        dfs(v, x);
        if (d[v] + 1 > d[x]) {
            d2[x] = d[x], d[x] = d[v] + 1;
        }
        else if (d[v] + 1 > d2[x]) {
            d2[x] = d[v] + 1;
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        Max = max(Max, d[i] + d2[i]);
    }
    cout << Max;
    return 0;
}