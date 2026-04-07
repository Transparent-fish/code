#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
set<int>id;

struct node {
    int x, y;
}a[N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1;i <= m;i++) {    
        bool pan = 1;
        for (int dx = -1;dx <= 1;dx++) {
            for (int dy = -1;dy <= 1;dy++) {
                int nx = a[i].x + dx, ny = a[i].y + dy;
                if (nx >= 1 && nx <= n - 1 && ny >= 1 && ny <= n - 1) {
                    if (id.count((nx * (n + 1) + ny))) {
                        pan = 0;
                        break;
                    }
                }
            }if (!pan)break;
        }
        if (pan) {
            id.insert((a[i].x * (n + 1)) + a[i].y);
        }
    }
    cout << id.size();
    return 0;
}