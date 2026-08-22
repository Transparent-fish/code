#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q;
string a[N];
map<string, bool>mp;

string check(string s) {
    string ns = "";
    string ans = "";
    for (int j = 0;j < s.size();j++) {
        ns = "";
        for (int k = 0;k < s.size();k++) {
            if (k == j)continue;
            ns += s[k];
        }
        if (binary_search(a + 1, a + n + 1, ns)) {
            if (ans == "" || ns < ans) ans = ns;
        }
    }
    if (ans != "") return ans;
    ns = s;
    for (int j = 0;j < s.size() - 1;j++) {
        swap(ns[j], ns[j + 1]);
        if (binary_search(a + 1, a + n + 1, ns)) {
            if (ans == "" || ns < ans) ans = ns;
        }
        ns = s;
    }
    if (ans != "") return ans;
    return "Not Found";
}

signed main() {
#ifdef __linux__
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);
#endif
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        string s;
        cin >> s;
        mp[s] = 1;
        a[i] = s;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= q;i++) {
        string s;
        cin >> s;
        if (mp[s] == 1) {
            cout << "OK\n";
            continue;
        }
        else {
            cout << check(s) << "\n";
        }
    }
    return 0;
}