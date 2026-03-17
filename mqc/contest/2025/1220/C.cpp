#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, v[N], w[N], cnt[N][N];

void Scanf() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i <= n; i++) {
    cnt[i][0] = 1;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = m; k >= w[j]; k--) {
        cnt[i][k] += cnt[i][k - w[j]];
        cnt[i][k] %= 10;
      }
    }
  }
}

void Printf() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << cnt[i][j];
    }
    cout << "\n";
  }
}

int main() {
  Scanf(), Printf();
  return 0;
}