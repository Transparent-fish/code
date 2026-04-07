#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, l, Min = 1e18;
string s;

void init() {
    s = "";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> q;
    for (;q--;) {
        int op;
        char c;
        // init();
        cin >> op;
        if (op == 1) {
            cin >> c;
            s += c;
            if (c == '(')l++;
            else l--;
            Min = min(Min, l);
        }
        else {
            if (s.back() == '(') l--;
            else l++;
            s.pop_back();
            if (Min < 0) {
                Min = 0;
                int _ = 0;
                for (auto i : s) {
                    if (i == '(') _++;
                    else _--;
                    Min = min(Min, _);
                }
            }
        }
        if (l == 0 && Min >= 0) cout << "Yes\n";
        else cout << "No\n";

    }
    return 0;
}