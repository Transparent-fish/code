#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, cnt, Sum, a[N], b[N];
map<int, int>mp;

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Sum += a[i];
        mp[a[i]]++;
    }
    for (auto i : mp) {
        if (i.first > 0) b[++cnt] = i.first * i.second;
    }
    sort(b + 1, b + cnt + 1, greater<int>());
    int res = 0;
    for (int i = 1; i <= min(k, cnt); i++) res += b[i];
    cout << Sum - res << "\n";
    return 0;
}