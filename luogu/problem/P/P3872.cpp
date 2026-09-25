#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans;
bool vis[N];

struct node {
    int q, w;
    friend bool operator<(node a, node b) {
        return a.w > b.w;
    }
}a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].q;
    }
    for (int i = 1;i <= n;i++) {
        cin >> a[i].w;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= n;i++) {
        for (int j = a[i].q;j > 0;j--) {
            if (!vis[j]) {
                vis[j] = 1;
                ans += a[i].w;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}