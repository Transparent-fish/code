#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 105;
const ull asd = 233333333;
int T, n, k, f[N][N], a[N];
ull h[N], p[N];

ull Get(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }

void init() {
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    h[i] = h[i - 1] * asd + a[i];
    p[i] = p[i - 1] * asd;
    f[i][i] = 1;
  }
}

void Printf() {
  for (int len = 2; len <= n; len++) {
    for (int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      f[i][j] = 0x3f3f3f3f;
      for (int k = 1; k <= len; k++) {
        if (len % k == 0 && Get(i, j - k) == Get(i + k, j))
          f[i][j] = min(f[i][j], f[i][i + k - 1]);
      }
      for (int k = i; k < j; k++) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
    }
  }
  if (f[1][n] <= k)
    cout << "YES\n";
  else
    cout << "NO\n";
}

void Scanf() {
  cin >> T;
  for (; T--;) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    init(), Printf();
  }
}

int main() {
  Scanf();
  return 0;
}