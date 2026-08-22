#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, nex[N];
string now, s[N];

int kmp(string a) {
    string ss = a;
    int len = ss.size();
    nex[0] = 0;
    for (int i = 1; i < len; i++) {
        int j = nex[i - 1];
        for (; j > 0 && ss[i] != ss[j];) j = nex[j - 1];
        if (ss[i] == ss[j]) j++;
        nex[i] = j;
    }
    return nex[len - 1];
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    now = s[1];
    for (int i = 2; i <= n; i++) {
        int len = min(now.size(), s[i].size());
        string a = s[i].substr(0, len) + "#" + now.substr(now.size() - len);
        now += s[i].substr(kmp(a));
    }
    cout << now;
    return 0;
}