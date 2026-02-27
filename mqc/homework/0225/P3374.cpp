#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, tree[N], a[N];

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
    update(i, a[i]);
  }
  for (; m--;) {
    int op, x, y;
    cin >> op >> x >> y;
    if (op == 1) {
      update(x, y);
    } else {
      cout << query(y) - query(x - 1) << "\n";
    }
  }
  return 0;
}