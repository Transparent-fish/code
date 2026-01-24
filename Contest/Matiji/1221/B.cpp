#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
int n, sum, cnt;
bool vis[N];
vector<int> num;

void init(int n) {
    memset(vis, 1, sizeof(vis));
    vis[0] = vis[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            num.push_back(i);
            if (i * i > n) continue;
            for (int j = i * i; j <= n; j += i) { vis[j] = 0; }
        }
    }
}

signed main() {
    cin >> n;
    init(n);
    for (auto i : num) {
        sum += i;
    }
    cout << sum - num.size();
    return 0;
}