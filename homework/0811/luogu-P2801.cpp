#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], L[N], R[N], tag[N], tot, len, pos[N];
vector<int> e[N];

void Sort(int x) {
    e[x].clear();
    for (int i = L[x]; i <= R[x]; i++) {
        e[x].push_back(a[i]);
    }
    sort(e[x].begin(), e[x].end());
}

void build() {
    len = sqrt(n);
    tot = (n + len - 1) / len;
    for (int i = 1; i <= tot; i++) {
        L[i] = (i - 1) * len + 1;
        R[i] = min(i * len, n);
    }
    for (int i = 1; i <= tot; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i;
        }
        Sort(i);
    }
}

void update(int l, int r, int k) {
    if (pos[l] == pos[r]) {
        for (int i = l; i <= r; i++) {
            a[i] += k;
        }
        Sort(pos[l]);
        return;
    }
    for (int i = l; i <= R[pos[l]]; i++) a[i] += k;
    Sort(pos[l]);
    for (int i = L[pos[r]]; i <= r; i++) a[i] += k;
    Sort(pos[r]);
    for (int i = pos[l] + 1; i < pos[r]; i++) tag[i] += k;
}

int query(int l, int r, int x) {
    int ans = 0;
    if (pos[l] == pos[r]) {
        for (int i = l; i <= r; i++) {
            if (a[i] + tag[pos[l]] >= x)ans++;
        }
        return ans;
    }
    for (int i = l; i <= R[pos[l]]; i++)
        if (a[i] + tag[pos[l]] >= x)ans++;
    for (int i = L[pos[r]]; i <= r; i++) {
        if (a[i] + tag[pos[r]] >= x) ans++;
    }
    for (int i = pos[l] + 1; i < pos[r]; i++)
        ans += e[i].end() - lower_bound(e[i].begin(), e[i].end(), x - tag[i]);
    return ans;
}

signed main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build();
    for (;q--;) {
        char op;
        int l, r, w;
        cin >> op >> l >> r >> w;
        if (op == 'M') {
            update(l, r, w);
        }
        else {
            cout << query(l, r, w) << "\n";
        }
    }
    return 0;
}

// @pid 187 @tid 6a799752f80e134e78225d60 @lang cc.cc14o2
