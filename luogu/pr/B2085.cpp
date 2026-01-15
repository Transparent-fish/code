#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e8 + 5;
int n, q;
bool vis[N];
vector<int> num;

void init(int n) {
  memset(vis, 1, sizeof(vis));
  vis[0] = vis[1] = 0;
  for (int i = 2; i <= n; i++) {
    if (vis[i]) {
      num.push_back(i);
      if (i * i > n) continue;
      for (int j = i * i; j <= n; j += i) {
        vis[j] = 0;
      }
    }
  }
}

signed main() {
  n = 1e6 + 5;
  init(n);
  int k;
  cin >> k;
  cout << num[k - 1] << "\n";
  return 0;
}