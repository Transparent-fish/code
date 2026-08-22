#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.a < b.a;
    }
}a[N];
priority_queue<int, vector<int>, greater<int> >q;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1);
    int ans = 0, cnt = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i].a <= q.size()) {
            if (a[i].b > q.top()) {
                ans -= q.top(), ans += a[i].b;
                q.pop(), q.push(a[i].b);
            }
        }
        else {
            q.push(a[i].b);
            ans += a[i].b;
        }
    }
    cout << ans;
    return 0;
}

// @pid 14 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
