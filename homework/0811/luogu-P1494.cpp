#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, len, nl, nr, a[N], id[N], cnt[N], c[N];

struct node {
    int l, r, idd;
    friend bool operator<(node a, node b) {
        if (id[a.l] == id[b.l]) {
            if (id[a.l] & 1) return a.r < b.r;
            return a.r > b.r;
        }
        else return id[a.l] < id[b.l];
    }
}q[N];

struct Output {
    int x, y;
}now, ans[N];

void add(int x) {
    x = c[x];
    cnt[x]++;
    if (cnt[x] > 1) {
        now.x = now.x + cnt[x] * (cnt[x] - 1) - (cnt[x] - 1) * (cnt[x] - 2);
    }
}

void del(int x) {
    x = c[x];
    cnt[x]--;
    if (cnt[x] > 0) {
        now.x = now.x + cnt[x] * (cnt[x] - 1) - cnt[x] * (cnt[x] + 1);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    len = sqrt(n) + 1;
    for (int i = 1;i <= n;i++) {
        cin >> c[i];
        id[i] = (i - 1) / len + 1;
    }
    for (int i = 1;i <= m;i++) {
        cin >> q[i].l >> q[i].r;
        q[i].idd = i;
    }
    sort(q + 1, q + m + 1);
    for (int i = q[1].l;i <= q[1].r;i++) {
        add(i);
    }
    now.y = (q[1].r - q[1].l + 1) * (q[1].r - q[1].l);
    nl = q[1].l, nr = q[1].r, ans[q[1].idd] = now;
    for (int i = 2;i <= m;i++) {
        for (;nl > q[i].l;) add(--nl);
        for (;nr < q[i].r;) add(++nr);
        for (;nl < q[i].l;) del(nl++);
        for (;nr > q[i].r;) del(nr--);
        now.y = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l);
        ans[q[i].idd] = now;
    }
    for (int i = 1;i <= m;i++) {
        if (ans[i].y == 0)cout << "0/1\n";
        else cout << ans[i].x / __gcd(ans[i].x, ans[i].y) << "/" << ans[i].y / __gcd(ans[i].x, ans[i].y) << "\n";
    }
    return 0;
}

// @pid 193 @tid 6a799752f80e134e78225d60 @lang cc.cc14o2
