#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int n, k, d, x, tp, Seed, a[N], dp[N];
deque<int>q;

inline int rnd() {
    static const int MOD = 1e9;
    return Seed = (1LL * Seed * 0x66CCFF % MOD + 20120712) % MOD;
}

signed main() {
    cin >> n >> k >> d >> x >> tp;
    if (tp == 0) {
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
    }
    else {
        cin >> Seed;
        for (int i = 1;i <= n;i++) {
            a[i] = rnd();
        }
    }
    dp[1] = a[1];
    q.push_back(1);
    for (int i = 2;i <= n;i++) {
        for (;!q.empty() && i - q.front() > x;)q.pop_front();
        dp[i] = dp[q.front()] + a[i] + k + (i - q.front() - 1) * d;
        for (;!q.empty() && dp[i] - i * d <= dp[q.back()] - q.back() * d;)q.pop_back();
        q.push_back(i);
    }
    cout << dp[n];
    return 0;
}