#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 20100403;
int n, m;

int fpow(int a, int b, int p) {
    int ans = 1;
    for (;b;) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

int C(int n, int k) {
    swap(n, k);
    if (k < 0 || k > n) return 0;
    int num = 1, den = 1;
    for (int i = 0; i < k; i++) {
        num = num * ((n - i) % mod) % mod;
    }
    for (int i = 1; i <= k; i++) {
        den = den * i % mod;
    }
    return num * fpow(den, mod - 2, mod) % mod;
}

signed main() {
    cin >> n >> m;
    cout << (C(n, n + m) - C(n + 1, n + m) + mod) % mod;
    return 0;
}

// @pid 33 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
