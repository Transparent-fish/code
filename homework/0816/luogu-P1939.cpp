#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 1e9 + 7;
int T, n;

struct node {
    int c[10][10];
}ans, bas;

void init() {
    memset(ans.c, 0, sizeof ans.c);
    memcpy(bas.c, ans.c, sizeof bas.c);
    for (int i = 1;i <= 3;i++)ans.c[i][i] = 1;
    bas.c[1][1] = bas.c[1][3] = bas.c[2][1] = bas.c[3][2] = 1;
}

node mul(node a, node b) {
    node res;
    memset(res.c, 0, sizeof res.c);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                res.c[i][j] += (a.c[i][k] % mod) * (b.c[k][j] % mod);
                res.c[i][j] %= mod;
            }
        }
    }
    return res;
}

void query(int x) {
    for (;x;) {
        if (x & 1) ans = mul(ans, bas);
        bas = mul(bas, bas);
        x >>= 1;
    }
}

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n;
        if (n <= 3)cout << "1\n";
        else {
            init(), query(n);
            cout << ans.c[2][1] << "\n";
        }
    }
    return 0;
}