#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, tot = 1;
int las, lasl, lasr;
bool pan;

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

int query(int l, int r) {
  // if (lasl == l && lasr == r) {
  //   return las;
  // }
  auto itr = split(r + 1), itl = split(l);
  set<int> cor;
  for (auto it = itl; it != itr; it++) {
    cor.insert(it->v);
  }
  for (auto i : cor) {
    if (i == -1) --las;
  }
  lasl = l, lasr = r, las = cor.size();
  return las;
}


signed main() {
  cin >> n >> m;
  s.insert({1, n, -1});
  for (; m--;) {
    int q, l, r;
    cin >> q >>l, l >> r;
    if (q == 1) {
      assign(l, r, ++tot);
    } else {
      cout << query(l, r) << "\n";
    }
  }
  return 0;
}