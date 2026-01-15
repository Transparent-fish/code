#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;

int Cnt(int x) {
  int res = 0, tmp = 1;
  for (; x >= tmp;) {
    x -= tmp;
    tmp++;
    res++;
  }
  return res;
}

signed main() {
	cin >> n;
  for (int i = 2; i <= sqrt(n); i++) {
    int cnt = 0;
    if (n % i == 0) {
      cnt = 0;
      for (; n % i == 0;) {
        n /= i;
        cnt++;
      }
      ans += Cnt(cnt);
    }
  }
  if (n != 1) ans += Cnt(1);
  cout << ans;
  return 0;
}