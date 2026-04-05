#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], b[N];
bool mp[15][15][30];
string s[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> s[i];
        for (int j = 0;j < s[i].size();j++) mp[s[i].size()][j + 1][s[i][j] - 'a'] = 1;
    }
    for (int i = 1;i <= q;i++) {
        if (s[i].size() != n) {
            cout << "No\n";
            continue;
        }
        bool vis = 1;
        for (int j = 1;j <= n;j++) {
            if (!mp[a[j]][b[j]][s[i][j - 1] - 'a']) {
                vis = 0;
                break;
            }
        }
        if (vis == 1)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}