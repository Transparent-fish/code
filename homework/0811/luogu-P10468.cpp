#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, bas = 131, mod = 998244353;
int n, has[N], fpow[N];
string s;

void Has() {
    fpow[0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        has[i] = (has[i - 1] * bas + s[i - 1]) % mod;
        fpow[i] = (fpow[i - 1] * bas) % mod;
    }
}

signed main() {
    cin >> s >> n;
    Has();
    for (;n--;) {
        int l, r, ll, rr, len1, len2;
        cin >> l >> r >> ll >> rr;
        len1 = r - l + 1, len2 = rr - ll + 1;
        cout <<
            ((has[r] + mod - has[l - 1] * fpow[len1] % mod) % mod
                ==
                (has[rr] + mod - has[ll - 1] * fpow[len2] % mod) % mod
                ? "Yes\n" : "No\n");
    }
    return 0;
}

// @pid 215 @tid 6a7afe00f80e134e7823401b @lang cc.cc14o2
