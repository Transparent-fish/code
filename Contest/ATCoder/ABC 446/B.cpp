#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, l[N];
bool vis[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> l[i];
        int cnt = 0, pan = 0;
        for (int j = 1;j <= l[i];j++) {
            int now;
            cin >> now;
            if (!pan && !vis[now]) {
                cnt = now;
                vis[now] = 1, pan = 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}