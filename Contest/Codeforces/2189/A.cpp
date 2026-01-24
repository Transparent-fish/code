#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, a[N];

signed main() {
    cin >> T;
    for (;T--;) {
        int n, h, l, cnt = 0, cntt = 0, cnttt = 0;
        cin >> n >> h >> l;
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for (int i = 1;i <= n;i++) {
            if (a[i] <= h && a[i] <= l)cnt++;
            else if (a[i] <= h)cntt++;
            else if (a[i] <= l)cnttt++;
        }
        cout << min({ cnt + cntt,cnt + cnttt,(cnt + cntt + cnttt) / 2 }) << "\n";
    }
    return 0;
}