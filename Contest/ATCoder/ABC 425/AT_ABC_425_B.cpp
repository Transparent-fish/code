#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], vis[N];
set<int>s;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        // s.insert(a[i]);
        if (a[i] != -1) {
            if (s.count(a[i])) {
                cout << "No\n";
                exit(0);
            }
            s.insert(a[i]);
            vis[a[i]] = 1;
        }
    }
    cout << "Yes\n";
    for (int i = 1;i <= n;i++) {
        if (a[i] == -1) {
            for (int j = 1;j <= n;j++) {
                if (vis[j] == 0) {
                    cout << j << " ";
                    vis[j] = 1;
                    break;
                }
            }
        }
        else {
            cout << a[i] << " ";
        }
    }
    return 0;
}