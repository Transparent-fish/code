#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353, N = 1005;
int n, m, na[N];
string s[N][N];

string add(string a, string b) {
    string ans;
    int na[N] = { 0 }, nb[N] = { 0 };
    int la = a.size(), lb = b.size();
    for (int i = 0;i < la;i++) na[la - 1 - i] = a[i] - '0';
    for (int i = 0;i < lb;i++) nb[lb - 1 - i] = b[i] - '0';
    int lmax = la > lb ? la : lb;
    for (int i = 0;i < lmax;i++) na[i] += nb[i], na[i + 1] += na[i] / 10, na[i] %= 10;
    if (na[lmax]) lmax++;
    for (int i = lmax - 1;i >= 0;i--) ans += na[i] + '0';
    return ans;
}

string mul(string a, int b) {
    string ans;
    int La = a.size();
    fill(na, na + N, 0);
    for (int i = La - 1;i >= 0;i--) na[La - i - 1] = a[i] - '0';
    int w = 0;
    for (int i = 0;i < La;i++) na[i] = na[i] * b + w, w = na[i] / 10, na[i] = na[i] % 10;
    while (w) na[La++] = w % 10, w /= 10;
    La--;
    while (La >= 0) ans += na[La--] + '0';
    return ans;
}

void init() {
    for (int i = 1; i <= 100; i++)s[i][1] = "1";
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = add(s[i - 1][j - 1], mul(s[i - 1][j], j));
        }
    }
}

signed main() {
    init();
    for (;cin >> n >> m;) {
        if (n < m)cout << "0\n";
        else cout << s[n][m] << "\n";
    }
    return 0;
}

// @pid 34 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
