#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d long double
const int N = 1e6 + 5;
int n, m;
vector<int> e[N];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  return 0;
}