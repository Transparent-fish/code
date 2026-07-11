#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, m, sum, cntt, cnt[N], MAx[N], Minn[N];
priority_queue<int, deque<int>, greater<int>>Min;
priority_queue<int, deque<int>>Max;

struct node {
    int c, v;
    friend bool operator<(node a, node b) {
        return a.v > b.v;
    }
}a[N];

signed main() {
    cin >> n >> k >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].c >> a[i].v;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= k;i++) {
        sum += a[i].v;
        if (cnt[a[i].c] == 0)cntt++;
        cnt[a[i].c]++;
        // cout << cnt[a[i].c] << "\n";
    }
    if (cntt >= m) {
        cout << sum << "\n";
        exit(0);
    }
    for (int i = 1; i <= k; i++) {
        Minn[a[i].c]++;
        if (Minn[a[i].c] > 1) Min.push(a[i].v);
    }
    for (int i = k + 1; i <= n; i++) {
        if (cnt[a[i].c] == 0) MAx[a[i].c] = max(MAx[a[i].c], a[i].v);
    }
    for (int i = 1; i <= n; i++) {
        if (MAx[i] > 0) Max.push(MAx[i]);
    }
    int now = m - cntt;
    for (int i = 0;i < now;i++) {
        sum += Max.top() - Min.top();
        Max.pop(), Min.pop();
    }
    cout << sum << "\n";
    return 0;
}