#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 125;
int q, cnt, a[1005][N][N][2];//0:r 1:l
bool vis[1005][N][N];

struct Input {
    int t, x, y;
    friend bool operator<(Input a, Input b) {
        return a.t < b.t;
    }
}in[1005];

signed main() {
    freopen("darksideofthemoon.in", "r", stdin);
    freopen("darksideofthemoon.out", "w", stdout);
    cin >> q;
    for (int i = 1;i <= q;i++) {
        cin >> in[i].t >> in[i].x >> in[i].y;
    }
    return 0;
}