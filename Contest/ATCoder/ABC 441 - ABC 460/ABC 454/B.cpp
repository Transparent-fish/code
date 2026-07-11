#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];
set<int>s;

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    if (s.size() == n)cout << "Yes\n";
    else cout << "No\n";
    if (s.size() == m)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}