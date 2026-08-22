#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, a, b;
__int128_t ans;

int fpow(int a, int b, int p) {
    int ans = 1;
    for (;b;) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

__int128_t C(__int128_t r, __int128_t n) {
    swap(r, n);
    __int128_t ans = 1;
    for (__int128_t i = 1; i <= r; ++i) {
        ans *= n - i + 1;
        ans /= i;
    }
    return ans;
}

void print(__int128_t x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar((int)(x % 10) + '0');
}

signed main() {
    cin >> n >> a >> b;
    for (int i = 0;i <= a;i++) {
        for (int j = 0;j <= b;j++) {
            ans += C(n + i - 1, n - 1) * C(j + n - 1, n - 1);
        }
    }
    print(ans);
    return 0;
}

// @pid 32 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2