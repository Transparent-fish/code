#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int T, f[N], d[N], fa[N], in[N];

int fpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fa[n] * in[k] % mod * in[n - k] % mod;
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
    d[0] = 1, d[1] = 0, d[2] = 1;
    for (int i = 1;i <= N;i++) {
        d[i] = ((i - 1) * (d[i - 1] + d[i - 2])) % mod;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    init();
    for (;T--;) {
        int n, m;
        cin >> n >> m;
        cout << (C(n, m) * d[n - m]) % mod << "\n";
    }
    return 0;
}

// @pid 113 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
