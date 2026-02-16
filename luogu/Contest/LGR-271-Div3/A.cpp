#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans;

struct node {
    string name;
    int rmb;
}a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].name >> a[i].rmb;
        if (a[i].name == "Q")ans += a[i].rmb;
    }
    cout << ans << "\n";
    return 0;
}