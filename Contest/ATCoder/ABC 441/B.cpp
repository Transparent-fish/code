#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, q;
string s, t;
set<char>a, b;

signed main() {
    cin >> n >> m >> s >> t >> q;
    for (auto i : s) {
        a.insert(i);
    }
    for (auto i : t) {
        b.insert(i);
    }
    for (int i = 1;i <= q;i++) {
        string s;
        bool pan = 0, pann = 0;
        cin >> s;
        for (auto j : s) {
            if (a.count(j) && !b.count(j)) pan = 1;
            if (b.count(j) && !a.count(j))pann = 1;
        }
        if (pan)cout << "Takahashi\n";
        else if (pann)cout << "Aoki\n";
        else cout << "Unknown\n";
    }
    return 0;
}