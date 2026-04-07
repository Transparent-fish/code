#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
    cin >> s;
    cout << s.substr(0, s.size() / 2) + s.substr(s.size() / 2 + 1);
    return 0;
}