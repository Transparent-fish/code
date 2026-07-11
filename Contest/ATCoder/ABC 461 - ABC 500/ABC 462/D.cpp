#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, d, a[N];

signed main() {
    cin >> n >> d;
    for (int i = 1;i <= n;i++) {
        int s, t;
        cin >> s >> t;
        int Max = t - d;
        if (s <= Max) {
            a[s]++, a[Max + 1]--;
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1;i < N;i++) {
        cnt += a[i];
        if (cnt >= 2)ans += cnt * (cnt - 1) / 2;
    }
    cout << ans;
    return 0;
}