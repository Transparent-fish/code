#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], b[N], cnt[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]]++, cnt[b[i]]++;
    }
    for (int i = 1;i <= n;i++) {
        if (n - cnt[i] - 1 < 3)cout << "0 ";
        else cout << (n - cnt[i] - 1) * (n - cnt[i] - 2) * (n - cnt[i] - 3) / 6 << " ";
    }
    return 0;
}