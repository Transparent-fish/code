#include <bits/stdc++.h>
using namespace std;
int n, k, cnt;

int main() {
  cin >> n >> k;
  for (int x = 0; pow(k, x) <= n; x++) {
    for (int y = 0; pow(k, x) + pow(k, y) <= n; y++) {
      for (int z = 0; pow(k, x) + pow(k, y) + pow(k, z) <= n; z++) {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}