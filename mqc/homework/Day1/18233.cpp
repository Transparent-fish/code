#include <bits/stdc++.h>
using namespace std;
#define int long long
#define asd make_pair
const int N = 105;
int n, m, sx, sy, ex, ey, boxx, boxy;
int tot, cnt, low[N * N], dfn[N * N], cut[N * N], head[N * N];
char a[N][N];
int d[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct node {
  int nex, to;
} e[N * N * N * 10];

int Get(int x, int y) { return (x - 1) * m + y; }

void add(int x, int y) {
  e[++cnt].nex = head[x];
  e[cnt].to = y;
  head[cnt] = x;
}

void tarjan(int x, int las, int root) { 
	low[x] = dfn[x] = ++tot;
  for(int i=head[i];i!=-1;i=e[i].nex){
        
  }
}

signed main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    head[i] = -1;
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'M')
        sx = i, sy = j;
      else if (a[i][j] == 'P')
        boxx = i, boxy = j;
      else if (a[i][j] == 'K')
        ex = i, ey = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 'S') continue;
      for (int k = 0; k < 4; k++) {
        int nx = i + d[i][0], ny = j + d[i][1];
      }
    }
  }
  return 0;
}