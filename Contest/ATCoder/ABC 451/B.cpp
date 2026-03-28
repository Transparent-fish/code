#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], b[N], ans[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
        ans[a[i]]--, ans[b[i]]++;
    }
    for (int i = 1;i <= m;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}