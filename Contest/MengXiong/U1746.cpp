#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int t, n, a[N], cnt[3];

signed main() {
    freopen("divide.in", "r", stdin);
    freopen("divide.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        cnt[0] = cnt[1] = cnt[2] = 0;
        for (int i = 1;i <= 2 * n;i++) {
            cin >> a[i];
            cnt[a[i] % 3]++;
        }
        if (cnt[0] > n) {
            cout << "NO\n";
            continue;
        }
        if (cnt[1] == 0 || cnt[2] == 0) {
            cout << "YES\n";
            continue;
        }
        if (cnt[0] < 2) {
            cout << "NO\n";
            continue;
        }
        if (cnt[0] == 2 && cnt[1] % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}