#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
    cin >> s;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            cout << c;
        }
    }
    return 0;
}