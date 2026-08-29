#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans;

signed main() {
    cin >> n;
    vector<int>a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
    }
    vector<int>now(n + 1);
    for (int i = 1;i <= n;i++) {
        now[i] = i;
    }
    do {
        if (now > a && now < b) {
            ans++;
        }
    } while (next_permutation(now.begin() + 1, now.end()));
    cout << ans;
    return 0;
}