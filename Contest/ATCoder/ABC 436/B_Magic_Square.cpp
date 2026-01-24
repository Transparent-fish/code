#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, l, r, a[N][N];

int main() {
    cin >> n;
    l = 0, r = n / 2;
    for (int i = 1;i <= n * n;i++) {
        a[l][r] = i;
        int ll = l, lr = r, nl = (l - 1 + n) % n, nr = (r + 1) % n;
        if (a[nl][nr] != 0) {
            nl = (ll + 1) % n;
            nr = lr;
        }   
        l = nl, r = nr;
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}