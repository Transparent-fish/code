#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int t, x, las, a[N];

signed main() {
    cin >> t >> x;
    for (int i = 0;i <= t;i++) {
        cin >> a[i];
    }
    las = a[0];
    for (int i = 0;i <= t;i++) {
        if (i == 0) {
            cout << i << " " << a[0] << "\n";
            continue;
        }
        if (abs(a[i] - las) >= x) {
            cout << i << " " << a[i] << "\n";
            las = a[i];
        }
    }
    return 0;
}