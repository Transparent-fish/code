#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, f[N];

struct node {
  int v, c;
  friend bool operator<(node a, node b) { return a.v < b.v; }
} a[N];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v >> a[i].c;
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = m + a[i].v - 1; j >= a[i].v; j--) {
      f[j] = max(f[j], f[j - a[i].v] + a[i].c);
      ans = max(ans, f[j]);
    }
  }
  cout << ans;
  return 0;
}