#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N];

struct node {
  int l, r;
  mutable int v;
  node(int _l, int _r = -1, int _v = 0) : l(_l), r(_r), v(_v) {}
  friend bool operator<(node a, node b) { return a.l < b.l; }
};
set<node> s;

auto split(int pos) {
  auto it = s.lower_bound(node(pos, 0, 0));
  if (it != s.end() && it->l == pos) {
    return it;
  }
  it--;
  int l = it->l, t = it->r, v = it->v;
  s.erase(it), s.insert(node(l, pos - 1, v));
  return s.insert(node(pos, t, v)).first;
}

void assign(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  s.erase(itl, itr), s.insert(node(l, r, v));
}

void add(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  for (auto it = itl; it != itr; it++) {
    it->v += v;
  }
}

int Max(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  int maxx = -1e18;
  for (auto it = itl; it != itr; it++) {
    maxx = max(maxx, it->v);
  }
  return maxx;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert(node(i, i, a[i]));
  }
  for (; q--;) {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> x;
      assign(l, r, x);
    } else if (op == 2) {
      cin >> x;
      add(l, r, x);
    } else {
      cout << Max(l, r) << "\n";
    }
  }
  return 0;
}