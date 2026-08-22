#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, now;
string s;

signed main() {
    cin >> n >> m;
    now = m;
    for (int i = 1;i <= n;i++) {
        cin >> s;
        if (s.find("kirai") != -1) {
            if (now >= 0) now = 0;
        }
        else if (s.find("daishuki") != -1) now += 2;
        else if (s.find("shuki") != -1) now += 1;
        else now -= 1;
    }
    if (now > 0) cout << now - m << "\n";
    else cout << "shuki\n";
    return 0;
}