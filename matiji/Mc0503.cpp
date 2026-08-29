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
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) {
            if (a[i] < a[j])cnt++;
        }
    }
    cout << cnt;
    return 0;
}