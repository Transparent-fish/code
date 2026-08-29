#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int Min = 1e18, Max = 0, sum = 0;
    for (int i = 1;i <= n;i++) {
        Min = min(Min, a[i]), Max = max(Max, a[i]);
        sum += Min + Max;
    }
    cout << sum;
    return 0;
}