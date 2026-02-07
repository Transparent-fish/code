#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, Max, a[N];
string ans;
map<int, int>mp;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mp[a[i]]++;
        Max = max(Max, a[i]);
    }
    int tot = n, jingwei = 0;
    for (int i = 1;i <= Max;i++) {
        ans += to_string((tot + jingwei) % 10);
        jingwei = (tot + jingwei) / 10;
        // cout << ans << " " << jingwei << " " << tot << "\n";
        tot -= mp[i];
    }
    // cout << ans << "\n";
    for (;jingwei > 0;) {
        ans += to_string(jingwei % 10);
        jingwei /= 10;
    }
    // reverse(ans.begin(), ans.end());
    // cout << ans << "\n";
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}