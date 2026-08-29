#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, cnt;

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep")cnt += (b - a);
    }
    cout << cnt;
    return 0;
}