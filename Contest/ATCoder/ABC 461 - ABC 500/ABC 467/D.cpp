#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;

signed main() {
    cin >> t;
    for (;t--;) {
        int px, py, qx, qy, rx, ry, sx, sy;
        cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
        int a1 = px - qx, b1 = py - qy, a2 = rx - sx, b2 = ry - sy;
        int c1 = (px * px + py * py - qx * qx - qy * qy), c2 = (rx * rx + ry * ry - sx * sx - sy * sy);
        if (a1 * b2 == a2 * b1) {
            if (a1 * c2 == a2 * c1 && b1 * c2 == b2 * c1) cout << "Yes\n";
            else cout << "No\n";
        }
        else cout << "Yes\n";
    }
    return 0;
}   