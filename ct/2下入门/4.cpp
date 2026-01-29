#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, f[N];

int main() {
  int T;
  cin >> T;
  for (; T--;) {
    cin >> n;
    f[0] = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
      if ((n - i) <= i && i != n) {
        f[i] = max(f[i - (n - i)] ^ 1, f[i]);
      }
      f[i] = max(f[i], f[i - 1] ^ 1);
    }
    cout << f[n] << "\n";
  }
  return 0;
}