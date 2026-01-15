#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, Max = 1e9;

struct node {
  int a, b, id;
  friend bool operator<(node a, node b) { return a.id < b.id; }
} a[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a;
    a[i].id = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].b;
  }
  do {
    int MAX = 0;
    for (int i = 1; i < n; i++) {
      MAX += max(a[i].b, a[i + 1].a);
    }
    Max = min(Max, MAX + n);
  } while (next_permutation(a + 1, a + n + 1));
  cout << Max;
  return 0;
}