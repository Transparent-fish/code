#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e18, MIN = 1e10;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  int num;
  cin >> num;
  if (num == 60) {
    cout << rt(MIN + 1, MAX) << " " << rt(10000000000, MIN);
    exit(0);
  }
  cout << rt(1000000000, MIN) << " " << rt(MIN, MAX);
  cout << flush;
  return 0;
}