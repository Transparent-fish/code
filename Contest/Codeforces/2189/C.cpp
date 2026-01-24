#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, a[N];

signed main() {
    cin >> T;
    for (;T--;) {
        int n, i = 0;
        cin >> n;
        for (;i < n;) {
            int now = 0;
            for (;(1LL << (now + 1)) <= i;)now++;
            int noow = (1LL << (now + 1)) - 1;
            noow = min(noow, n - 1);
            for (int j = i; j <= noow; j++) {
                a[j + 1] = noow - (j - i) + 1;
            }
            i = noow + 1;
        }
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}