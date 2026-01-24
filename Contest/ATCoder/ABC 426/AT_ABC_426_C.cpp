#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q;
map<int, int>mp;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    int _ = q;
    for (int i = 1;i <= n;i++) {
        mp[i] = 1;
    }
    for (; _--;) {
        int x, y, cnt = 0;
        cin >> x >> y;
        auto it = mp.begin();
        for (;it != mp.end() && it->first <= x;) {
            cnt += it->second;
            mp[y] += it->second;
            it = mp.erase(it);
        }
        cout << cnt << "\n";
    }
    return 0;
}