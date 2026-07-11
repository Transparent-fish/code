#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt, cntt;
string s;

signed main() {
    cin >> s;
    for (auto c : s) {
        if (c == 'E')cnt++;
        else cntt++;
    }
    cout << (cnt > cntt ? "East" : "West");
    return 0;
}