#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

bool pan(int l, int x, int r) { return l <= x && x <= r; }

signed main() {
  // assert(pan(0, x, 1e18));
  int T = rt(1, 100), num;
  cout << T << "\n";
  cin >> num;
  for (; T--;) {
    if (num <= 2)
      cout << rt(1, 100);
    else if (num > 2 && num <= 10)
      cout << rt(1000, 20000);
    else
      cout << rt(2000, 100000);
    cout << endl;
  }
  return 0;
}

/*
20
2 10 8
*/