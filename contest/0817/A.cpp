#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n;

bool check(int x) {
    for (int i = 1;i <= x * x;i++) {
        if (i * i == x)return 1;
    }
    return 0;
}

int f(int l, int r) {
    int cnt = 0;
    for (int i = l;i <= r;i++) {
        if (check(i) == 1) {
            cnt++;
        }
    }
    return cnt;
}

signed main() {
#ifdef __linux__
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
#endif
    for (int n = 1;n <= 5005;n++) {
        int sum = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                sum += f(i, j);
                sum %= mod;
            }
        }
        cout << sum << ", ";
    }
    return 0;
}