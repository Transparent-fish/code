#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DYL
const int N = 1e6 + 5;
int n, c[N], v[N], f[N];

void Scanf() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
  }
}

signed main() {
  Scanf();
  return 0;
}