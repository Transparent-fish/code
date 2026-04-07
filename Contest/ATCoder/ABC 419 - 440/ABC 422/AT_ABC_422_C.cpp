#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;

signed main() {
    cin >> t;
    for (;t--;) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << min({ a,c,(a + b + c) / 3LL }) << "\n";
    }
    return 0;
}