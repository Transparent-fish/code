#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, ans, now = 1;

struct node {
  int x, y, t;
} a[N];

bool pan(int x) {
  return abs(a[now].x - a[x].x) + abs(a[now].y - a[x].y) <=
         abs(a[now].t - a[now].t);
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].x >> a[i].y >> a[i].t;
  }
  for (int i = 1; i <= m; i++) {
    if (pan(i) == 1) {
      ans++, now = i;
    }
  }
  cout << ans + 1;
  return 0;
}