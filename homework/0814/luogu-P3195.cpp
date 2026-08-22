#include<bits/stdc++.h>
using namespace std;
#define int long long
#define d double
const int N = 1e6 + 5;
int n, l, h, t = -1, a[N], b[N], f[N], q[N], c[N], sum[N];

int X(int x) {
    return f[x] + b[x] * b[x];
}

d k(int x, int y) {
    return (d)(X(x) - X(y)) / (d)(b[x] - b[y]);
}

signed main() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum[i] = sum[i - 1] + c[i];
    }
    b[0] = 1 + l;
    for (int i = 1; i <= n; i++) {
        a[i] = sum[i] + i;
        b[i] = sum[i] + i + 1 + l;
    }
    q[++t] = 0;
    for (int i = 1; i <= n; i++) {
        for (;t > h && k(q[h], q[h + 1]) < 2 * a[i];)h++;
        f[i] = f[q[h]] + (a[i] - b[q[h]]) * (a[i] - b[q[h]]);
        for (;t > h && k(q[t], q[t - 1]) > k(i, q[t - 1]);)t--;
        q[++t] = i;
    }
    cout << f[n];
    return 0;
}