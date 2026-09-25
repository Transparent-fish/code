#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s, t;

signed main() {
    cin >> n >> s >> t;
    for (int i = 0;i < s.size();i++) {
        if (t[i] != '*' && s[i] != t[i]) {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
    return 0;
}