#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, Min, Max, Minn, Maxx;
string s[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    Min = m, Max = -1, Minn = n, Maxx = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j - 1] == '#') {
                Min = min(Min, j - 1);
                Max = max(Max, j - 1);
                Minn = min(Minn, i);
                Maxx = max(Maxx, i);
            }
        }
    }
    for (int i = Minn; i <= Maxx; i++) {
        for (int j = Min; j <= Max; j++) {
            cout << s[i][j];
        }
        cout << "\n";
    }
    return 0;
}