#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s;

signed main() {
    cin >> s >> n;
    cout << s.substr(n, s.size() - 2 * n);
    return 0;
}