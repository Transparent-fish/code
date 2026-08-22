#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, nex[N];

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
    cin >> T;
    for (;T--;) {
        string s;
        cin >> s;
        kmp(s);
        cout << (s.size() % (s.size() - nex[s.size() - 1]) == 0 ? (s.size() - nex[s.size() - 1]) : s.size()) << "\n";
    }
    return 0;
}

// @pid 220 @tid 6a7afe00f80e134e7823401b @lang cc.cc14o2
