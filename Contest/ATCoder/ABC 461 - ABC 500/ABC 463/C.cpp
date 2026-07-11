#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, Max, id, t[N], ans[N];

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.b > b.b;
    }
}a[N];

struct Node {
    int t, id;
    friend bool operator<(Node a, Node b) {
        return a.t > b.t;
    }
}b[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b;
    }
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> b[i].t;
        b[i].id = i;
    }
    sort(a + 1, a + n + 1), sort(b + 1, b + q + 1);
    id = 1;
    for (int i = 1;i <= q;i++) {
        int now = b[i].t;
        for (;id <= n && a[id].b > now;) Max = max(Max, a[id].a), id++;
        ans[b[i].id] = Max;
    }
    for (int i = 1;i <= q;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}