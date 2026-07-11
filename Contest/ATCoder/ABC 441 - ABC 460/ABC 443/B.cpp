#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, cnt, sum;

signed main() {
    cin >> n >> k;
    for (;sum < k;) {
        sum += (n + cnt);
        if (sum >= k)break;
        cnt++;
    }
    cout << cnt;
    return 0;
}