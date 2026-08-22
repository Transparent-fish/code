#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.b < b.b;
    }
}a[N];
priority_queue<int>q;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b;
    }
    sort(a + 1, a + n + 1);
    int sum = 0, cnt = 0;
    for (int i = 1;i <= n;i++) {
        // if (!q.empty()) {
            sum += a[i].a;
            q.push(a[i].a);
            if (sum <= a[i].b) {
                cnt++;
            }
            else {
                sum -= q.top();
                q.pop();
            }
        // }
    }
    cout << cnt;
    return 0;
}

// @pid 13 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
