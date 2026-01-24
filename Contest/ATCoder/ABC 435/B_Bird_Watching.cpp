#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], b[N], s[N], c[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        s[a[i]] += b[i], c[a[i]]++;
    }
    cout << fixed << setprecision(15);
    for (int i = 1;i <= m;i++) {
        cout << (long double)s[i] / c[i] << "\n";
    }
    return 0;
}