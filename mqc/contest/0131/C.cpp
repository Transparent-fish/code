#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, mod = 998244353;
int n, q, a[N], b[N];
vector<int> na(N), nb(N);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

void rot(int l, int r) {
  for (int i = 1; i <= r - l + 1; i++) {
    na[i] = rt(1, N);
  }
}

bool check(int l, int r) {
  for (int i = l; i <= r; i++) {
    nb[i] = b[i];
  }
  sort(na.begin(), na.end());
  sort(nb.begin(), nb.end());
  return na == nb;
}

signed main() {
#ifdef __linux__
  freopen("hourse.in", "r", stdin);
  freopen("hourse.out", "w", stdout);
#endif
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    nb[i] = b[i];
  }
  cin >> q;
  for (; q--;) {
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = 1; i <= l; i++) {
      rot(l, r);
      if (check(l, r) == 1) {
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}