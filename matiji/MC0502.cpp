#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, cntt, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) { cin >> a[i];if (a[i] < 0)cnt++;else if (a[i] > 0)cntt++; }
    cout << cntt << " " << cnt;
    return 0;
}