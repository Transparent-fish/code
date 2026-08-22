#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.b > b.b;
    }
}a[N];
priority_queue<node>q;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].a >> a[i].b;
        q.push(a[i]);
    }
    int sum = 0;
    for (int i = 1;i <= n;i++) {
        if (!q.empty()) {
            auto now = q.top();
            q.pop();
            sum += now.a;
            if(sum > now.b){
                cout<<"No\n";
                exit(0);
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}

// @pid 19 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
