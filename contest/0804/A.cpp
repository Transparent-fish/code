#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int T, a[N], b[N], f[N][50], f1[N][50];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifdef __linux__
    freopen("geminae.in", "r", stdin);
    freopen("geminae.out", "w", stdout);
#endif
    cin >> T;
    for (;T--;) {
        int n, m;
        string s, s1;
        cin >> n >> m >> s >> s1;
        memset(a, 0x3f, sizeof a);
        memset(b, 0x3f, sizeof b);
        for (int i = 0;i < n;i++) {
            a[s[i] - 'A'] = min(a[s[i] - 'A'], i);
        }
        for (int i = 0;i < m;i++) {
            b[s1[i] - 'A'] = min(b[s1[i] - 'A'], i);
        }
        for (int i = 0;i < 26;i++) {
            f[n][i] = f1[m][i] = 0;
        }
        for (int i = n - 1;i >= 0;i--) {
            for (int j = 0;j < 26;j++) f[i][j] = f[i + 1][j];
            f[i][s[i] - 'A']++;
        }
        for (int i = m - 1;i >= 0;i--) {
            for (int j = 0;j < 26;j++) f1[i][j] = f1[i + 1][j];
            f1[i][s1[i] - 'A']++;
        }
        bool pan = 0;
        for (int k = 0;k < 26;k++) {
            if (a[k] >= n || b[k] >= m) continue;
            for (int j = 0;j < 26;j++) {
                if (f[a[k] + 1][j] > 0 && f1[b[k] + 1][j] > 0) {
                    cout << char(k + 'A') << char(j + 'A') << "\n";
                    pan = 1;
                    break;
                }
            }
            if (pan) break;
        }
        if (!pan) {
            cout << "-1\n";
        }
    }
    return 0;
}