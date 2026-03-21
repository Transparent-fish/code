#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n, a[N][N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n - 1;i++) {
        for (int j = i + 1;j < n;j++) {
            for (int k = j + 1;k <= n;k++) {
                if (a[i][j] + a[j][k] < a[i][k]) {
                    cout << "Yes\n";
                    exit(0);
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}