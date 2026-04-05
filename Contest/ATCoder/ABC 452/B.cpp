#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 15;
int n, m;
char a[N][N];

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (i == 1 || i == n || j == 1 || j == m)cout << "#";
            else cout << ".";
        }
        cout << "\n";
    }
    return 0;
}