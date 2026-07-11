#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt, vis[N];
vector<int>e[N];

void bfs() {
    queue<int>q;
    q.push(1);
    vis[1] = 1;
    for (;!q.empty();) {
        int now = q.front();
        q.pop();
        cnt++;
        for (auto i : e[now]) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    bfs();
    cout << cnt << "\n";
    return 0;
}