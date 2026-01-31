#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, t, sum, tot, a[N];

signed main() {
    cin >> n >> t;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        if (a[i] >= tot) {
            sum += (a[i] - tot);
            tot = a[i] + 100;
        }
    }
    if (t > tot)sum += (t - tot);
    cout << sum;
    return 0;
}