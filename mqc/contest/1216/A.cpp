#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;

struct node {
  int num, id;
} a[N];

bool cmp(node a, node b) { return a.num > b.num; }

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].num;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  cout << a[2].id;
  return 0;
}