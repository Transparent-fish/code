#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, a[N], tree[N], res;
int b[N], id[N];

int lowbit(int x) { return x & -x; }

void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tree[i] += c;
  }
}

int query(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    res += tree[i];
  }
  return res;
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; b[i] = a[i];
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    id[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  }
  for (int i = 1; i <= n; i++) {
    res += query(n) - query(id[i]); update(id[i], 1);
  }
  cout << res;
  return 0;
}
