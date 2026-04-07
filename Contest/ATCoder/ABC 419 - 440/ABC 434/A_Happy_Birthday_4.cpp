#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, y, z;

signed main() {
    cin >> x >> y >> z;
    if (x - z * y < 0)cout << "No";
    else {
        if (x - z * y % z - 1)cout << "Yes";
        else cout << "No";
    }
    return 0;
}