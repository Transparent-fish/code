#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, r, c;
int maxr, maxc, minr, minc;

signed main() {
    cin >> n;
    maxr = maxc = -1e18;
    minr = minc = 1e18;
    for (;n--;) {
        cin >> r >> c;
        maxr = max(maxr, r), minr = min(minr, r);
        maxc = max(maxc, c), minc = min(minc, c);
    }
    cout << max((maxr - minr + 1) / 2, (maxc - minc + 1) / 2) << "\n";
    return 0;
}