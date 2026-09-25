#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, Max, a[N];
map<int, int>mp;

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 1;i <= k;i++) {
        Max = max(Max, mp[i]);
    }
    int ans = 0;
    for (int i = 1;i <= k;i++) {
        if (mp[i] + 1 >= Max)ans++;
    }
    cout << ans;
    return 0;
}