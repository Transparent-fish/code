#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, a[N];

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        int now = 1e18;
        for (int i = 1;i <= n;i++) {
            if (a[i] != 0)now = min(now, a[i]);
        }
        cout << now + 1 << "\n";
    }
    return 0;
}