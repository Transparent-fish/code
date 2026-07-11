#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

char Get(char c) {
    if (c >= 'a' && c <= 'c') return '2';
    if (c >= 'd' && c <= 'e') return '3';
    if (c >= 'd' && c <= 'f') return '3';
    if (c >= 'g' && c <= 'i') return '4';
    if (c >= 'j' && c <= 'l') return '5';
    if (c >= 'm' && c <= 'o') return '6';
    if (c >= 'p' && c <= 's') return '7';
    if (c >= 't' && c <= 'v') return '8';
    if (c >= 'w' && c <= 'z') return '9';
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        cout << Get(s[0]);
    }
    return 0;
}