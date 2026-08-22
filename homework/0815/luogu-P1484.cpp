#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, ans, cnt, a[N], l[N], r[N], vis[N];
priority_queue<pair<int, int>>q;

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        l[i] = i - 1, r[i] = i + 1;
        q.push({ a[i],i });
    }
    l[1] = 0, r[n] = n + 1;
    for (;!q.empty();) {
        auto now = q.top();
        int i = now.second;
        q.pop();
        if (now.first <= 0) break;
        if (vis[now.second]) continue;
        ans += now.first;
        q.push({ a[i] = a[l[i]] + a[r[i]] - now.first, i });
        vis[l[i]] = vis[r[i]] = 1;
        l[i] = l[l[i]], r[i] = r[r[i]];
        l[r[i]] = i, r[l[i]] = i;
        if ((++cnt) >= k) break;
    }
    cout << ans;
    return 0;
}