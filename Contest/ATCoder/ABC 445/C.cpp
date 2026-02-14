#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], f[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = n;i >= 1;i--) {
        if (a[i] == i)f[i] = i;
        else if (a[i] > i)f[i] = f[a[i]];
    }
    for (int i = 1;i <= n;i++) {
        cout << f[i] << " ";
    }
    return 0;
}