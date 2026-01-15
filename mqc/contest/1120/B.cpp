#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int T, n, ans;
bool vis[N];

struct node {
  int num, id;
} a[N];

bool cmp(node a, node b) { return a.num < b.num; }

signed main() {
  freopen("permutation.in", "r", stdin);
  freopen("permutation.out", "w", stdout);
  cin >> T;
  for (; T--;) {
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].num;
      a[i].id = i;
      vis[i] = 0;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      int now = 0;
      if (vis[i] == 1 || a[i].id == i) continue;
      int j = i;
      for (; !vis[j];) {
        vis[j] = 1;
        j = a[j].id;
        now++;
      }
      if (now > 0) ans += now - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}