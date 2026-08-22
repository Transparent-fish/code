#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int n, mod, tot, fa[N], in[N], d[N], p[N];
bool vis[N];

void init() {
    for (int i = 2;i <= 2e6;i++) {
        if (!vis[i])p[++tot] = i;
        for (int j = 1;j <= tot;j++) {
            if (i * p[j] > 2e6)break;
            vis[i * p[j]] = 1;
            if (i % p[j] == 0)break;
        }
    }
}

int Get(int n, int p) {
    int ans = 0;
    while (n) {
        n /= p;
        ans += n;
    }
    return ans;
}

int fastpow(int a, int b) {
    if (b == 0)return 1;
    int c = fastpow(a, b / 2);
    if (b % 2 == 0)return c * c % mod;
    return c * c % mod * a % mod;
}

int inv(int x) {
    return fastpow(x, mod - 2) % mod;
}

int C(int x, int y) {
    int ans = 1;
    for (int i = 1;i <= tot;i++) {
        if (p[i] > x)break;
        int tmp = Get(x, p[i]) - Get(y, p[i]) - Get(x - y, p[i]);
        if (tmp > 0) {
            ans *= fastpow(p[i], tmp);
            ans %= mod;
        }
    }
    return ans;
}
signed main() {
    cin >> n >> mod;
    init();
    cout << (C(2 * n, n) - C(2 * n, n - 1) + mod) % mod;
    return 0;
}

// @pid 114 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
