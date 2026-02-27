#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int k, n, c, tree[N], tag[N];

struct node {
  int s, t, k;
  friend bool operator<(node a, node b) {}
} a[N];

void pushup(int rt) { max(tree[rt] = tree[rt << 1], tree[rt << 1 | 1]); }

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
  return sum;
}
signed main() {
  cin >> k >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s >> a[i].t >> a[i].k;
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
  	
  }
  return 0;
}