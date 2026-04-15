#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N], b[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    int al = 1, bl = 1, ar = n, br = n;
    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
    for (;al <= ar;) {
        if (a[al] > b[bl])ans += 200, al++, bl++;
        else if (a[ar] > b[br])ans += 200, ar--, br--;
        else {
            if (a[al] < b[br])ans -= 200;
            al++, br--;
        }
    }
    cout << ans << "\n";
    return 0;
}