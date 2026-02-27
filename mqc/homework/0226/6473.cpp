#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, tree[N], tag[N], a[N];

void pushup(int rt) { tree[rt] = tree[rt << 1] + tree[rt << 1 | 1]; }

void pushdown(int l, int r, int rt) {
  if (tag[rt]) {
    int mid = l + r >> 1;
    tag[rt << 1] += tag[rt], tag[rt << 1 | 1] += tag[rt];
    tree[rt << 1] += tag[rt] * (mid - l + 1);
    tree[rt << 1 | 1] += tag[rt] * (r - mid);
    tag[rt] = 0;
  }
}

void build(int l, int r, int rt) {
  if (l == r) {
    tree[rt] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1), build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}

void update(int l, int r, int rt, int L, int R, int p) {
  if (L <= l && r <= R) {
    tree[rt] += p * (r - l + 1);
    tag[rt] += p;
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(l, r, rt);
  if (L <= mid) update(l, mid, rt << 1, L, R, p);
  if (R > mid) update(mid + 1, r, rt << 1 | 1, L, R, p);
  pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
  if (L <= l && r <= R) {
    return tree[rt];
  }
  int mid = (l + r) >> 1, sum = 0;
  pushdown(l, r, rt);
  if (L <= mid) sum += query(l, mid, rt << 1, L, R);
  if (R > mid) sum += query(mid + 1, r, rt << 1 | 1, L, R);
  // pushup(rt);
  return sum;
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, n, 1);
  for (; m--;) {
    int op, x, y, k;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> k;
      update(1, n, 1, x, y, k);
    } else if (op == 2) {
      cin >> k;
      update(1, n, 1, 1, 1, k);
    } else if (op == 3) {
      cin >> k;
      update(1, n, 1, 1, 1, -k);
    } else if (op == 4) {
      cin >> x >> y;
      cout << query(1, n, 1, x, y) << "\n";
    } else {
      cout << query(1, n, 1, 1, 1) << "\n";
    }
  }
  return 0;
}