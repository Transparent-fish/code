#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, k, ans, cnt[N], s[505][505];

signed main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + (ss[j - 1] - '0');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int sum = 0;
            cnt[0] = 1;
            for (int c = 1; c <= m; c++) {
                sum += s[j][c] - s[i - 1][c];
                if (sum - k >= 0 && sum - k <= n * m) ans += cnt[sum - k];
                cnt[sum]++;
            }
            sum = 0;
            cnt[0] = 0;
            for (int c = 1; c <= m; c++) {
                sum += s[j][c] - s[i - 1][c];
                cnt[sum] = 0;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}