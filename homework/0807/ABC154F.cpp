#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int N = 2000005;
int r, c, rr, cc, ans, fa[N], in[N];

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
}

signed main() {
    cin >> r >> c >> rr >> cc;
    init();
    for (int i = r; i <= rr; i++) {
        ans = (ans + C(i + cc + 1, i + 1) - C(i + c, i + 1)) % mod;
        if (ans < 0) ans += mod;
    }
    cout << ans;
    return 0;
}

// @pid 21 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
