#include <bits/stdc++.h>
using namespace std;
#define int long long
#define dou double
const int N = 1e5 + 5;
int H, n, pan, noww;
dou ans, now;
priority_queue<int> q;

struct node {
    int t, h;
    friend bool operator<(node a, node b) {
        return a.t < b.t;
    }
}a[N];

signed main() {
#ifdef __linux__
    freopen("water.in", "r", stdin);
    freopen("water.out", "w", stdout);
#endif
    cin >> H >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].t >> a[i].h;
        if (!a[i].h) pan = 1;
    }
    if (!pan) {
        cout << "-1\n";
        exit(0);
    }
    sort(a + 1, a + n + 1);
    now = H;
    for (int i = 1; i <= n; i++) {
        if (a[i].h >= now) continue;
        for (;ans < a[i].t;) {
            if (q.size()) {
                if (ans + (dou)(now - q.top()) / q.size() < a[i].t) {
                    ans += (dou)(now - q.top()) / q.size(), now = q.top();
                    q.pop();
                }
                else {
                    dou t = (dou)(a[i].t - ans) * q.size();
                    now -= t, ans = a[i].t;
                }
            }
            else {
                ans = a[i].t;
            }
            if (!now) {
                printf("%.6f\n", ans);
                exit(0);
            }
        }
        if (now > a[i].h) q.push(a[i].h);
    }
    for (;q.size();) {
        ans += (dou)(now - q.top()) / q.size();
        now = q.top(), q.pop();
    }
    printf("%.6f\n", ans);
    return 0;
}