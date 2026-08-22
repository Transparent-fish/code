#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, ans, a[N], l[N], las[N], nex[N];

struct node {
    int a, b;
    friend bool operator<(node a, node b) {
        return a.b > b.b;
    }
};
priority_queue<node>q;

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i < n;i++) {
        l[i] = a[i + 1] - a[i];
        nex[i] = i + 1, las[i] = i - 1;
    }
    nex[n - 1] = 0;
    for (int i = 1;i < n;i++) {
        q.push({ i,l[i] });
    }
    for (int i = 1;i <= k;i++) {
        auto now = q.top();
        q.pop();
        if (now.b != l[now.a]) {
            k++;
            continue;
        }
        ans += now.b;
        int Las = las[now.a], Lass = nex[now.a];
        nex[now.a] = nex[nex[now.a]];
        las[nex[now.a]] = now.a;
        las[now.a] = las[las[now.a]];
        nex[las[now.a]] = now.a;
        l[now.a] = (Las && Lass) ? min((int)1e9 + 7, l[Las] + l[Lass] - l[now.a]) : 1e9 + 7;
        l[Las] = l[Lass] = 1e9 + 7;
        q.push({ now.a,l[now.a] });
    }
    cout << ans;
    return 0;
}

// @pid 15 @tid 6a6c7ddbbdb36af2d80fa4c1 @lang cc.cc14o2
