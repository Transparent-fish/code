#include <bits/stdc++.h>
using namespace std;
#define int long long
int s, a, b, x;

signed main() {
    cin >> s >> a >> b >> x;
    cout << (x / (a + b) * a + min(x % (a + b), a)) * s;
    return 0;
}