#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt, sum, res, ned, ans, fa[N];

struct node {
    int sta, end, v, cor;
    friend bool operator<(node a, node b) {
        if (a.v == b.v) return a.cor < b.cor;
        else return a.v < b.v;
    }
}e[N];

int find(int x) {
    if (fa[x] == x)return fa[x];
    return fa[x] = find(fa[x]);
}

void kruskal() {
    sort(e + 1, e + m + 1);
    for (int i = 1;cnt != n - 1;i++) {
        int fx = find(e[i].sta), fy = find(e[i].end);
        if (fx != fy) {
            cnt++;
            fa[fx] = fy;
            if (e[i].cor == 0) res++;
            sum += e[i].v;
        }
    }
}

void init() {
    for (int i = 1;i <= n;i++)fa[i] = i;
    sum = cnt = res = 0;
}

signed main() {
    cin >> n >> m >> ned;
    for (int i = 1;i <= m;i++) {
        cin >> e[i].sta >> e[i].end >> e[i].v >> e[i].cor;
        e[i].sta++, e[i].end++;
    }
    int l = -101, r = 1e9;
    for (;l <= r;) {
        int mid = l + r >> 1;
        for (int i = 1;i <= m;i++) {
            if (e[i].cor == 0)e[i].v += mid;
        }
        init(), kruskal();
        if (res >= ned) {
            l = mid + 1, ans = sum - ned * mid;
        }
        else {
            r = mid - 1;
        }
        for (int i = 1;i <= m;i++) {
            if (e[i].cor == 0) e[i].v -= mid;
        }
    }
    cout << ans;
    return 0;
}