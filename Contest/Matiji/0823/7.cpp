#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, las, Max, a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] == -1)cnt++;
        Max = max(Max, a[i]);
    }
    las = n - cnt;
    if (las == cnt) {
        if (Max >= (n >> 1)) {
            for (int i = 1;i <= n;i++) {
                if (a[i] > 0)cout << i << " ";
            }
        }
        else {
            for (int i = 1;i <= n;i++) {
                if (a[i] == -1)cout << i << " ";
            }
        }
    }
    else if (las < cnt) {
        if (Max > (n >> 1)) {
            for (int i = 1;i <= n;i++) {
                if (a[i] > 0)cout << i << " ";
            }
        }
        else {
            for (int i = 1;i <= n;i++) {
                if (a[i] == -1)cout << i << " ";
            }
        }
    }
    else {
        int sum = 0;
        for (int i = 1;i <= n;i++) {
            if (a[i] > 0)sum += a[i];
        }
        if (Max > cnt) {
            for (int i = 1;i <= n;i++) {
                if (a[i] == Max)cout << i << " ";
            }
        }
        else {
            for (int i = 1;i <= n;i++) {
                if (a[i] == -1)cout << i << " ";
            }
        }
    }
    return 0;
}