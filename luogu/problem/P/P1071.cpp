#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b, s, ans;
map<char, char>mp;
map<char, bool>vis, vvis;

signed main() {
    cin >> a >> b >> s;
    for (int i = 0;i < a.size();i++) {
        if (vis[b[i]] && b[i] != mp[a[i]]) {
            cout << "Failed\n";
            exit(0);
        }
        mp[a[i]] = b[i];
        vis[b[i]] = 1;
    }
    for (auto i = 'A';i <= 'Z';i++) {
        if (!vis[i]) {
            cout << "Failed\n";
            exit(0);
        }
    }
    for (auto i : s) {
        if (vis[i] == 0 && b[i] != mp[a[i]]) {
            cout << "Failed\n";
            exit(0);
        }
        ans += mp[i];
    }
    cout << ans << "\n";
    return 0;
}