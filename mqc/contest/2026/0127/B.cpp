#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 12000005;
int Q, tot;

struct node {
  int sum;
  int ls, rs;
} tree[N << 2];

void update(int now, int l, int r, int pos) {
  if (!now) ++tot;
}

signed main() {
  cin >> Q;
  for (; Q--;) {
    int x, y,
        id = (2 * max(abs(x), abs(y)) - 1) * (2 * max(abs(x), abs(y)) - 1);
    cin >> x >> y;
    if (y == max(abs(x), abs(y))) {
      if (x == -max(abs(x), abs(y)))
        id += (2 * max(abs(x), abs(y)) - 1) * (2 * max(abs(x), abs(y)) - 1);
      else
        id += (x + max(abs(x), abs(y)));
    } else if (x == max(abs(x), abs(y))) {
      id += (max(abs(x), abs(y)) + max(abs(x), abs(y)));
      id += (max(abs(x), abs(y)) - y);
    } else if (y == -max(abs(x), abs(y))) {
      id += (max(abs(x), abs(y)) * 4 + max(abs(x), abs(y)) - x);
    } else {
      id += (max(abs(x), abs(y)) * 6);
      id += (y - (-max(abs(x), abs(y))));
    }
    if (x == 0 && y == 0) id = 1;
    // cout << Get(root, 1, Max, id);
  }
  return 0;
}