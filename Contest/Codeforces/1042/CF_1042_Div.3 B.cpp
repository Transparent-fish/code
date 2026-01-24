#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;

signed main() {
    cin >> t;
    for (;t--;) {
        int n;
        cin >> n;
        cout << "-1 ";
        for (int i = 2;i <= n;i++) {
            if (i % 2 == 0) {
                if (i == n)cout << "2\n";
                else cout << "3 ";
            }
            else {
                cout << "-1 ";
            }
        }
    }
    return 0;
}