#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 5;
int n, m, c, tree[N], a[N], las[N], lass[N], ans[N];

struct node {
  int l, r, id;
  friend bool operator<(node a, node b) {
    if (a.r == b.r) return a.l < b.l;
    return a.r < b.r;
  }
} b[N];

int lowbit(int x) { return x & -x; }

void update(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) {
    tree[i] += c;
  }
}

int query(int x) {
  int res = 0;
  for (int i = x; i >= 1; i -= lowbit(i)) {
    res += tree[i];
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i].l >> b[i].r;
    b[i].id = i;
  }
  sort(b + 1, b + m + 1);
  int l = 1;
  for (int i = 1; i <= m; i++) {
    for (; l <= b[i].r;) {
      if (!las[a[l]]) {
        las[a[l]] = l;
      } else if (!lass[a[l]]) {
        lass[a[l]] = las[a[l]];
        las[a[l]] = l;
        update(lass[a[l]], 1);
      } else {
        update(lass[a[l]], -1);
        lass[a[l]] = las[a[l]];
        las[a[l]] = l;
        update(lass[a[l]], 1);
      }
      l++;
    }
    if (b[i].l == 1) {
      ans[b[i].id] = query(b[i].r);
    } else {
      ans[b[i].id] = query(b[i].r) - query(b[i].l - 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}