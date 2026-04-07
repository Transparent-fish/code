#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, b[N];
string s, t, ans;

signed main() {
    cin >> n >> m >> s >> t;
    for (;m--;) {
        int l, r;
        cin >> l >> r;
        b[l]++, b[r + 1]--;
    }
    for (int i = 1;i <= n;i++) {
        b[i] += b[i - 1];
    }
    for (int i = 0;i < n;i++) {
        if (b[i + 1] % 2 == 1) {
            cout << t[i];
        }
        else {
            cout << s[i];
        }
    }
    return 0;
}