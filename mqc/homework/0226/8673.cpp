#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int t, mod, tree[N], tag[N];

void pushup(int rt) {
  tree[rt] = tree[rt << 1] * tree[rt << 1 | 1];
  tree[rt] %= mod;
}

void build(int l, int r, int rt) {
  if (l == r) {
    tree[rt] = l;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt), build(mid + 1, r, rt), pushup(rt);
}

void update(int l, int r, int rt, int p, int c) {
  if (l == r) {
    tree[rt] /= c;
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid)
    update(l, mid, rt << 1, p, c);
  else
    update(mid + 1, r, rt << 1 | 1, p, c);
}

signed main() {
  cin >> t;
  for (; t--;) {
    int q, m;
    cin >> q >> m;
    build(1, q, 1);
    for (int i = 1; i <= 1; i++) {
      
    }
  }
  return 0;
}