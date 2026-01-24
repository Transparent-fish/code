#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
char ans;
map<char, int>mp;

signed main() {
    cin >> s;
    for (auto i : s) {
        mp[i]++;
    }
    int Min = LLONG_MAX;
    for (auto c : mp) {
        if (c.second < Min) {
            Min = c.second;
            ans = c.first;
        }
    }
    cout << ans;
    return 0;
}