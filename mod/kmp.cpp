#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int nxt[N];
string a, b;

signed main() {
  cin >> a >> b;
  a = "#" + a, b = "#" + b;
  int j = 0;
  for (int i = 2; i < b.size(); i++) {
    for (; j > 0 && b[j + 1] != b[i];) j = nxt[j];
    if (b[j + 1] == b[i]) j++;
    nxt[i] = j;
  }
  j = 0;
  for (int i = 1; i < a.size(); i++) {
    for (;j && b[j + 1] != a[i];) j = nxt[j];
    if (b[j + 1] == a[i]) j++;
    if (j == b.size() - 1) { cout << i - j + 1 << "\n"; j = nxt[j]; }
  }
  for (int i = 1; i < b.size(); i++) cout << nxt[i] << " ";
  return 0;
}
