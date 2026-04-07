#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int Max, a[N];
string s, ans;

signed main() {
    cin >> s;
    for (auto i : s) {
        a[i - 'a']++;
    }
    for (int i = 0;i < 26;i++) {
        Max = max(Max, a[i]);
    }
    for (auto i : s) {
        if (a[i - 'a'] != Max) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}