#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n - 2;i++) {
        if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}