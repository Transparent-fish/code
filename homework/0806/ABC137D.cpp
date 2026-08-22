#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, ans;

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.a < b.a;
    }
}a[N];

priority_queue<int> q;

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1);
    int id = 1;
    for (int i = 1; i <= m; i++) {
        for (;id <= n && a[id].a <= i;) {
            q.push(a[id].b);
            id++;
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans;
    return 0;
}

// @pid 19 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
