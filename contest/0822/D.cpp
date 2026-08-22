#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, l, a[N];

signed main() {
#ifdef __linux__
    freopen("magneti.in", "r", stdin);
    freopen("magnet.out", "w", stdout);
#endif
    cin >> n >> l;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << l;
    }
    else {
        int sum = 1;
        for (int i = l;i >= 1;i--) {
            sum *= i;
            sum %= mod;
        }
        cout << sum;
    }
    return 0;
}