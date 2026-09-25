#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];
multiset<int>s;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s.insert(a[i]);
        if (s.size() > 3) s.erase(s.begin());
        if (i >= 3)cout << *s.begin() << "\n";
    }
    return 0;
}