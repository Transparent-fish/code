#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
#define int long long
int n, tree[N];

struct no {
    int h, id;
} a[N];

bool cmp(no x, no y) {
    return x.h > y.h;
}

void up(int x, int y) {
    for (int i = x; i <= n; i += (i & -i)) {
        tree[i] += y;
    }
}

int qu(int x) {
    int res = 0;
    for (int i = x; i; i -= (i & -i)) {
        res += tree[i];
    }
    return res;
}

signed main() {
    // freopen("city.in","r",stdin);
    // freopen("city.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].h;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    long long ans = 0, i = 1;
    while (i <= n) {
        vector<int> pos, ni;
        int j = i;
        while (j <= n && a[j].h == a[i].h) j++;
        for (int k = i; k < j; k++) {
            pos.push_back(a[k].id);
        }
        sort(pos.begin(), pos.end());
        if (i == 1) {
            for (int p : pos) {
                up(p, 1);
            }
        }
        else {
            int q = qu(n), sum = 0, mi = 1e18, pa = 0;
            for (int p : pos) {
                ni.push_back(qu(p - 1));
            }
            for (int v : ni) {
                sum += v;
            }
            int m = pos.size();
            for (int k = 0; k <= m; k++) {
                mi = min(mi, (m - k) * q + 2 * pa - sum);
                if (k < m) pa += ni[k];
            }
            ans += mi;
            for (int p : pos) {
                up(p, 1);
            }
        }
        i = j;
    }
    cout << ans << "\n";
    return 0;
}