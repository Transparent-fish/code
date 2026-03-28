#include<bits/stdc++.h>
using namespace std;
#define int long long
int q;
multiset<int>s;

signed main() {
    cin >> q;
    for (;q--;) {
        int op, h;
        cin >> op >> h;
        if (op == 1)s.insert(h);
        else {
            if (s.upper_bound(h) != s.begin()) {
                s.erase(s.begin(), s.upper_bound(h));
            }
        }
        cout << s.size() << "\n";
    }
    return 0;
}