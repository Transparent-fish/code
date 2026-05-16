#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt;
int d[4][2] = { 0,1,0,-1,1,0,-1,0 };

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cnt = 0;
            for (int k = 0;k < 4;k++) {
                if (i + d[k][0] >= 1 && i + d[k][0] <= n && j + d[k][1] >= 1 && j + d[k][1] <= m)cnt++;
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
    return 0;
}