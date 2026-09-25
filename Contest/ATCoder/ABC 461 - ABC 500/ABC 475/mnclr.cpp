#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
    cin >> s;
    for (int i = 0;i < s.size();i++) {
        cout << s[i];
        if (i != s.size() - 1)cout << "o";
    }
    return 0;
}