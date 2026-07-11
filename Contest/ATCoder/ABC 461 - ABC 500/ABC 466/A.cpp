#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, pan, a[N];

signed main() {
    cin >> n;
    pan = 1;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] >= 0) {
            pan = 0;
        }
    }
    if (pan == 1)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}