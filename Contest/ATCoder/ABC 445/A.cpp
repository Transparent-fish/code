#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
    cin >> s;
    if (s[0] == s[s.size() - 1])cout << "Yes\n";
    else cout << "No\n";
    return 0;
}