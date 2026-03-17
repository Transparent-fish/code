#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;

signed main() {
  cin >> n;
  if (n % 2 == 0) {
    cout << n - (n / 2);
  } else {
    cout << n - (n / 2) + 1;
  }
  return 0;
}

/*
4
*/