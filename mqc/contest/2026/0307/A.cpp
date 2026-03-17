#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m, a[N];

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (; m--;) {
    char op;
    int l, r, v;
    cin >> op >> l >> r;
    if (op == 'Q') {
    	
    } else {
      cin >> v;
      for (int i = l; i <= r; i++) {
        a[i] = v;
      }
    }
  }
  return 0;
} 