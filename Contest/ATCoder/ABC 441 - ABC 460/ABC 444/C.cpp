#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];
vector<int>s;

bool check(int x) {
    if (x < a[n])return 0;
    int l = 1, r = n;
    for (;l <= r;) {
        if (a[r] == x)r--;
        else {
            if (l >= r || a[l] + a[r] != x)return 0;
            l++, r--;
        }
    }
    return 1;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (check(a[n]))s.push_back(a[n]);
    if (check(a[1] + a[n]))s.push_back(a[1] + a[n]);
    sort(s.begin(), s.end());
    for (auto i : s)cout << i << " ";
    return 0;
}