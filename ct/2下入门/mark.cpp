#include <bits/stdc++.h>
using namespace std;
#define int long long
const int ER_N = 1e5, MAX_N = 1e6;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int num, T, n;
  cin >> num;
  if (num <= 10) {  // T:1-3 n:1-1e3
    T = rt(1, 3), n = rt(1, 100);
    cout << T << "\n";
    for (; T--;) {
      cout << rt(1, 100) << "\n";
    }
  } else if (num > 10 && num < 30) {  // T:4-6 n:1-1e5
    T = rt(4, 6), n = rt(1, ER_N);
    cout << T << "\n";
    for (; T--;) {
      cout << rt(1, ER_N) << "\n";
    }
  } else {  // T:6-10 n:1e5-1e6
    T = rt(6, 10), n = rt(ER_N, MAX_N);
    cout << T << "\n";
    for (; T--;) {
      n = rt(ER_N, MAX_N);
      cout << n << "\n";
    }
  }
  cout << flush;
  return 0;
}