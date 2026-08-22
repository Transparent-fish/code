#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, Mod = 1e9 + 7;
int n, nex[N], cnt[N];
string s;

signed main() {
    cin >> n;
    for (;n--;) {
        cin >> s;
        s = "&" + s;
        memset(nex, 0, sizeof nex);
        memset(cnt, 0, sizeof cnt);
        int j = 0, ans = 1;
        cnt[1] = 1;
        for (int i = 2;i < s.size();i++) {
            for (; j > 0 && s[j + 1] != s[i];) j = nex[j];
            if (s[j + 1] == s[i]) j++;
            nex[i] = j, cnt[i] = cnt[j] + 1;
        }
        j = 0;
        // for (int i = 1;i <= s.size();i++)cout << cnt[i] << " ";
        for (int i = 2;i < s.size();i++) {
            // j = nex[i];
            for (;j && s[j + 1] != s[i];) {
                j = nex[j];
            }
            if (s[j + 1] == s[i]) j++;
            for (;j * 2 > i;)j = nex[j];
            ans *= (cnt[j] + 1) % Mod, ans %= Mod;
        }
        cout << ans << "\n";
    }
    return 0;
}