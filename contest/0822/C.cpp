#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, a[N], b[N], c[N];

signed main() {
#ifdef __linux__
    freopen("store.in", "r", stdin);
    freopen("store.out", "w", stdout);
#endif
    cin >> n >> m >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
    cout << "Impossible";
    return 0;
}