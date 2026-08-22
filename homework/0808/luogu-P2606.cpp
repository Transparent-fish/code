#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5, Mod = 998244353;
int n, mod, f[N], in[N], fa[N], siz[N];

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int m) {
    return 1ll * fa[n] * fpow(1ll * fa[m] * fa[n - m] % mod, mod - 2) % mod;
}

void init() {
    fa[0] = 1;
    for (int i = 1; i < N; i++) {
        fa[i] = fa[i - 1] * i % mod;
    }
    in[N - 1] = fpow(fa[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        in[i] = in[i + 1] * (i + 1) % mod;
    }
}

int luka(int n, int m) {
    if (m == 0)return 1;
    if (n < m)return 0;
    return C(n % mod, m % mod) * luka(n / mod, m / mod) % mod;
}

signed main() {
    cin >> n >> mod;
    init();
    for (int i = 1;i <= n;i++)siz[i] = 1;
    for (int i = n;i >= 2;i--)siz[i >> 1] += siz[i];
    for (int i = n + 1;i <= n * 2 + 1;i++)f[i] = 1;
    for (int i = n;i >= 1;i--) {
        f[i] = luka(siz[i] - 1, siz[i * 2]) % mod * f[i * 2] % mod * f[i * 2 + 1] % mod;
    }
    for (int i = 1;i <= n;i++) {
        cout << f[i] << " ";
    }
    cout << f[1];
    return 0;
}

// @pid 35 @tid 6a6c7f23bdb36af2d80fa4cd @lang cc.cc14o2
