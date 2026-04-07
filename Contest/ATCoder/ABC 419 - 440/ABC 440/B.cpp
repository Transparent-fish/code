#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
    int id, t;
    friend bool operator<(node a, node b) {
        return a.t < b.t;
    }
}a[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].t;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1;i <= 3;i++) {
        cout << a[i].id << " ";
    }
    return 0;
}