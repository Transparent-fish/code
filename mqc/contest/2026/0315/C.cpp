#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2 + 5;
int n, a[N];
int b[N];
int tt = 10005;
int c[N];

int init() {
  int tot = 1;
  for (int i = 1; i <= n; i++) {
    int mi = 1e18;
    for (int j = 1; j <= n; j++) {
      if (a[j] != -1) {
        mi = min(mi, a[j]);
      }
    }
    if (mi == 1e18) break;
    bool f = 0;
    for (int j = 1; j <= n; j++) {
      if (a[j] == mi && a[j + 1] == a[j]) {
        f = 1;
        for (int k = j; k > tot; k--) {
          a[k] = a[k - 1];
        }
        a[tot] = -1;
        tot++;
        a[j + 1]++;
      }
    }
    if (!f) {
      for (int j = 1; j <= n; j++) {
        if (a[j] == mi) a[j] = tt;
      }
      tt++;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) ans++;
  }
  return ans;
}

int js() {
  int tot = n;
  for (int i = n; i >= 1; i--) {
    int mi = 1e18;
    for (int j = n; j >= 1; j--) {
      if (c[j] != -1) {
        mi = min(mi, c[j]);
      }
    }
    if (mi == 1e18) break;
    bool f = 0;
    for (int j = n; j > 1; j--) {
      if (c[j] == mi && c[j - 1] == c[j]) {
        f = 1;
        for (int k = j; k < tot; k++) {
          c[k] = c[k + 1];
        }
        c[tot] = -1;
        tot--;
        c[j - 1]++;
      }
    }
    if (!f) {
      for (int j = 1; j <= n; j++) {
        if (c[j] == mi) c[j] = tt;
      }
      tt++;
    }
  }
  int an = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i] != -1) an++;
  }
  return an;
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    c[i] = a[i];
  }
  init();
  cout << min(js(), init());
  return 0;
}