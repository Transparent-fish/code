#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int l, n, Min, Max, a[N];

signed main() {
    cin >> l >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    // Min = 1e18;
    for (int i = 1;i <= n;i++) {
        Min = max({ min(a[i], l - a[i] + 1),Min });
        Max = max({ a[i], l - a[i] + 1,Max });
    }
    cout << Min << " " << Max << "\n";
    return 0;
}