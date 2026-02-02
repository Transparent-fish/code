#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  freopen("pingpang.in", "r", stdin);
  freopen("pingpang.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a >> a >> a;
  }
  cin >> n;
  for (; n--;) {
    if (rt(1, 114514) % 3 == 1)
      cout << "Win\n";
    else if (rt(1, 114514) % 3 == 2)
      cout << "Draw\n";
    else
      cout << "Lose\n";
  }
  return 0;
}