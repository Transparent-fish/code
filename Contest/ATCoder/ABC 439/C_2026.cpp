#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int n, cnt, mp[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int x = 1;x * x <= n;x++) {
        for (int y = x + 1;;y++) {
            if (x * x + y * y > n)break;
            mp[x * x + y * y]++;
        }
    }
    for (int i = 1;i <= n;i++) {
        if (mp[i] == 1)cnt++;
    }
    cout << cnt << "\n";
    for (int i = 1;i <= n;i++) {
        if (mp[i] == 1)cout << i << " ";
    }
    return 0;
}