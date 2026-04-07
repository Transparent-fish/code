#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x;

signed main() {
    cin >> n >> x;
    for (int i = 1;i <= n;i++) {
        int now;
        cin >> now;
        if (now < x) {
            x = now;
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}