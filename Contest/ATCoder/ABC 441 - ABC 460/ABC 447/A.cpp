#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;

signed main() {
    cin >> n >> m;
    if (m <= (n + 1) / 2)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}