#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int dp[N];
string a, b, aa, bb;

int lis(string s) {
    for (int i = 0;i < s.size();i++) {
        dp[i] = 1;
    }
    for (int i = 0;i < s.size();i++) {
        for (int j = 0;j < i;j++) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int Max = -1e18;
    for (int i = 0;i <= s.size();i++) {
        Max = max(Max, dp[i]);
    }
    return Max;
}

signed main() {
    cin >> a >> b;
    aa = a, bb = b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << max({
        lis(a + b),
        lis(b + a),
        lis(a + bb),
        lis(bb + a),
        lis(aa + bb),
        lis(bb + aa),
        lis(aa + b),
        lis(b + aa)
        });
    return 0;
}