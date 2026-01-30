#include <bits/stdc++.h>
using namespace std;
#define int long long
int sx, sy;
int a[4][4];

signed main() {
    for (int i = 1;i <= 4;i++) {
        for (int j = 1;j <= 4;j++) {
            cin >> a[i][j];
            if (a[i][j] == 0)sx = i, sy = j;
        }
    }
    int sum = 0;
    for (int i = 1;i <= 4;i++) {
        sum += a[sx][i];
    }
    cout << 10 - sum;
    return 0;
}