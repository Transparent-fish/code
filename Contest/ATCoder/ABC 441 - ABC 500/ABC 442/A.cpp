#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt;
string s;

signed main() {
    cin >> s;
    for (int i = 0;i < s.size();i++) {
        if (s[i] == 'i' || s[i] == 'j')cnt++;
    }
    cout << cnt << "\n";
    return 0;
}