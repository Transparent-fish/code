#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, m, d, cnt, ans, a[N][N];

signed main() {
    cin >> n >> m >> d;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (cnt == d) {
                int ni = i + 1, nj = j + 1;
                if (ni > n)nj++;
                if (nj > m)ni++;
                if (a[ni][nj] != 1) {
                    cout << ans << "\n";
                    exit(0);
                }
                cnt++, ans++;
            }
            else {
                ans++, cnt++;
            }
        }
    }
    return 0;
}