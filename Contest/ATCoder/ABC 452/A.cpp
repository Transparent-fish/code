#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, d;

signed main() {
    cin >> m >> d;
    if ((m == 1 && d == 7) || (m == 3 && d == 3) || (m == 5 && d == 5) || (m == 7 && d == 7) || (m == 9 && d == 9)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}