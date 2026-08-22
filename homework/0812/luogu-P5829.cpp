#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int m, j, tot, nex[N], dep[N], fa[N], f[N][30];
string s;
vector<int>e[N];

void dfs(int x, int fa, int deep) {
    dep[x] = deep, f[x][0] = fa;
    for (int j = 1; j <= 20; j++) {
        f[x][j] = f[f[x][j - 1]][j - 1];
    }
    for (auto v : e[x]) {
        if (v == fa) continue;
        dfs(v, x, deep + 1);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int j = 20; j >= 0; j--) {
        if (dep[f[y][j]] >= dep[x]) {
            y = f[y][j];
        }
    }
    if (x == y) return x;
    for (int j = 20; j >= 0; j--) {
        if (f[x][j] != f[y][j]) {
            x = f[x][j], y = f[y][j];
        }
    }
    return f[x][0];
}

signed main() {
    cin >> s >> m;
    s = "$" + s;
    for (int i = 2;i < s.size();i++) {
        for (;j > 0 && s[j + 1] != s[i];) j = nex[j];
        if (s[j + 1] == s[i]) j++;
        nex[i] = j;
    }
    for (int i = 1;i < s.size();i++) {
        fa[i] = nex[i], e[nex[i]].push_back(i);
    }
    dfs(0, 0, 1);
    for (;m--;) {
        int p, q, Lca;
        cin >> p >> q;
        Lca = lca(p, q);
        if (Lca == p || Lca == q)cout << nex[p] << "\n";
        else cout << Lca << "\n";
    }
    return 0;
}