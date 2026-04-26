#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans;
string a[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int x = i; x <= n; x++) {
                for (int y = j; y <= m; y++) {
                    bool pan = 1;
                    for (int r = i; r <= x; r++) {
                        for (int c = j; c <= y; c++) {
                            int ni = i + x - r, nj = j + y - c;
                            if (a[r][c] != a[ni][nj]) {
                                pan = 0;
                                break;
                            }
                        }
                        if (!pan) break;
                    }
                    if (pan) ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}