#include <bits/stdc++.h>
using namespace std;
#define int long long
int h, w;

signed main() {
    cin >> h >> w;
    double now = (double)w * 10000 / (h * h);
    if (now >= 25.0) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}