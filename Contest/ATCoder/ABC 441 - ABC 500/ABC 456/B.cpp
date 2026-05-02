#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[3][7];

signed main() {
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 6; ++j) {
            int now;
            cin >> now;
            if (now >= 1 && now <= 6) {
                cnt[i][now]++;
            }
        }
    }
    int now = cnt[1][4] * cnt[2][5] * cnt[3][6];
    now += cnt[1][4] * cnt[2][6] * cnt[3][5];
    now += cnt[1][5] * cnt[2][4] * cnt[3][6];
    now += cnt[1][5] * cnt[2][6] * cnt[3][4];
    now += cnt[1][6] * cnt[2][4] * cnt[3][5];
    now += cnt[1][6] * cnt[2][5] * cnt[3][4];
    printf("%.10lf", now / 216.0);
    return 0;
}