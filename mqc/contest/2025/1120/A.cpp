#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b, T;

signed main() {
  freopen("pigeon.in", "r", stdin);
  freopen("pigeon.out", "w", stdout);
  cin >> a >> b >> T;
  cout << T / ((a * b) / (__gcd(a, b)));
  return 0;
}