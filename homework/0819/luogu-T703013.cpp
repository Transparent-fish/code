#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, son[N], fa[N];
vector<int>e[N];

void dfs(int x, int f) {
    for (auto c : e[x]) {
        if (c == fa[x])continue;
        son[x] = c;
        dfs(c, x);
    }
}

signed main() {
    cin >> n;
    for (int i = 2;i <= n;i++) {
        cin >> fa[i];
        son[i] = 1;
    }
    for (int i = n;i >= 2;i--) {
        son[fa[i]] += son[i];
    }
    cnt = (n - 1) * (n - 1);
    for (int i = 2;i <= n;i++) {
        if (fa[i] == 1) {
            cnt += son[i] * son[i];
            // cout << cnt << " " << i << " ";
        }
    }
    cout << cnt;
    return 0;
}