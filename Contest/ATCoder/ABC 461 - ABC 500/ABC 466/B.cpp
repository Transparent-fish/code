#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];

signed main() {
    memset(a, -1, sizeof(a));
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        int c, s;
        cin >> c >> s;
        a[c] = max(a[c], s);
    }
    for (int i = 1;i <= m;i++) {
        if (a[i] == -1) cout << -1 << " ";
        else cout << a[i] << " ";
    }
    return 0;
}