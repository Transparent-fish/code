#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int n, a[N][N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        for (int j = i;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    return 0;
}