#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Min, cnt, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
    }
    Min = 1e18;
    for (int i = 1;i <= n;i++) {
        if (a[i] < Min) {
            cnt++;
        }
        Min = min(Min, a[i]);
    }
    cout << cnt;
    return 0;
}