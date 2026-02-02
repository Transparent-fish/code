#include <bits/stdc++.h>
using namespace std;
#define endl cerr << "------------------I Love ODT------------------\n";
#define int long long
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif

#define ds(x) (x == '\r' || x == '\n' || x == ' ')
#define MAX 20
namespace fastIO {
template <typename T>
inline void r(T& a) {
  a = 0;
  char ch = gc();
  bool ok = 0;
  for (; ch < '0' || ch > '9';) ok ^= (ch == '-'), ch = gc();
  for (; ch >= '0' && ch <= '9';)
    a = (a << 1) + (a << 3) + (ch ^ 48), ch = gc();
  if (ok) a = -a;
}
template <typename T>
inline void w(T a) {
  if (a == 0) {
    pc('0');
    return;
  }
  static char ch[MAX];
  int till = 0;
  if (a < 0) {
    pc('-');
    for (; a;) ch[till++] = -(a % 10), a /= 10;
  } else
    for (; a;) ch[till++] = a % 10, a /= 10;
  for (; till;) pc(ch[--till] ^ 48);
}
struct Srr {
  inline Srr operator>>(int& a) {
    r(a);
    return {};
  }
  inline Srr operator>>(char& ch) {
    ch = gc();
    for (; ds(ch);) ch = gc();
    return {};
  }
  inline Srr operator>>(string& s) {
    s = "";
    char ch = gc();
    for (; ds(ch);) ch = gc();
    for (; !(ds(ch) || ch == EOF);) {
      s.push_back(ch);
      ch = gc();
    }
    return {};
  }
  template <typename T>
  inline Srr operator<<(T& a) {
    r(a);
    return {};
  }
  inline void is(int n, string& s) {
    s = "";
    char ch = gc();
    for (; ds(ch);) ch = gc();
    for (; n--;) {
      s.push_back(ch);
      ch = gc();
    }
  }
} in;
struct Sww {
  inline Sww operator<<(const int a) {
    w(a);
    return {};
  }
  inline Sww operator<<(const char ch) {
    pc(ch);
    return {};
  }
  inline Sww operator<<(const string s) {
    for (int i = 0; i < s.size(); i++) pc(s[i]);
    return {};
  }
  template <typename T>
  inline Sww operator>>(const T a) {
    w(a);
    return {};
  }
} out;
}  // namespace fastIO
using fastIO::in;
using fastIO::out;
#undef ds
const int N = 1e5 + 5;
int n, m, root, mod, tot, w[N], wt[N], dep[N], fa[N], siz[N], id[N], top[N],
    son[N];
int tree[N << 2], laz[N << 2];

struct node {
  int v;
};
vector<node> e[N];

void dfs1(int x, int f, int deep) {
  dep[x] = deep;
  fa[x] = f;
  siz[x] = 1;
  int maxx = 0;
  for (auto i : e[x]) {
    if (i.v == f) {
      continue;
    }
    dfs1(i.v, x, deep + 1);
    siz[x] += siz[i.v];
    if (siz[i.v] > maxx) {
      maxx = siz[i.v];
      son[x] = i.v;
    }
  }
}

void dfs2(int x, int topfa) {
  top[x] = topfa;
  id[x] = ++tot;
  wt[tot] = w[x];
  if (!son[x]) {
    return;
  }
  dfs2(son[x], topfa);
  for (auto i : e[x]) {
    if (i.v == fa[x] || i.v == son[x]) {
      continue;
    }
    dfs2(i.v, i.v);
  }
}

void pushup(int rt) {
  tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
  tree[rt] %= mod;
}

void pushdown(int l, int r, int rt) {
  if (laz[rt]) {
    laz[rt << 1] += laz[rt];
    laz[rt << 1] %= mod;
    laz[rt << 1 | 1] += laz[rt];
    laz[rt << 1 | 1] %= mod;
    int mid = (l + r) >> 1;
    tree[rt << 1] += laz[rt] * (mid - l + 1);
    tree[rt << 1] %= mod;
    tree[rt << 1 | 1] += laz[rt] * (r - mid);
    tree[rt << 1 | 1] %= mod;
    laz[rt] = 0;
  }
}

void build(int l, int r, int rt) {
  if (l == r) {
    tree[rt] = wt[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pushup(rt);
}

void update(int l, int r, int rt, int L, int R, int c) {
  if (L <= l && r <= R) {
    laz[rt] += c;
    tree[rt] += c * (r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(l, r, rt);
  if (L <= mid) {
    update(l, mid, rt << 1, L, R, c);
  }
  if (R > mid) {
    update(mid + 1, r, rt << 1 | 1, L, R, c);
  }
  pushup(rt);
}

int query(int l, int r, int rt, int L, int R) {
  if (L <= l && r <= R) {
    return tree[rt];
  }
  pushdown(l, r, rt);
  int mid = (l + r) >> 1, sum = 0;
  if (L <= mid) {
    sum += query(l, mid, rt << 1, L, R), sum %= mod;
  }
  if (R > mid) {
    sum += query(mid + 1, r, rt << 1 | 1, L, R), sum %= mod;
  }
  return sum;
}

void _(int x, int y, int z) {
  z %= mod;
  for (; top[x] != top[y];) {
    if (dep[top[x]] < dep[top[y]]) {
      swap(x, y);
    }
    update(1, n, 1, id[top[x]], id[x], z);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) swap(x, y);
  update(1, n, 1, id[x], id[y], z);
}

int __(int x, int y) {
  int O00 = 0;
  for (; top[x] != top[y];) {
    if (dep[top[x]] > dep[top[y]]) {
      swap(x, y);
    }
    O00 += query(1, n, 1, id[top[y]], id[y]);
    O00 %= mod;
    y = fa[top[y]];
  }
  if (dep[x] < dep[y]) {
    swap(x, y);
  }
  O00 += query(1, n, 1, id[y], id[x]);
  O00 %= mod;
  return O00;
}

void ___(int x, int y) {
  y %= mod;
  update(1, n, 1, id[x], id[x] + siz[x] - 1, y);
}

int ____(int x) { return query(1, n, 1, id[x], id[x] + siz[x] - 1) % mod; }
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m >> root >> mod;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    e[u].push_back({v}), e[v].push_back({u});
  }
  dfs1(root, 0, 1), dfs2(root, root), build(1, n, 1);
  for (; m--;) {
    int op, x, y, z;
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> z;
      _(x, y, z);
    } else if (op == 2) {
      cin >> x >> y;
      cout << __(x, y) << "\n";
    } else if (op == 3) {
      cin >> x >> y;
      ___(x, y);
    } else {
      cin >> x;
      cout << ____(x) << "\n";
    }
  }
  return 0;
}