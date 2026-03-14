#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, l, r, siz, ans;
string s;
vector<int>cnt[N];

signed main() {
    cin >> n >> l >> r >> s;
    for (int i = 0;i < s.size();i++) {
        cnt[s[i] - 'a'].push_back(i);
    }
    for (int i = 0;i < 26;i++) {
        int L = 0, R = 0;
        for (int j = 0;j < cnt[i].size();j++) {
            for (;L<j && cnt[i][j] - cnt[i][L]>r;)L++;
            for (;R < j && cnt[i][j] - cnt[i][R] >= l;)R++;
            // cout << l << " " << r << "\n";
            ans += R - L;
        }
    }
    cout << ans << "\n";
    return 0;
}