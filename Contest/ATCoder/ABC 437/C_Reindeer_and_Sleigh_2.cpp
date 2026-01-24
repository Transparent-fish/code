#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T;

struct node {
    int w, p;
    friend bool operator<(node a, node b) {
        return (a.p + a.w) > (b.p + b.w);
    }
}a[N];

signed main() {
    cin >> T;
    for (; T--;) {
        int n, sum = 0, sum1 = 0, now = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].w >> a[i].p;
            sum1 += a[i].w;
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) {
            if (sum >= sum1) break;
            sum += a[i].p, sum1 -= a[i].w, now = i;
        }
        if (sum >= sum1) cout << n - now << "\n";
        else cout << "0\n";
    }
    return 0;
}
