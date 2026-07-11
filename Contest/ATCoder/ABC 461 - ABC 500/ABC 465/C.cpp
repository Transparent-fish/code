#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, now;
string s;
deque<int>q;

signed main() {
    cin >> n >> s;
    for (int i = 1;i <= n;i++) {
        char c = s[i - 1];
        if (now) q.push_front(i);
        else q.push_back(i);
        if (c == 'o')now = !now;
    }
    if (now) {
        for (int i = n - 1; i >= 0; i--) {
            cout << q[i] << (i == 0 ? "" : " ");
        }
    }
    else {
        for (int i = 0;i < n;i++) {
            cout << q[i] << " ";
        }
    }
    return 0;
}