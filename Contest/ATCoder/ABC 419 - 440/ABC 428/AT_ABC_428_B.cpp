#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, Max = -1e18;
string s;
map<string, int>mp;

signed main() {
    cin >> n >> k >> s;
    for (int i = 0;i <= n - k;i++) {
        mp[s.substr(i, k)]++;
    }
    for (auto i : mp) {
        Max = max(Max, i.second);
    }
    cout << Max << "\n";
    for (auto i : mp) {
        if (i.second == Max)cout << i.first << " ";
    }
    return 0;
}