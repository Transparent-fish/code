#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a, b, c, tal, head, x[N], s[N], f[N], q[N];

int X(int x) {
    return s[x];
}

int Y(int i) {
    return f[i] + a * s[i] * s[i] - b * s[i];
}

bool pan(int x, int y, int z) {
    return Y(y) - Y(x) >= -z * (X(y) - X(x));
}

bool pann(int x, int y, int z) {
    return (X(y) - X(x)) * (Y(z) - Y(x)) - (Y(y) - Y(x)) * (X(z) - X(x)) > 0;
}

signed main() {
    cin >> n >> a >> b >> c;
    for (int i = 1;i <= n;i++) {
        cin >> x[i];
        s[i] = s[i - 1] + x[i];
    }
    q[0] = 0;
    for (int i = 1;i <= n;i++) {
        for (;head < tal && pan(q[head], q[head + 1], -2 * a * s[i]);)head++;
        int j = q[head];
        f[i] = a * s[i] * s[i] + b * s[i] + c + Y(j) + (-2 * a * s[i]) * X(j);
        for (;head < tal && pann(q[tal - 1], q[tal], i);) {
            tal--;
        }
        q[++tal] = i;
    }
    cout << f[n];
    return 0;
}