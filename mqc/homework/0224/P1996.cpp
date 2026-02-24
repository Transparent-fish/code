#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, cnt;
queue<int>q;

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        q.push(i);
    }
    for (;!q.empty();) {
        ++cnt;
        if (cnt % m == 0) {
            // cnt = 0;
            cout << q.front() << " ";
            q.pop();
        }
        else {
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}