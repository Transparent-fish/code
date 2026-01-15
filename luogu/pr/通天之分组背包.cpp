#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, f[N], v[N], c[N], Max;
vector<int> e[N];

int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int id;
    cin >> v[i] >> c[i] >> id;
    e[id].push_back(i);
    Max = max(Max, id);
  }
  for (int i = 1; i <= Max; i++) {
    for (int j = m; j >= 1; j--) {
      for (auto k : e[i]) {
        if (j >= v[k]) {
          f[j] = max(f[j], f[j - v[k]] + c[k]);
        }
      }
    }
  }
  cout << f[m];
  return 0;
}