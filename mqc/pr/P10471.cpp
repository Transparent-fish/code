#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n, m, T, tot, Max, a[N], tree[N][62];

int Get(char x) {
  if (x >= 'A' && x <= 'Z')
    return x - 'A';
  else if (x >= 'a' && x <= 'z')
    return 26 + x - 'a';
  else
    return 52 + x - '0';
}

void insert(int s) {
  int u = 0;
  for (int i = 30; i >= 0; i--) {
    int v = ((s >> i) & 1);
    if (!tree[u][v]) tree[u][v] = ++tot;
    u = tree[u][v];
  }
}

int query(int s) {
  int u = 0, ans = 0;
  for (int i = 30; i >= 0; i--) {
    int v = ((s >> i) & 1);
    if (tree[u][v ^ 1]) {
      u = tree[u][v ^ 1];
      ans += (1 << i);
    } else {
      u = tree[u][v];
    }
  }
  return ans;
}

void Scanf() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    insert(a[i]);
  }
}

void Printf() {
  for (int i = 1; i <= n; i++) {
    Max = max(Max, query(a[i]));
  }
  cout << Max;
}

int main() {
  Scanf(), Printf();
  return 0;
}