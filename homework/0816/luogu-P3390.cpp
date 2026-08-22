#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105, mod = 1e9 + 7;
int n, k, a[N][N], c[N][N], now[N][N];

void js() {
    memset(now, 0, sizeof(now));
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                now[i][j] = (now[i][j] + c[i][k] * a[k][j]) % mod;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            c[i][j] = now[i][j];
            c[i][j] %= mod;
        }
    }
}

void jss() {
    memset(now, 0, sizeof(now));
    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                now[i][j] = (now[i][j] + a[i][k] * a[k][j]) % mod;
            }
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            a[i][j] = now[i][j];
            a[i][j] %= mod;
        }
    }
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        c[i][i] = 1;
    }
    for (;k;) {
        if (k & 1) js();
        jss();
        k >>= 1;
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << c[i][j] % mod << " ";
        }
        cout << "\n";
    }
    return 0;
}