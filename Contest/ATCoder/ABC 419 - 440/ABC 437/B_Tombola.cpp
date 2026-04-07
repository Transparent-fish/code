#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e6 + 5;
int h, w, n, a[N][N], b[N];
set<int>s;

int main() {
    cin >> h >> w >> n;
    for (int i = 1;i <= h;i++) {
        for (int j = 1;j <= w;j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    int Max = -1e9;
    for (int i = 1;i <= h;i++) {
        int cnt = 0;
        for (int j = 1;j <= w;j++) {
            if (s.find(a[i][j]) != s.end()) {
                cnt++;
            }
        }
        Max = max(Max, cnt);
    }
    cout << Max;
    return 0;
}