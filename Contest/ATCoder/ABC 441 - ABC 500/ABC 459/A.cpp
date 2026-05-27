#include <bits/stdc++.h>
using namespace std;
#define int long long
int x;

signed main() {
    string s = " HelloWorld";
    cin >> x;
    for (int i = 1;i < s.size();i++) {
        if (i == x)continue;
        cout << s[i];
    }
    return 0;
}