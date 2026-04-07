#include <bits/stdc++.h>
using namespace std;
#define int long long
int d, f;

signed main() {
    cin >> d >> f;
    cout << (((d - f) / 7) * 7 + f) + 7 - d;
    return 0;
}