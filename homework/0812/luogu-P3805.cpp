#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2.2e7 + 5;
int n, r, c, ans, a[N];
string s, t;

signed main() {
    cin >> t;
    for (int i = 0;i < t.size();i++) {
        s += "$", s += t[i];
    }
    s += "$";
    for (int i = 0;i < (t.size() << 1 | 1);i++) {
        if (r > i)a[i] = min(r - i, a[(c << 1) - i]);
        else a[i] = 1;
        for (;i + a[i] < (t.size() << 1 | 1) && i - a[i] >= 0 && s[i + a[i]] == s[i - a[i]];) a[i]++;
        if (i + a[i] > r) {
            r = i + a[i], c = i;
        }
        ans = max(ans, a[i]);
    }
    cout << ans - 1;
    return 0;
}