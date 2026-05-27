#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, mod;

int fpow(int x, int y, int mod) {
    if (y == 0)return 1;
    int now = fpow(a, floor(y / 2), mod);
    if (y % 2 == 0)return (now * now) % mod;
    else return (now * now % mod * a) % mod;
}

signed main() {
    cin >> a >> b >> mod;
    cout << a << "^" << b << " mod " << mod << "=";
    cout << fpow(a, b, mod) << "\n";
    return 0;
}