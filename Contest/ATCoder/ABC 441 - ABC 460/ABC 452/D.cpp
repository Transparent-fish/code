#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
string s, t;

signed main() {
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        int j = 0, vis = 0;
        for (int k = i; k < s.size(); k++) {
            if (j < t.size() && s[k] == t[j]) j++;
            if (j == t.size()) {
                cnt += k - i;
                vis = 1;
                break;
            }
        }
        if (!vis) cnt += s.size() - i;
    }
    cout << cnt << "\n";
    return 0;
}