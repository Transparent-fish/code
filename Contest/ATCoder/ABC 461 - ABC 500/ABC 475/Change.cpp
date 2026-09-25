#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a, x, y, z;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a;
        int t = (1000 - a % 1000) % 1000;
        z += t / 100, t %= 100, y += t / 10;
        t %= 10, x += t;
    }
    cout << x << " " << y << " " << z;
    return 0;
}