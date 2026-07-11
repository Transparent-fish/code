#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, y, l, r, a, b, cnt;

signed main() {
    cin >> x >> y >> l >> r >> a >> b;
    for (int i = a;i < b;i++) {
        if (i >= l && i < r)cnt += x;
        else cnt += y;
    }
    cout << cnt;
    return 0;
}