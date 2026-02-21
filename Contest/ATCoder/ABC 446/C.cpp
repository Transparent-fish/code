#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, d, a[N], b[N];

struct node {
    int id, tim;
};
deque<node>q;

signed main() {
    cin >> T;
    for (;T--;) {
        cin >> n >> d;
        for (;!q.empty();) {
            q.pop_back();
        }
        for (int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for (int i = 1;i <= n;i++) {
            cin >> b[i];
        }
        for (int i = 1;i <= n;i++) {
            q.push_back({ i,a[i] });
            int now = b[i];
            for (;now > 0 && !q.empty();) {
                if (q.front().tim > now) {
                    q.front().tim -= now;
                    now = 0;
                }
                else {
                    now -= q.front().tim;
                    q.pop_front();
                }
            }
            for (;!q.empty() && i - q.front().id >= d;) {
                q.pop_front();
            }
        }
        int ans = 0;
        for (auto i : q) {
            ans += i.tim;
        }
        cout << ans << "\n";
    }
    return 0;
}