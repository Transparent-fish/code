#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 2;i <= n;i++) {
        if ((a[i] - 1) / 10 < (a[i - 1] - 1) / 10) {
            cout << "No\n";
            exit(0);
        }
    }
    cout << "Yes\n";
    return 0;
}