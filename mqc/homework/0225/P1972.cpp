#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, cnt, a[N];

struct node {
  int l, r;
  mutable int v;
  node(int _l, int _r = -1, int _v = 0) : l(_l), r(_r), v(_v) {}
  friend bool operator<(node a, node b) { return a.l < b.l; }
};
set<node> s;

auto split(int x) {
  auto it = s.lower_bound(node(x, 0, 0));
  if (it != s.end() && it->l == x) return it;
  it--;
  int l = it->l, r = it->r, v = it->v;
  s.erase(it), s.insert(node(l, x - 1, v));
  return s.insert(node(x, r, v)).first;
}

void assgin(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  s.erase(itl, itr), s.insert(node(l, r, v));
}

void as() {
  vector<node> e;
  for (auto i : s) {
    if (e.empty() || e.back().v != i.v) {
      e.push_back(i);
    } else {
      e[e.size() - 1].r = i.r;
    }
  }
  s.clear();
  for (auto i : e) s.insert(i);
}

int query(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  set<int> s;
  for (auto it = itl; it != itr; it++) {
    s.insert(it->v);
  }
  return s.size();
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int op;
    cin >> op;
    s.insert(node(i, i, op));
  }
  cin >> m;
  for (; m--;) {
    int l, r;
    if (++cnt == 20) {
      as();
      cnt = 0;
    }
    cin >> l >> r;
    cout << query(l, r) << "\n";
  }
  return 0;
}