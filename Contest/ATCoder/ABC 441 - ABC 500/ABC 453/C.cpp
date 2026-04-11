#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N];

void dfs(int now, double noow, int cnt) {
    if (now == n + 1){
        ans = max(ans, cnt);
        return;
    }
    dfs(now + 1, noow + a[now], cnt + ((noow * (noow + a[now]) < 0) ? 1 : 0));
    dfs(now + 1, noow - a[now], cnt + ((noow * (noow - a[now]) < 0) ? 1 : 0));
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dfs(1, 0.5, 0);
    cout << ans << "\n";
    return 0;
}