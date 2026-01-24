#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int cnt, ans;
string s;

struct node {
    char c;
    int b;
}a[N];

signed main() {
    cin >> s;
    for (int i = 0;i < s.size();) {
        char now = s[i];
        int j = i;
        for (;j < s.size() && s[j] == now;) {
            j++;
        }
        a[++cnt] = { now,j - i };
        i = j;
    }
    for (int i = 1;i < cnt;i++) {
        if (a[i].c + 1 == a[i + 1].c) {
            ans += min(a[i].b, a[i + 1].b);
        }
    }
    cout << ans;
    return 0;
}