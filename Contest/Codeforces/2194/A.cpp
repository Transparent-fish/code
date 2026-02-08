#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;

signed main() {
    cin >> T;
    for (;T--;) {
        int n, w;
        cin >> n >> w;
        cout << n - n / w << "\n";
    }
    return 0;
}