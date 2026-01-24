#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

bool ck(int x) {
    unordered_set<int> s;
    for (;x != 1;) {
        if (s.count(x)) return 0;
        s.insert(x);
        int sum = 0;
        for (;x > 0;) {
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        x = sum;
    }
    return 1;
}

signed main() {
    cin >> n;
    if (ck(n))cout << "Yes";
    else cout << "No";
    return 0;
}