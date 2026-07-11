#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], b[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= n;i++) {
        if (b[a[i]] != i) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
    return 0;
}