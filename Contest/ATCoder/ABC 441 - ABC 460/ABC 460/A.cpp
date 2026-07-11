#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt;

signed main() {
    cin >> n >> m;
    for (;m;)m = n % m, ++cnt;
    cout << cnt;
    return 0;
}