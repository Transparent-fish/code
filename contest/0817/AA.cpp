#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, now, cnt;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    cin >> n;
    for (int i = 1;i * i <= n;i++) {
        cnt += (((n - i * i + 1) % mod) * ((i * i) % mod)) % mod;
        cnt %= mod;
    }
    cout << cnt;
    return 0;
}