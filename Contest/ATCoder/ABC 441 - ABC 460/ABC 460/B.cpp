#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, x, y, r, xx, yy, rr, now;

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> x >> y >> r >> xx >> yy >> rr;
        now = (x - xx) * (x - xx) + (y - yy) * (y - yy);
        cout << (now >= (r - rr) * (r - rr) && now <= (r + rr) * (r + rr) ? "Yes\n" : "No\n");
    }
    return 0;
}