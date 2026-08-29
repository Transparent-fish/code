#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
string s;
vector<int>a;

signed main() {
    cin >> n >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'x') a.push_back(i + 1);
    }
    int cnt = 0, now = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'o') cnt++;
        for (; now < a.size() && a[now] <= i; now++);

        if (cnt == 0) {
            cout << i << "\n";
        }
        else if (now + cnt - 1 < a.size()) {
            cout << a[now + cnt - 1] << "\n";
        }
        else {
            cout << n << "\n";
        }
    }
    return 0;
}