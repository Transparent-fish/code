#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];
map<int, int>mp;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        mp[a[i]] = max(mp[a[i]], mp[a[i] - 1] + 1);
    }
    int Max = 0;
    for (auto i : mp) {
        Max = max(Max, i.second);
    }
    cout << Max << "\n";
    return 0;
}

/*
dp[a[i]]=dp[a[i]-1]+1
*/