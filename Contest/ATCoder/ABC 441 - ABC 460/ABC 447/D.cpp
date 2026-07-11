#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt, cntt, ans;
string s;

signed main() {
    cin >> s;
    for (auto i : s) {
        if (i == 'A')cnt++;
        else if (i == 'B') {
            if (cnt > 0) {
                cnt--, cntt++;
            }
        }
        else {
            if (cntt > 0) {
                cntt--, ans++;
            }
        }
    }
    cout << ans;
    return 0;
}