#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N];
map<int, int>mp, mpp;

void Scanf() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

void init() {
    for (int i = 1;i <= n;i++) {
        if (a[i] % 7 == 0)mp[a[i] / 7]++;
        if (a[i] % 3 == 0)mpp[a[i] / 3]++;
        if (a[i] % 5 != 0)continue;
        ans += mp[a[i] / 5] * mpp[a[i] / 5];
    }
    mp.clear(), mpp.clear();
}

void Printf() {
    for (int i = n;i >= 1;i--) {
        if (a[i] % 7 == 0)mp[a[i] / 7]++;
        if (a[i] % 3 == 0)mpp[a[i] / 3]++;
        if (a[i] % 5 != 0)continue;
        ans += mp[a[i] / 5] * mpp[a[i] / 5];
    }
    cout << ans;
}

signed main() {
    Scanf(), init(), Printf();
    return 0;
}