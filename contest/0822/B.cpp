#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 5;
int n, sumX, sumY;
vector<int>c, cc, ans;

struct node {
    int x, y, id;
    friend bool operator<(node a, node b) {
        return a.x > b.x;
    }
}a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
#ifdef __linux__
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].x >> a[i].y;
        sumX += a[i].x, sumY += a[i].y, a[i].id = i;
    }
    if (sumX != sumY) {
        cout << "-1";
    }
    else {
        int nowX = 0, nowY = 0;
        sort(a + 1, a + n + 1);
        for (int i = 1;i <= (n >> 1);i++) {
            if (nowX < (sumX >> 1)) {
                nowX += a[i].x;
                c.push_back(a[i].id);
            }
        }
        for (int i = (n >> 1 | 1);i <= n;i++) {
            if (nowY < (sumY >> 1)) {
                nowY += a[i].y;
                cc.push_back(a[i].id);
            }
        }
    }
    int now = 0, id = 0, idd = 0;
    for (int i = 1;i <= n;i++) {
        if (now == 0) {
            now = 1;
            cout << c[++id] << " ";
        }
        else {
            now = 0;
            cout << cc[++idd] << " ";
        }
    }
    return 0;
}