#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEBUG
const int N = 1e6 + 5;
int n, m, l[N], r[N];

bool check(int x) {
    int i = 1, j = 1, cnt = 0;
    for (;i <= n && j <= m;) {
        if (abs(l[i] - r[j]) <= x) {
            cnt++, i++, j++;
#ifdef DEBUG
            cout << "asd\n";
            cout << cnt << " " << i << " " << j << "\n";
#endif
        }
        else if (l[i] < r[j]) {
#ifdef DEBUG
            cout << "asdasd\n";
            cout << cnt << " " << i << " " << j << "\n";
#endif
            i++;
        }
        else {
#ifdef DEBUG
            cout << "asdasdasd\n";
            cout << cnt << " " << i << " " << j << "\n";
#endif
            j++;
        }
        // cout << i << " " << j << "\n";
    }
    return cnt == min(n, m);
}

signed main() {
#ifdef DEBUG
    freopen("ex_gloves4.in", "r", stdin);
    freopen("ans.ans", "w", stdout);
#else
    freopen("gloves.in", "r", stdin);
    freopen("gloves.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> l[i];
    }
    for (int i = 1;i <= m;i++) {
        cin >> r[i];
    }
    sort(l + 1, l + n + 1), sort(r + 1, r + m + 1);
    int L = 0, R = 1e18, ans = 0;
    for (;L <= R;) {
        int mid = (L + R) >> 1;
        if (check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    cout << ans;
    return 0;
}