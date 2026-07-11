#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, vis;
string s;

signed main() {
    cin >> n >> s;
    for (auto i : s) {
        if (vis == 0 && i == 'o')continue;
        else {
            vis = 1;
            cout << i;
        }
    }
    return 0;
}