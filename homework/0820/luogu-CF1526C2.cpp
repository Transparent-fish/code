#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, cnt, now, a[N];
priority_queue<int>q;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        if (a[i] < 0) q.push(-a[i]);
        now += a[i], cnt++;
        if (now < 0 && !q.empty()) {
            now += q.top(), cnt--, q.pop();
        }
    }
    cout << cnt;
    return 0;
}