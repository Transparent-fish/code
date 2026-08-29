#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
bool vis[N];
string s;

signed main() {
    cin >> n >> m >> s;
    for (int i = 0;i < n;i++) {
        if (s[i] == 'G') {
            int l = max(0LL, i - m), r = min(n - 1, i + m);
            for (int j = l;j <= r;j++)vis[j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0;i < n;i++) {
        if (!vis[i])cnt++;
    }
    cout << cnt;
    return 0;
}