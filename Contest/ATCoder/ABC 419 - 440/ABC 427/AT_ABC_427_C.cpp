#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, Min;

struct node {
    int u, v;
};
vector<node>e;

signed main() {
    cin >> n >> m;
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        e.push_back({ u,v });
    }
    Min = 1e18;
    for (int i = 1;i <= (1 << n);i++) {
        int cnt = 0;
        for (auto c : e) {
            if (((i >> c.u - 1) & 1) == ((i >> c.v - 1) & 1))cnt++;
        }
        Min = min(Min, cnt);
    }
    cout << Min;
    return 0;
}