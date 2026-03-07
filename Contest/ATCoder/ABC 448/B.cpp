#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans, a[N], b[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        int aa, bb;
        cin >> aa >> bb;
        b[aa] += bb;
    }
    for (int i = 1;i <= m;i++) {
        ans += min(a[i], b[i]);
    }
    cout << ans << "\n";
    return 0;
}