#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];

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

int query(int l, int r, int c) {
  auto itr = split(r + 1), itl = split(l);
  int cnt = 0;
  for (auto it = itl; it != itr; it++) {
    if (it->v == c) cnt++;
  }
  return cnt;
}

void update(int i) {
  set<node> now;
  s.clear();
  swap(a[i], a[i + 1]);
  for (int i = 1; i <= n; i++) {
    now.insert(node(i, i, a[i]));
  }
  s = now;
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

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert(node(i, i, a[i]));
  }
  int _ = 0;
  for (; m--;) {
    int op, l, r, c, x;
    cin >> op;
    ++_;
    if (_ == 60) {
      _ = 0;
      as();
    }
    if (op == 1) {
      cin >> l >> r >> c;
      cout << query(l, r, c) << "\n";
    } else {
      cin >> x;
      update(x);
    }
  }
  return 0;
}