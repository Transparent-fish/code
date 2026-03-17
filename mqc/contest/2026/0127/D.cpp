#include <bits/stdc++.h>
using namespace std;
#define int long long
#define asd make_pair
int n;
string s;

bool check(int x){
  
}

signed main() {
#ifdef __linux__
  freopen("str.in", "r", stdin);
  freopen("str.out", "w", stdout);
#endif
  cin >> n >> s;
  int l = 1, r = 1e9, ans = 0;
  for (; l <= r;) {
    int mid = l + r >> 1;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}