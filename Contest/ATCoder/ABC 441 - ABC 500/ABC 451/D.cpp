#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, cnt;
string s[N], ans[N];
set<int>ss;

void dfs(int x) {
    string ans;
    if (x != 0) ans = to_string(x);
    for (int i = 1; i <= cnt; i++) {
        string now;
        if (x == 0) now = s[i];
        else now = ans + s[i];
        if (now.size() >= 11) continue;
        if (stoll(now) > 1e9) continue;
        if (ss.find(stoll(now)) == ss.end()) {
            ss.insert(stoll(now));
            dfs(stoll(now));
        }
    }
}

signed main() {
    cin >> n;
    int now = 1;
    for (;now <= 1e9;) {
        s[++cnt] = to_string(now);
        now *= 2;
    }
    dfs(0);
    cnt = 0;
    for (auto i : ss) {
        ans[++cnt] = to_string(i);
    }
    cout << ans[n];
    return 0;
}