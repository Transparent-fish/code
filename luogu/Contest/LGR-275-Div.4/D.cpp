#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], k;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    cin >> k;
    if (a[k] == 1) {
        for (int i = 1;i <= n;i++) {
            if (a[i] == 0) { cout << i;exit(0); }
        }
    }
    cout << k;
    return 0;
}