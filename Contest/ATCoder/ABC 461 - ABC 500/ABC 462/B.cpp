#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, k[N];
vector<int>ans[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++) {
            int x;
            cin >> x;
            ans[x].push_back(i);
        }
    }
    for (int i = 1;i <= n;i++) {
        cout << ans[i].size() << " ";
        for (int j = 0;j < ans[i].size();j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}