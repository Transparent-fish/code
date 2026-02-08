#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, a[N];

signed main() {
    cin >> T;
    for (;T--;) {
        int n, x, y, tot = 0, Max = -1;
        cin >> n >> x >> y;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
            tot += (a[i] / x) * y;
            Max = max(Max, a[i] - ((a[i] / x) * y));
        }
        cout << tot + Max << "\n";
        // cout << tot << " " << Max << "\n";
    }
    return 0;
}