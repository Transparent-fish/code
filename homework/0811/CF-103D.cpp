#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int n, m, len, nl, nr, a[N], id[N], cnt[N], c[N], Sum[N];
vector<int> d, noow[1005];

struct node {
    int l, r, idd;
}q[N];

struct Output {
    int x, y;
}now, ans[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    cin >> m;
    len = sqrt(n) + 1;
    for (int i = 1;i <= m;i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idd = i;
        if (q[i].r < len) noow[q[i].r].push_back(i);
        else d.push_back(i);
    }
    for (int b = 1; b < len; b++) {
        if (noow[b].empty()) continue;
        for (int i = n; i >= 1; i--) {
            Sum[i] = c[i];
            if (i + b <= n) Sum[i] += Sum[i + b];
        }
        for (auto c : noow[b]) {
            ans[c].x = Sum[q[c].l];
        }
    }
    for (auto i : d) {
        int sum = 0;
        for (int j = q[i].l; j <= n; j += q[i].r) {
            sum += c[j];
        }
        ans[i].x = sum;
    }
    for (int i = 1;i <= m;i++) {
        cout << ans[i].x << "\n";
    }
    return 0;
}
