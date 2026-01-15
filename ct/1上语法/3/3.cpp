#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N];
bool fl = 0;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == a[i - 1]) {
      fl = 1;
    }
  }
  if (fl == 1) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}