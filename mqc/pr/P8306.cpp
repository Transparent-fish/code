#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n, m, T, tot, mp[N], tree[N][62];

void init() {
  for (int i = 0; i < tot; i++) {
    for (int j = 0; j < 63; j++) {
      tree[i][j] = 0;
    }
    mp[i] = 0;
  }
  tot = 0;
}

int Get(char x) {
  if (x >= 'A' && x <= 'Z')
    return x - 'A';
  else if (x >= 'a' && x <= 'z')
    return 26 + x - 'a';
  else
    return 52 + x - '0';
}

void insert(string s) {
  int u = 0;
  for (int i = 0; i < s.size(); i++) {
    int v = Get(s[i]);
    if (!tree[u][v]) tree[u][v] = ++tot;
    u = tree[u][v];
    mp[u]++;
  }
}

int query(string s) {
  int u = 0;
  for (int i = 0; i < s.size(); i++) {
    int v = Get(s[i]);
    if (!tree[u][v]) return 0;
    u = tree[u][v];
  }
  return mp[u];
}

void Scanf() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    insert(s);
  }
}

void Printf() {
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    cout << query(s) << "\n";
  }
}

int main() {
  cin >> T;
  for (; T--;) {
    init(), Scanf(), Printf();
  }
  return 0;
}