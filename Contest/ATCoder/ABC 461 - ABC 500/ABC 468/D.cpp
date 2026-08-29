#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt;
string s;

signed main() {
    cin >> s;
    for (int i = 0;i < s.size();i++) {
        int now = 0;
        for (int l = i, r = i;l >= 0 && r < s.size();l--, r++) {
            if (s[l] != s[r]) now++;
            if (now <= 1)cnt++;
            else break;
        }
    }
    for (int i = 0;i < s.size() - 1;i++) {
        int now = 0;
        for (int l = i, r = i + 1;l >= 0 && r < s.size();l--, r++) {
            if (s[l] != s[r]) now++;
            if (now <= 1)cnt++;
            else break;
        }
    }
    cout << cnt;
    return 0;
}