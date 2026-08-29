#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, res, ans, a[N], b[N], c[N << 1], h[N];
int cnt[N], pos[N], now[N];
set<pair<int, int>> s;

bool check(int x, int y) {
    int ex = 0, ey = 0, sx = cnt[x], sy = cnt[y];
    int com = 0;
    for (;ex < sx && ey < sy;) {
        if (c[h[x] + ex] == c[h[y] + ey]) com++, ex++, ey++;
        else if (c[h[x] + ex] < c[h[y] + ey]) ex++;
        else ey++;
    }
    return sx + sy - com >= m;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]]++, cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        h[i] = h[i - 1] + cnt[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        c[h[a[i]] + pos[a[i]]++] = i;
        c[h[b[i]] + pos[b[i]]++] = i;
    }
    for (int x = 1; x <= n; x++) {
        int noow = 0;
        now[x] = -1;
        for (int i = 1; i <= m; i++) {
            if (noow < cnt[x] && c[h[x] + noow] == i) noow++;
            else {
                now[x] = i;
                break;
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        if (now[x] == -1) res++;
    }
    ans = res * (res - 1) / 2 + res * (n - res);
    for (int x = 1; x <= n; x++) {
        if (now[x] == -1) continue;
        int cc[2] = { a[now[x]], b[now[x]] };
        for (int k = 0; k < 2; k++) {
            int y = cc[k], u = min(x, y), v = max(x, y);
            if (y == x || now[y] == -1 || !s.insert({ u, v }).second) continue;
            if (check(u, v)) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
