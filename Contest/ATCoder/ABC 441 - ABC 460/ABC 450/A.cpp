#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main() {
    cin >> n;
    for (int i = n;i >= 1;i--) {
        if (i == 1)cout << "1";
        else cout << i << ",";
    }
    return 0;
}