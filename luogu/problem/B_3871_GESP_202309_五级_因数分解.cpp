#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int>a;

void Cnt(int x) {
    int cnt = 0;
    for (int i = 2;i <= sqrt(x);i++) {
        if (x % i == 0) {
            cnt = 0;
            for (;x % i == 0;) {
                x /= i;
                cnt++;
            }
            if (cnt == 1)cout << i;
            else cout << i << "^" << cnt;
            if (n > 1)cout << " * ";
        }
    }
    if (n > 1)cout << x;
}

signed main() {
    cin >> n;
    Cnt(n);
    return 0;
}