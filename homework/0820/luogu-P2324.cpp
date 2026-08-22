#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
string Ans =
"11111"
"01111"
"00*11"
"00001"
"00000";

int Get(string s) {
    int cnt = 0;
    for (int i = 0; i < 25; i++) {
        if (s[i] != '*' && s[i] != Ans[i]) {
            cnt++;
        }
    }
    return cnt;
}

bool dfs(string s, int x, int l, int pre) {
    int h = Get(s);
    if (x + h > l) return 0;
    if (h == 0) return 1;
    int pos = s.find('*');
    int a = pos / 5, b = pos % 5;
    for (int i = 0; i < 8; i++) {
        if (pre + i == 7) continue;
        int nx = a + dx[i], ny = b + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        int npos = nx * 5 + ny;
        string ns = s;
        swap(ns[pos], ns[npos]);
        if (dfs(ns, x + 1, l, i)) return 1;
    }
    return 0;
}

signed main() {
    cin >> T;
    for (;T--;) {
        string s = "";
        for (int i = 1;i <= 5;i++) {
            string row;
            cin >> row;
            s += row;
        }
        if (s == Ans) {
            cout << 0 << '\n';
            continue;
        }
        int ans = -1;
        for (int l = 1; l <= 15; l++) {
            if (dfs(s, 0, l, -1)) {
                ans = l;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}