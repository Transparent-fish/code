#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, len, a[N], id[N], nex[N], cnt[N];

void update(int x) {
    int l = id[x] * len, r = min((id[x] + 1) * len - 1, n - 1);
    for (int i = r;i >= l;i--) {
        if (i + a[i] >= n) {
            nex[i] = -1, cnt[i] = 1;
        }
        else if (id[i] == id[i + a[i]]) {
            nex[i] = nex[i + a[i]], cnt[i] = cnt[i + a[i]] + 1;
        }
        else {
            nex[i] = i + a[i], cnt[i] = 1;
        }
    }
}

int query(int x) {
    int ans = 0;
    for (;x != -1;) {
        ans += cnt[x], x = nex[x];
    }
    return ans;
}

void init() {
    for (int i = n - 1;i >= 0;i--) {
        if (i + a[i] >= n) {
            nex[i] = -1, cnt[i] = 1;
        }
        else if (id[i] == id[i + a[i]]) {
            nex[i] = nex[i + a[i]], cnt[i] = cnt[i + a[i]] + 1;
        }
        else {
            nex[i] = i + a[i], cnt[i] = 1;
        }
    }
}

signed main() {
    cin >> n;
    len = sqrt(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        id[i] = i / len;
    }
    init();
    cin >> q;
    for (;q--;) {
        int op, l, r;
        cin >> op >> l;
        if (op == 1)cout << query(l) << "\n";
        else {
            cin >> r;
            a[l] = r, update(l);
        }
    }
    return 0;
}

// @pid 189 @tid 6a799752f80e134e78225d60 @lang cc.cc14o2
