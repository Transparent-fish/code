#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int cnt, a, b, c;
string s;

signed main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') {
            a = (a + (b + c + 1) % mod) % mod;
        }
        else if (s[i] == 'b') {
            b = (b + (a + c + 1) % mod) % mod;
        }
        else if (s[i] == 'c') {
            c = (c + (a + b + 1) % mod) % mod;
        }
    }
    cout << (a + b + c) % mod << "\n";
    return 0;
}