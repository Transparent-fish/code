#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, a[N], s[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int now;
        cin >> now;
        if (now > 0)a[++cnt] = now;
    }
    return 0;
}