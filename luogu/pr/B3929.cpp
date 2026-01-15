#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int q;
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

bool paan(int x) {
  set<int> s;
  for (int i = 0; num[i] * num[i] <= x; i++) {
    for (;x % num[i] == 0;) {
      s.insert(num[i]);
      x /= num[i];
    }
  }
  if (x > 1) s.insert(x);
  return s.size() == 2;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  init(N);
  cin >> q;
  for (; q--;) {
    int n;
    cin >> n;
    cout << paan(n) << "\n";
  }
  return 0;
}