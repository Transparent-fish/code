#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 1e6, MAX_AI = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n = rt(1000, MAX_N);
  cout << n << "\n";
  for (int i = 1; i <= n; i++) {
    cout << rt(1000, MAX_AI) << " ";
  }
  cout << flush;
  return 0;
}