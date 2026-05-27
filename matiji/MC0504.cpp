#include <bits/stdc++.h>
using namespace std;
#define int long long
string s, ans;

signed main() {
    cin >> s;
    for (auto i : s) {
        if (i == 'D') {
            if (ans.size() != 0) {
                ans.pop_back();
            }
        }
        else {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0)cout << "!!!!";
    else cout << ans;
    return 0;
}