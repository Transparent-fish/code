#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
stack<char>sk;

string ck(string s) {
    for (;!sk.empty();) sk.pop();
    for (auto i : s) {
        sk.push(i);
        for (;sk.size() >= 4;) {
            string now = "";
            now.push_back(sk.top()), sk.pop();
            now.push_back(sk.top()), sk.pop();
            now.push_back(sk.top()), sk.pop();
            now.push_back(sk.top()), sk.pop();
            if (now == ")xx(") {
                sk.push('x');
                sk.push('x');
            }
            else {
                reverse(now.begin(), now.end());
                for (auto j : now) {
                    sk.push(j);
                }
                break;
            }
        }
    }
    string now = "";
    for (;!sk.empty();) {
        now += sk.top();
        sk.pop();
    }
    return now;
}

signed main() {
    cin >> t;
    for (;t--;) {
        string s, ss;
        cin >> s >> ss;
        if (ck(s) == ck(ss))cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}