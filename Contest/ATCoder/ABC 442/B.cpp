#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, cnt = 0, pan = 0;

signed main() {
    cin >> q;
    for (;q--;) {
        int a;
        cin >> a;
        if (a == 1)cnt++;
        else if (a == 2) {
            if (cnt >= 1)cnt--;
        }
        else if (a == 3)pan = !pan;
        if (pan && cnt >= 3)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}