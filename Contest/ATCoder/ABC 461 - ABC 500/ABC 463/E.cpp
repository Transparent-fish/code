#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, y, dis[N], vis[N];

struct node {
    int u, w;
};
vector<node>e[N << 1];

void dij() {
    priority_queue<pair<int, int>> q;
    q.push({ 0,1 });
    dis[1] = 0;
    for (;!q.empty();) {
        int now = q.top().second;
        q.pop();
        if (!vis[now]) {
            vis[now] = 1;
            for (auto [v, w] : e[now]) {
                if (dis[v] > dis[now] + w) {
                    dis[v] = dis[now] + w;
                    q.push({ -dis[v],v });
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m >> y;
    for (int i = 1;i <= m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({ v,w });
        e[v].push_back({ u,w });
    }
    int now = (n << 1) + 1;
    for (int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        e[i].push_back({ now,x + y });
        e[now].push_back({ i, x });
    }
    for (int i = 1;i <= now;i++) {
        dis[i] = LLONG_MAX;
    }
    dij();
    for (int i = 2;i <= n;i++) {
        cout << dis[i] << " ";
    }
    return 0;
}