#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, ans, a[N];
priority_queue<int> q;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        q.push(a[i]);
        if (q.top() != a[i]) {
            ans += q.top() - a[i];
            q.pop(), q.push(a[i]);
        }
    }
    cout << ans;
    return 0;
}