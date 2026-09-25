#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N], cnt[N];
map<int, int>mp;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1;i <= 100;i++) {
        if (mp[i] % 2 == 1) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}