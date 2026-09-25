#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25;
int a, b, c, f[N][N][N];

int dfs(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return dfs(20, 20, 20);
    if (f[a][b][c] != -1) return f[a][b][c];
    int res = 0;
    if (a < b && b < c) {
        res = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
        f[a][b][c] = res;
    }
    else {
        res = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
        f[a][b][c] = res;
    }
    return res;
}

signed main() {
    memset(f, -1, sizeof(f));
    for (;cin >> a >> b >> c;) {
        if (a == b && b == c && c == -1) {
            exit(0);
        }
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
    }
    return 0;
}