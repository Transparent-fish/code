#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans, a[N], mp[N];

struct node {
    int a, b;
};
vector<node> b[N];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int A, D, B;
        cin >> A >> D >> B;
        if (D == 1) a[i] = B;
        else {
            a[i] = A;
            if (A != B) {
                b[D].push_back({ A, B });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (mp[a[i]] == 0) {
            ans++;
        }
        mp[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        for (auto now : b[i]) {
            mp[now.a]--;
            if (mp[now.a] == 0) ans--;
            if (mp[now.b] == 0)ans++;
            mp[now.b]++;
        }
        cout << ans << "\n";
    }
    return 0;
}