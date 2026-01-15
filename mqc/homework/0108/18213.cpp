#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N];
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int x = a[1];
  for (int i = 2; i <= n; i++) {
    if (a[i] != x) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}