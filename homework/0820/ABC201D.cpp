#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2005;
int n, m, a[N][N], f[N][N];

void scan() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        for (int j = 1;j <= m;j++) {
            a[i][j] = (s[j - 1] == '-' ? -1 : 1);
        }
    }
}

void print() {
    f[n][m] = 0;
    for (int i = n;i >= 1;i--) {
        for (int j = m;j >= 1;j--) {
            if (i == n && j == m) continue;
            int now = -1e18;
            if (i < n) now = max(now, a[i + 1][j] - f[i + 1][j]);
            if (j < m) now = max(now, a[i][j + 1] - f[i][j + 1]);
            f[i][j] = now;
        }
    }
    if (f[1][1] > 0) puts("Takahashi");
    if (f[1][1] < 0) puts("Aoki");
    if (f[1][1] == 0) puts("Draw");
}

signed main() {
    scan(), print();
    return 0;
}