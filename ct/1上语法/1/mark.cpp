#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MIN = 1e6, MAX = 1e18;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  cout << rt(MIN, MAX);
  cout << flush;
  return 0;
}