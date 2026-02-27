#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, x, y, m, Max;

signed main() {
    cin >> a >> b >> x >> y >> m;
    for (int i = 0; i <= a; i++) {
        if (i * x > m) break;
        Max = max(Max, i + min(b, (m - i * x) / y));
    }
    for (int i = 0; i <= b; i++) {
        if (i * y > m) break;
        Max = max(Max, i + min(a, (m - i * y) / x));
    }
    cout << Max << "\n";
    return 0;
}