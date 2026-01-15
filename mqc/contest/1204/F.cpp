#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k;

struct node {
  int l, r;
  friend bool operator<(node a, node b) { return a.r < b.r; }
} a[N];

signed main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].l >> a[i].r;
  }
  sort(a + 1, a + n + 1);
  int las = -1, cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i].l >= las) {
      las = a[i].r;
      cnt++;
    }
  }
  cout << cnt * k;
  return 0;
}