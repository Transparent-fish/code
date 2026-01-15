#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;

struct node {
  int u, v, w;
} a[N];
vector<node> e[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    e[u].push_back({v, w});
  }
  return 0;
}