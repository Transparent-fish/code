#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans = 1e18, a[N], b[N];
signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        cin >> b[i];
    }
    for (int i = 0;i <= 1;i++) {
        int now_ = 0, noow = a[1];
        if (i) {   
            noow = 1 - noow;
            now_++;
        }
        for (int j = 1; j < n; j++) {
            int nex;
            if (b[j] == 0) nex = noow;
            else nex = 1 - noow;
            if (nex != a[j + 1]) now_++;
            noow = nex;
        }
        ans = min(ans, now_);
    }
    cout << ans;
    return 0;
}