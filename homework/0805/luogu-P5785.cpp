#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int n, s, he, ta = -1, t[N], c[N], q[N], dp[N];
int sumt[N], sumc[N];

double k(int x, int y) {
    return (double)(double)(dp[x] - dp[y]) / (sumc[x] - sumc[y]);
}

signed main() {
    cin >> n >> s;
    for (int i = 1;i <= n;i++) {
        cin >> t[i] >> c[i];
        sumt[i] = sumt[i - 1] + t[i], sumc[i] = sumc[i - 1] + c[i];
    }
    q[++ta] = 0;
    for (int i = 1;i <= n;i++) {
        int l = he, r = ta, ans = he;
        for (;l <= r;) {
            int mid = (l + r) >> 1;
            if (mid == ta) {
                ans = ta;
                break;
            }
            if (dp[q[mid + 1]] - dp[q[mid]] >= (sumt[i] + s) * (sumc[q[mid + 1]] - sumc[q[mid]])) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int j = q[ans];
        dp[i] = dp[j] - (sumt[i] + s) * sumc[j] + sumt[i] * sumc[i] + s * sumc[n];
        for (;ta - he >= 1;) {
            int a = q[ta - 1], b = q[ta], c = i;
            if (sumc[i] == sumc[b]) {
                if (dp[i] >= dp[b])goto aaa;
                else {
                    ta--;
                    continue;
                }
            }
            if ((dp[b] - dp[a]) * (sumc[c] - sumc[b]) >= (dp[c] - dp[b]) * (sumc[b] - sumc[a]))ta--;
            else break;
        }
        q[++ta] = i;
    aaa:;
    }
    cout << dp[n];
    return 0;
}

// @pid 80 @tid 6a72d3367c64e169ce051ea9 @lang cc.cc14o2
