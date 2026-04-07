#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, _;
int a[N], s[N];

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (;q--;) {
        int op, l, c;
        cin >> op;
        if (op == 1) {
            cin >> c;
            _ = (_ + c) % n;
        }
        else {
            cin >> c >> l;
            c--, l--;
            if ((_ + c) % n <= (_ + l) % n) {
                cout << s[((_ + l) % n) + 1] - s[((_ + c) % n)] << "\n";
            }
            else {
                cout << s[n] - s[((_ + c) % n)] + s[((_ + l) % n) + 1] << "\n";
            }
        }
    }
    return 0;
}