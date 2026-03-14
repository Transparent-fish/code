#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, c;

signed main() {
    cin >> a >> b >> c;
    for (;c--;) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            cout << v * b << "\n";
            a -= v;
        }
        else {
            cout << v * a << "\n";
            b -= v;
        }
    }
    return 0;
}