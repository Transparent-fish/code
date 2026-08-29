#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
string s;

signed main() {
    cin >> s;
    for (int i = 0, j = s.size() - 1;i < j;i++, j--) {
        if (s[i] != s[j])cnt++;
    }
    cout << cnt;
    return 0;
}