#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int cnt, id, idd, a[N], b[N];
string s, t, ss, tt;

signed main() {
    cin >> s >> t;
    for (auto i : s) {
        if (i == 'A') {
            cnt++;
        }
        else {
            ss += i;
            a[id++] = cnt;
            cnt = 0;
        }
    }
    a[id] = cnt;
    cnt = 0;
    for (auto i : t) {
        if (i == 'A') {
            cnt++;
        }
        else {
            tt += i;
            b[idd++] = cnt;
            cnt = 0;
        }
    }
    b[idd] = cnt;
    if (ss != tt) {
        cout << "-1";
        exit(0);
    }
    int ans = 0;
    for (int i = 0; i <= ss.size(); i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << "\n";
    return 0;
}