#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main() {
    cin >> n;
    for (;n--;) {
        string s, ans = "";
        cin >> s;
        if (s[0] >= 'a' && s[0] <= 'z')ans += s[0] - 'a' + 'A';
        for (int i = 1;i < s.size();i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                if (s[i + 1] >= 'a' && s[i + 1] <= 'z')ans += s[i + 1] - 'a' + 'A';
            }
        }
        cout << ans + "\n";
    }
    return 0;
}