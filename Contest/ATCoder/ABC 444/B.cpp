#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, cnt;

int Sum(int x) {
    int sum = 0;
    for (;x;) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        if (Sum(i) == k)cnt++;
    }
    cout << cnt;
    return 0;
}