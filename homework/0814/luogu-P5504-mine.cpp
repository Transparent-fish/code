#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], c[N], f[N];
map<int, int>mp;
vector<int>sk[N];

int Get(int x) {
    return f[x - 1] + a[x] * c[x] * c[x];
}

int Cal(int x, int y) {
    return f[y - 1] + a[x] * (c[x] - c[y] + 1) * (c[x] - c[y] + 1);
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        c[i] = ++mp[a[i]];
    }
    for (int i = 1;i <= n;i++) {
        int now = a[i];
        for (;sk[now].size() >= 2;) {
            int po = sk[now][sk[now].size() - 2], pot = sk[now][sk[now].size() - 1];
            if ((Get(pot) - Get(po)) * (c[i] - c[pot]) <= (Get(i) - Get(pot)) * (c[pot] - c[po]))sk[now].pop_back();
            else break;
        }
        sk[now].push_back(i);
        int l = 0, r = sk[now].size() - 1;
        for (;l < r;) {
            int mid = (l + r) >> 1;
            if (Cal(i, sk[now][mid]) <= Cal(i, sk[now][mid + 1])) l = mid + 1;
            else r = mid;
        }
        f[i] = Cal(i, sk[now][l]);
    }
    cout << f[n];
    return 0;
}