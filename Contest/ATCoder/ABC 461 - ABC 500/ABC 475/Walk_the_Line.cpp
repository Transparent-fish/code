#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, s, l, ans, a[N], ss[N];

signed main() {
    cin >> n >> s >> l;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        ss[i] = ss[i - 1] + a[i];
    }
    for (int i = 1;i <= s;i++) {
        for (int j = s;j <= n;j++) {
            int x = ss[s - 1] - ss[i - 1], y = ss[j - 1] - ss[s - 1];
            if (min(x * 2 + y, x + y * 2) <= l) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans;
    return 0;
}