#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, p, q, b[N], c[N];

struct node {
    int a, b;
    friend bool operator<(node A, node B) {
        return A.b < B.b;
    }
}a[N], aa[N];
priority_queue<node>qq;

bool cmp(node x, node y) {
    return x.a > y.a;
}

bool cmpp(node x, node y) {
    return x.b < y.b;
}

bool check(int k) {
    if ((n - p - q) * k >= m)return 1;
    for (;!qq.empty();)qq.pop();
    int now = 1, cnt = 0;
    for (int i = 1;i <= p;i++) {
        for (;now <= m && a[now].a >= b[i];)qq.push(a[now++]);
        for (int j = 1;j <= k && qq.size();j++)qq.pop();
    }
    for (;!qq.empty();) {
        aa[++cnt] = qq.top();
        qq.pop();
    }
    for (int i = now;i <= m;i++) {
        aa[++cnt] = a[i];
    }
    now = 1;
    sort(aa + 1, aa + cnt + 1, cmpp);
    for (int i = 1;i <= q;i++) {
        for (;now <= cnt && aa[now].b <= c[i];)qq.push(aa[now++]);
        for (int j = 1;j <= k && !qq.empty();j++)qq.pop();
    }
    return (((long long)qq.size() + cnt - now + 1) <= (n - p - q) * k);
}

signed main() {
    cin >> n >> m >> p >> q;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].a >> a[i].b;
    }
    for (int i = 1;i <= p;i++) {
        cin >> b[i];
    }
    for (int i = 1;i <= q;i++) {
        cin >> c[i];
    }
    sort(b + 1, b + p + 1, greater<int>());
    sort(a + 1, a + m + 1, cmp);
    sort(c + 1, c + q + 1);
    int l = 1, r = m, ans = -1;
    for (;l <= r;) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}

// @pid 109 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
