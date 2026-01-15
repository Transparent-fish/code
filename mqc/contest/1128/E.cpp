#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, a[N], b[N];

void Scanf() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + n + 1), sort(b + 1, b + n);
}

void Printf() {
  for (int i = 1; i < n; i++) {
    if (a[i] > b[i]) {
      cout << -1;
      exit(0);
    }
  }
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] > b[i]) {
      cout << a[i + 1];
      exit(0);
    }
  }
  cout << a[1];
}

signed main() {
  Scanf(), Printf();
  return 0;
}