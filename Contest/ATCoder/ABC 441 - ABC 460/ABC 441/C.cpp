#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 4;
int n, k, x, cnt, a[N];

signed main() {
    cin >> n >> k >> x;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1;i <= n;i++) {
        a[i] += a[i - 1];
    }
    for (int i = 1;i <= n;i++) {
        cnt = max(0LL, k - n + i);
        if (cnt > i)continue;
        if (a[i] - a[i - cnt] >= x) {
            cout << i << "\n";
            exit(0);
        }
    }
    cout << "-1\n";
    return 0;
}