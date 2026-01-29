#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5, M = 2100000;
int n, m, cnt, tot, head[N], dfn[N], low[N];
stack<int> sk;

struct node {
  int form, to, nex, id;
} e[M << 1];

void add(int x, int y) {
  e[++cnt].nex = head[x];
  e[cnt].to = y;
  e[cnt].form = x;
  head[x] = cnt;
}

void tarjan(int x, int las) {
  dfn[x] = low[x] = ++tot;
  for (int i = head[i]; i != -1; i = e[i].nex) {
     
  }
}

signed main() {
  cin >> n >> m;
  memset(head, -1, sizeof(head));
  return 0;
}