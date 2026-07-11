#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, pan;
char c;

signed main() {
    cin >> n >> c;
    int now = c - 'A';
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s[now] == 'o') {
            pan = 1;
        }
    }
    cout << (pan ? "Yes\n" : "No\n");
    return 0;
}