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

void _1_add(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  for (auto it = itl; it != itr; it++) {
    it->v += v;
  }
}

bool _2_pan(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  vector<int> num;
  for (auto i = itl; i != itr; i++) {
    num.push_back(i->v);
  }
  for (int i = 1; i < num.size(); i++) {
    if (num[i] != num[i - 1]) return 0;
  }
  return 1;
}

bool _3_sort(int l, int r) {
  if (l == r) return 1;
  auto itr = split(r + 1), itl = split(l);
  vector<int> num;
  for (auto it = itl; it != itr; it++) {
    num.push_back(it->v);
  }
  for (int i = 0; i < num.size() - 1; i++) {
    if (num[i] >= num[i + 1]) return 0;
  }
  return 1;
}

bool _4_sort(int l, int r) {
  if (l == r) return 1;
  auto itr = split(r + 1), itl = split(l);
  vector<int> num;
  for (auto it = itl; it != itr; it++) {
    num.push_back(it->v);
  }
  for (int i = num.size() - 1; i > 0; i--) {
    if (num[i] >= num[i - 1]) return 0;
  }
  return 1;
}

bool _5_pan(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  vector<int> num;
  for (auto it = itl; it != itr; it++) {
    num.push_back(it->v);
  }
  int now = -1, pan = 1;
  for (int i = 1; i < num.size(); i++) {
    if (pan) {
      if (num[i] > num[i - 1]) continue;
      if (num[i] < num[i - 1]) {
        pan = 0;
        now = i - 1;
      } else {
        return 0;
      }
    } else {
      if (num[i] < num[i - 1]) continue;
      return 0;
    }
  }
  return pan == 0 && now > 0;
}

void cl() {
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

void Printf(int l, int r) {
  auto itr = split(r + 1), itl = split(l);
  vector<int> num;
  for (auto i = itl; i != itr; i++) {
    num.push_back(i->v);
  }
  for (auto i : num) {
    cout << i << " ";
  }
  cout << "\n";
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("peak.in", "r", stdin);
  freopen("peak.out", "w", stdout);
  cin >> n;
  s.insert({1, n, 0});
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    assign(i, i, a[i]);
  }
  cl();
  cin >> q;
  for (; q--;) {
    int op, l, r, x;
    cin >> op >> l >> r;
    if (op == 1) {
      cin >> x;
      _1_add(l, r, x);
    } else if (op == 2) {
      cout << _2_pan(l, r);
    } else if (op == 3) {
      cout << _3_sort(l, r);
    } else if (op == 4) {
      cout << _4_sort(l, r);
    } else {
      cout << _5_pan(l, r);
    }
    if (op != 1) cout << "\n";
  }
  return 0;
}
