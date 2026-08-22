#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, mod = 9999973;
int n, m, f[N][N], g[N][N];

signed main() {
    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 0;i < n;i++) {
        memset(g, 0, sizeof g);
        for (int j = 0;j <= m;j++) {
            for (int k = 0;k + j <= m;k++) {
                if (!f[j][k])continue;
                int z = m - j - k, v = f[j][k];
                g[j][k] += v % mod;
                if (z >= 1) g[j + 1][k] = (g[j + 1][k] + v * z) % mod;
                if (j >= 1) g[j - 1][k + 1] = (g[j - 1][k + 1] + v * j) % mod;
                if (z >= 2) g[j + 2][k] += (v * z * (z - 1) / 2) % mod;
                if (j >= 2) g[j - 2][k + 2] += (v * j * (j - 1) / 2) % mod;
                if (z >= 1 && j >= 1) g[j][k + 1] = (g[j][k + 1] + v * z * j) % mod;
            }
        }
        memcpy(f, g, sizeof(f));
    }
    int ans = 0;
    for (int i = 0;i <= m;i++) {
        for (int j = 0;i + j <= m;j++) {
            ans = (ans + f[i][j]) % mod;
        }
    }
    cout << ans;
    return 0;
}

// @pid 111 @tid 6a6c7f23bdb36af2d80fa4cd @lang cc.cc14o2
