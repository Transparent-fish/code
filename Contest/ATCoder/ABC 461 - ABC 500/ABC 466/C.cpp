#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;
string s;

bool query(int x, int y) {
    cout << "? " << x << " " << y << "\n" << flush;
    cin >> s;
    return s == "Yes";
}

signed main() {
    cin >> n;
    for (int i = 1, j = 2;j <= n;j++) {
        for (;i < j && !query(i, j);) i++;
        ans += (j - i);
    }
    cout << "! " << ans << "\n" << flush;
    return 0;
}