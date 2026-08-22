#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans, cnt, siz[N], fa[N];

struct node {
    int u, v, w;
    friend bool operator<(node a, node b) {
        return a.w < b.w;
    }
}e[N];

void init() {
    for (int i = 1;i <= n;i++) {
        fa[i] = i;
    }
}

int find(int x) {
    if (fa[x] == x)return fa[x];
    return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)fa[fx] = fy;
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1), init();
    for (int i = 1; i <= m; i++) {
        if (find(e[i].u) != find(e[i].v)) {
            cnt++, ans += e[i].w;
            fa[find(e[i].u)] = find(e[i].v);
        }
    }
    if (cnt == n - 1) cout << ans;
    else cout << "orz";
    return 0;
}

// @pid 174 @tid 6a7836f3f80e134e7821926a @lang cc.cc14o2
