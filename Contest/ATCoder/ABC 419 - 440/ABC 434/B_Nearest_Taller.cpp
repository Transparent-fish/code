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
    for (int i = 1;i <= n;i++) {
        int pan = -1;
        for (int j = i - 1;j >= 1;j--) {
            if (a[j] > a[i]) {
                pan = j;
                break;
            }
        }
        cout << pan << "\n";
    }
    return 0;
}