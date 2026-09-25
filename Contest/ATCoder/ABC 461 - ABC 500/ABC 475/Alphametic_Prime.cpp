#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20 + 5;
int a[N], b[N];
string s;
vector<bool> p(10000000, 1);
vector<int> c;
bool pan = 0;

bool check(int x) {
    if (x < 2)return 0;
    return p[x];
}

void dfs(int x) {
    if (pan)return;
    if (x == c.size()) {
        if (a[s[0] - 'a'] == 0)return;
        int d = 0;
        for (int i = 0; i < s.size(); i++) {
            d = d * 10 + a[s[i] - 'a'];
        }
        if (check(d)) {
            cout << d, pan = 1;
        }
        return;
    }
    for (int i = 0; i <= 9; i++) {
        if (b[i] != -1)continue;
        a[c[x]] = i, b[i] = c[x];
        dfs(x + 1);
        a[c[x]] = -1, b[i] = -1;
    }
}

signed main() {
    cin >> s;
    p[0] = p[1] = 0;
    for (int i = 2; i * i < 10000000; i++) {
        if (!p[i])continue;
        for (int j = i * i; j < 10000000; j += i) {
            p[j] = 0;
        }
    }
    memset(a, -1, sizeof a), memset(b, -1, sizeof b);
    for (int i = 0; i < s.size(); i++) {
        int d = s[i] - 'a';
        bool pan = 0;
        for (int j = 0; j < c.size(); j++) {
            if (c[j] == d) {
                pan = 1;
                break;
            }
        }
        if (!pan)c.push_back(d);
    }
    dfs(0);
    if (!pan)cout << -1;
    return 0;
}
