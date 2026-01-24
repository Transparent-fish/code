#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int x, y, ans;
unordered_map<int, set<int>>mp;
set<int>s, a;

struct node {
    int x, y;
}b[N];

void Scanf() {
    for (;cin >> x >> y;) {
        s.insert(x), a.insert(y), mp[x].insert(y);
        bool pan = 0;
        for (auto i : s) {
            if (mp[i].size() == a.size()) {
                bool vis = 1;
                for (auto j : a) {
                    if (mp[i].find(j) == mp[i].end()) {
                        vis = 0;
                        break;
                    }
                }
                if (vis) {
                    pan = 1;
                    break;
                }
            }
        }
        if (pan) ans++;
    }
}

void Printf() {
    cout << ans;
}

int main() {
    Scanf(), Printf();
    return 0;
}