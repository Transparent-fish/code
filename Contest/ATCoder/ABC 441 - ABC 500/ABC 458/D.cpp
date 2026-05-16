#include <bits/stdc++.h>
using namespace std;
#define int long long
int x, q;
multiset<int>s;

signed main() {
    cin >> x >> q;
    auto now = s.insert(x);
    for (;q--;) {
        int u, v;
        cin >> u >> v;
        s.insert(u), s.insert(v);
        if (u < *now && v < *now) now--;
        else if (u >= *now && v >= *now)now++;
        cout << *now << "\n";
    }
    return 0;
}