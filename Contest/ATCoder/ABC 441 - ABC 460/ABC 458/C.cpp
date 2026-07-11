#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans;
string s;

signed main() {
    cin >> s;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == 'C') {
            ans += min(i, (int)s.size() - 1 - i) + 1;
        }
    }
    cout << ans;
    return 0;
}