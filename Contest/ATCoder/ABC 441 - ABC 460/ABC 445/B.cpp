#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
string s[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }
    for (int i = 1;i <= n;i++) {
        string now((m - s[i].size()) / 2, '.');
        cout << now << s[i] << now << "\n";
    }
    return 0;
}