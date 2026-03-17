#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
char c;
string s;

signed main() {
  cin >> n >> c >> k >> s;
  for (int l = 1; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
      int cnt = 0;
      for (int j = i; j < i + l; j++) {
        if (s[j] == c) cnt++;
      }
      if (cnt >= k) {
        cout << s.substr(i, l);
        exit(0);
      }
    }
  }
  return 0;
}