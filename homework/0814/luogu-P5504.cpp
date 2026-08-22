#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, tot, a[N], c[N], dp[N], cnt[N];
vector<int> sk[N];

int cal(int x, int y) {
    return dp[y - 1] + a[x] * (c[x] - c[y] + 1) * (c[x] - c[y] + 1);
}

int Get(int j) {
    return dp[j - 1] + a[j] * c[j] * c[j];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = ++cnt[a[i]];
    }
    for (int i = 1; i <= n; i++) {
        int now = a[i];
        for (;sk[now].size() >= 2;) {
            int j2 = sk[now][sk[now].size() - 1], j1 = sk[now][sk[now].size() - 2];
            if ((Get(j2) - Get(j1)) * (c[i] - c[j2]) <= (Get(i) - Get(j2)) * (c[j2] - c[j1])) sk[now].pop_back();
            else break;
        }
        sk[now].push_back(i);
        int l = 0, r = sk[now].size() - 1;
        for (;l < r;) {
            int mid = (l + r) / 2;
            if (cal(i, sk[now][mid]) <= cal(i, sk[now][mid + 1])) l = mid + 1;
            else r = mid;
        }
        dp[i] = cal(i, sk[now][l]);
    }
    cout << dp[n];
    return 0;
}
