#include <bits/stdc++.h>
using namespace std;
#define int long long
int p, q, x, y;

signed main() {
    cin >> p >> q >> x >> y;
    if (p <= x && x <= p + 99 && q <= y && y <= q + 99)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}