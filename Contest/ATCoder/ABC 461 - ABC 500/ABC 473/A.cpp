#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, sum, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = n / 2 + 1;i <= n;i++) {
        sum += a[i];
    }
    cout << sum;
    return 0;
}