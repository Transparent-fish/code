#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
    string s;
    int cnt, id;
    friend bool operator<(node a, node b) {
        return a.cnt * b.id > b.cnt * a.id;
    }
}e[N];

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> e[i].s;
        e[i].cnt = 0, e[i].id = 0;
        for (int j = 0; j < e[i].s.size(); j++) {
            if (e[i].s[j] == 'X') e[i].cnt++;
            else e[i].id += e[i].s[j] - '0';
        }
    }
    sort(e + 1, e + n + 1);
    int ans = 0, cntX = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].s.size(); j++) {
            if (e[i].s[j] == 'X') cntX++;
            else ans += cntX * (e[i].s[j] - '0');
        }
    }
    cout << ans;
    return 0;
}