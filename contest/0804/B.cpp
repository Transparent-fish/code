#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int T, n, r, a, b, id, f[N];

void solve() {
    cin >> n >> r >> a >> b;
    f[0] = id = 0;
    for (int i = 1;i <= n;i++) {
        f[i] = max(f[id], i * r) + a + b * (i - id);
        for (;max(f[id], (i + 1) * r) - id * b >= max(f[id + 1], (i + 1) * r) - (id + 1) * b && id < i;)id++;
    }
    cout << f[n] << "\n";
}

signed main() {
#ifdef __linux__
    freopen("pipeline.in", "r", stdin);
    freopen("pipeline.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    for (;T--;) solve();
    return 0;
}