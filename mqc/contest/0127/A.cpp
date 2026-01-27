#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 2000005;
const int mod = 998244353;
int randseed, n, m, Q;
int x[maxn], y[maxn], t[maxn], u[maxn], v[maxn], id[maxn];
int now[maxn], pos[maxn], noow[maxn], ans[maxn];
int mp[maxn];
vector<int> query[maxn];

unsigned int rnd() {
  unsigned int r;
  r = randseed = randseed * 1103515245 + 12345;
  return (r << 16) | ((r >> 16) & 0xFFFF);
}

void init() {
  cin >> n >> m >> Q >> randseed;
  for (int i = 1; i <= m; i++) {
    x[i] = rnd() % n + 1;
    y[i] = rnd() % n + 1;
  }
  for (int i = 1; i <= Q; i++) {
    t[i] = rnd() % m + 1;
    u[i] = rnd() % n + 1;
    v[i] = rnd() % n + 1;
    id[i] = rnd() % n + 1;
    query[t[i]].push_back(i);
  }
}

int main() {
#ifdef __linux__
  freopen("seat.in", "r", stdin);
  freopen("seat.out", "w", stdout);
#endif
  init();
  for (int i = 1; i <= n; i++) {
    now[i] = i;
    pos[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    for (int j : query[i]) {
      int p = pos[id[j]];
      if (p == u[j])
        p = v[j];
      else if (p == v[j])
        p = u[j];
      noow[j] = p;
    }
    int p1 = x[i], p2 = y[i];
    if (p1 != p2) {
      int id1 = now[p1], id2 = now[p2];
      swap(now[p1], now[p2]);
      pos[id1] = p2;
      pos[id2] = p1;
    }
  }
  for (int i = 1; i <= n; i++) mp[i] = i;
  for (int i = m; i >= 1; i--) {
    for (int j : query[i]) {
      ans[j] = mp[noow[j]];
    }
    swap(mp[x[i]], mp[y[i]]);
  }
  ll ret = 0;
  for (int i = 1; i <= Q; i++) ret = (ret + (ll)i * ans[i]) % mod;
  cout << ret << "\n";
  return 0;
}