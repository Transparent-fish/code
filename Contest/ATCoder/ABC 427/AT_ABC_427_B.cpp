#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];

int f(int x) {
    int sum = 0;
    for (;x;) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main() {
    cin >> n;
    a[0] = 1;
    for (int i = 1; i <= n; i++) {
        int _ = 0;
        for (int j = 0; j < i; j++) {
            _ += f(a[j]);
        }
        a[i] = _;
    }
    cout << a[n];
    return 0;
}