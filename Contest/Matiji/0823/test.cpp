#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, las, Max, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] != -1)cnt += a[i];
        if (a[i] == -1)las++;
        Max = max(Max, a[i]);
    }
    if (cnt / las > Max) {
        for (int i = 1;i <= n;i++) {
            if (a[i] == -1)cout << i << " ";
        }
    }
    else {
        for (int i = 1;i <= n;i++) {
            if (a[i] == Max)cout << i << " ";
        }
    }
    return 0;
}