#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N];

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++)cin >> a[i];
    for (;q--;) {
        int op, l, r, x;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> x;
            for (int i = l;i <= r;i++)a[i] += x;
        }
        else if (op == 2) {
            cin >> x;
            for (int i = l;i <= r;i++)if (a[i] > x)a[i] = x;
        }
        else {
            int sum = 0;
            for (int i = l;i <= r;i++)sum += a[i];
            cout << sum << "\n";
        }
    }
    return 0;
}