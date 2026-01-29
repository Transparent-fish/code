#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_AB = 1e18, MIN_AB = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  cout << rt(MIN_AB, MAX_AB) << " " << rt(MIN_AB, MAX_AB) << "\n";
  cout << flush;
  return 0;
}