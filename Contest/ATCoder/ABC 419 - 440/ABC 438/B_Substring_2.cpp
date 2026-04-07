#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, Min = 1e9;
string s, t;

signed main() {
    cin >> n >> m >> s >> t;
    for (int i = 0;i <= n - m;i++) {
        int now = 0;
        for (int j = 0;j < m;j++) {
            now += (((s[i + j] - '0') - (t[j] - '0')) + 10) % 10;
        }
        Min = min(Min, now);
    }
    cout << Min;
    return 0;
}