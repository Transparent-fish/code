#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt, a[N];
int d[8][2] = { 0,1,0,-1,1,0,-1,0 ,1,1,1,-1,-1,1,-1,-1 };
string s;
queue<int> q;

int Get(int x, int y) {
    return (x - 1) * m + (y - 1);
}

void bfs() {
    if (cnt == 0 || cnt == n * m) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << '.';
            }
            cout << "\n";
        }
        exit(0);
    }
    for (;!q.empty();) {
        int now = q.front();
        q.pop();
        int cx = now / m + 1, cy = now % m + 1;
        for (int i = 0; i < 8; i++) {
            int nx = cx + d[i][0], ny = cy + d[i][1];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                int nid = Get(nx, ny);
                if (a[nid] == -1) {
                    a[nid] = a[now] + 1;
                    q.push(nid);
                }
            }
        }
    }
}

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            int id = Get(i, j);
            a[id] = -1;
            if (s[j - 1] == '#') {
                a[id] = 0;
                q.push(id);
                cnt++;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = Get(i, j);
            if (a[id] % 2 == 0) cout << '#';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}