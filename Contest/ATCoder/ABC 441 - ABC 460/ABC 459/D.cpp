#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
map<char, int>mp;

signed main() {
    cin >> T;
    for (;T--;) {
        string s;
        char c;
        int Max = 0;
        cin >> s;
        mp.clear();
        for (auto i : s) {
            mp[i]++;
        }
        for (auto i : mp) {
            Max = max(Max, i.second);
        }
        for (auto i : mp) {
            if (i.second == Max) {
                c = i.first;
                break;
            }
        }
        if (Max > (s.size() + 1) / 2)cout << "No\n";
        else {
            string ans(s.size(), ' ');
            int idx = 0;
            for (;mp[c] > 0;) ans[idx] = c, idx += 2, mp[c]--;
            for (auto i : mp) {
                for (;i.second > 0;) {
                    if (idx >= s.size())idx = 1;
                    ans[idx] = i.first, idx += 2, i.second--;
                }
            }
            cout << "Yes\n" << ans << "\n";
        }
    }
    return 0;
}