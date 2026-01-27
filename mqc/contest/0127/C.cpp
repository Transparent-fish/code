#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;
string s[N];
unordered_map<int, int> mp;

int hum(string a, string b) {
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] != b[i]) cnt++;
  }
  return cnt;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifdef __linux__
  freopen("find.in", "r", stdin);
  freopen("find.out", "w", stdout);
#endif
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    int Max = 0;
    for (int j = 0; j < n; j++) {
      if (Max == m) break;
      Max = max(Max, hum(s[i], s[j]));
    }
    cout << Max << "\n";
  }
  return 0;
}