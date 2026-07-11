#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt;
bool vis[N], viss[N];

struct node {
    int u, v;
}a[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].u >> a[i].v;
    }
    for (int i = m;i >= 1;i--) {
        if (!vis[a[i].u] && !viss[a[i].v])cnt++;
        vis[a[i].u] = 1, viss[a[i].v] = 1;
    }
    cout << cnt;
    return 0;
}