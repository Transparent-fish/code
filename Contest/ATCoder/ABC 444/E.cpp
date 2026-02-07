#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, d, l = 1, ans, a[N];
set<int>s;

signed main() {
    cin >> n >> d;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int r = 1;r <= n;r++) {
        int now = a[r];
        for (;;) {
            auto it = s.lower_bound(now - d + 1);
            if (it != s.end() && *it < a[r] + d) { s.erase(s.find(a[l]));l++; }
            else break;
        }
        s.insert(a[r]);
        ans += r - l + 1;
    }
    cout << ans << "\n";
    return 0;
}