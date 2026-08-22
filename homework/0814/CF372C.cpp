#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1.5e6 + 5;
int n, m, d, Max, f[2][N], las[N];
deque<int>q;

struct node {
    int a, b, t;
}a[N];

signed main() {
    cin >> n >> m >> d;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].a >> a[i].b >> a[i].t;
    }
    for (int i = 1; i <= n; i++) {
        f[0][i] = 0;
    }
    int now = 0, noow = 1, cnt = 1;
    a[0].t = 1;
    for (int i = 1;i <= m;i++) {
        swap(now, noow);
        for (;!q.empty();) q.pop_front();
        cnt = 1;
        for (int j = 1; j <= n; j++) {
            for (;cnt <= n && cnt <= j + d * (a[i].t - a[i - 1].t);) {
                for (;!q.empty() && f[noow][q.back()] <= f[noow][cnt];) {
                    q.pop_back();
                }
                q.push_back(cnt);
                cnt++;
            }
            for (;!q.empty() && q.front() < j - d * (a[i].t - a[i - 1].t);) {
                q.pop_front();
            }
            f[now][j] = f[noow][q.front()] + a[i].b - abs(a[i].a - j);
        }
    }
    Max = -1e18;
    for (int i = 1;i <= n;i++) {
        Max = max(Max, f[now][i]);
    }
    cout << Max;
    return 0;
}