#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N], tree[N];

int lowbit(int x) { return x & -x; }

void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) tree[i] += c;
}

int query(int x) {
  int sum = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    sum += tree[i];
  }
  return sum;
}
signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    update(i, a[i] - a[i - 1]);
  }
  for (; m--;) {
    int op, x, y, k;
    cin >> op >> x;
    if (op == 1) {
      cin >> y >> k;
      update(x, k);
      if (y + 1 <= n) update(y + 1, -k);
    } else {
      cout << query(x) << "\n";
    }
  }
  return 0;
}