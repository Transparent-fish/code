#include <bits/stdc++.h>
using namespace std;
#define int long long
string x, y;
map<string, int>mp;

signed main() {
    cin >> x >> y;
    mp["Ocelot"] = 1;
    mp["Serval"] = 2;
    mp["Lynx"] = 3;
    if (mp[x] >= mp[y]) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}