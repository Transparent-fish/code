#include <bits/stdc++.h>
using namespace std;
#define int long long
int T, x, y, k;

int solve(int x, int y, int k) {
    int ans = 0;
    for (;x != y;) {
        if (x > y)x /= k;
        else y /= k;
        ans++;
    }
    return ans;
}

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> x >> y >> k;
        cout << solve(x, y, k) << "\n";
    }
    return 0;
}