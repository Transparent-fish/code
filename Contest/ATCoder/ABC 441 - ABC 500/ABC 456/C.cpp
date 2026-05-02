#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int l, cnt, n;
string s;

signed main() {
    cin >> s;
    n = s.size();
    s = " " + s, l = 1;
    l = 1;
    for (int r = 1; r <= n; r++) {
        if (r == n || s[r] == s[r + 1]) {
            int ll = r - l + 1;
            cnt += (ll * (ll + 1) / 2);
            cnt %= mod;
            l = r + 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}