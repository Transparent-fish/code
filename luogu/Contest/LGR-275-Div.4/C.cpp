#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, x, y, cnt, Max, a[N];

bool check(int k) {
    if (x + y == k || x + k == y || y + k == x || x * y == k || x * k == y || y * k == x)return 1;
    return 0;
}

signed main() {
    cin >> n >> x >> y;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        if (check(a[i]) == 1) {
            cnt++;
            Max = max(Max, a[i]);
        }
    }
    cout << cnt << " " << Max;
    return 0;
}