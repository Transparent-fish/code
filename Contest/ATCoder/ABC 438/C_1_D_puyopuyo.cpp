#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];

struct node {
    int v, l;
};

stack<node>sk;

void asd() {
    for (;!sk.empty() && sk.top().l >= 4;) {
        sk.top().l -= 4;
        if (sk.top().l == 0) {
            node now = sk.top();
            sk.pop();
            if (!sk.empty() && sk.top().v == now.v)sk.top().l += now.l;
        }
    }
}

void Printf() {
    int ans = 0;
    for (;!sk.empty();) {
        ans += sk.top().l;
        sk.pop();
    }
    cout << ans;
}

void Scanf() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

signed main() {
    Scanf();
    for (int i = 1;i <= n;i++) {
        if (sk.empty() || sk.top().v != a[i]) {
            sk.push({ a[i],1 });
        }
        else {
            sk.top().l++;
        }
        asd();
    }Printf();
    return 0;
}