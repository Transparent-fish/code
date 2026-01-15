#include <bits/stdc++.h>
using namespace std;
#define int long long
int a;
string s;

bool pan(int x) {
  if (x == 1 || x == 0) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}

signed main() {
  cin >> a;
  s = to_string(a);
  for (int i = 0; i <= 9; i++) {
    string now = s + to_string(i);
    if (pan(stoll(now)) == 1) {
      cout << stoll(now) << "\n";
      exit(0);
    }
  }
  cout << "-1";
  return 0;
}