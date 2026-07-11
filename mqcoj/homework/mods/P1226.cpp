#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, p;

int fpow(int a, int b, int mod) {
    if (b == 0)return 1;
    int c = fpow(a, (b >> 1), mod);
    if ((b & 1) == 0)return (c * c) % mod;
    else return (c * c % mod * a) % mod;
}

signed main() {
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << fpow(a, b, p);
    return 0;
}