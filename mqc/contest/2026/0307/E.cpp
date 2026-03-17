#include <bits/stdc++.h>
using namespace std;
#define int long long
int ad, ax, bd, bx;
char s;
int cnta, cntb, ansa, ansb;

signed main() {
  cin >> s;
  while (cin >> s) {
    if (s == 'E') {
      cout << ad << ":" << bd;
      break;
    }
    if (s == 'A')
      ax++;
    else
      bx++;
    if (bd == 2 && ad == 2) {
      if (ax == 15 && bx < 14) {
        ad++;
      }
      if (bx == 15 && ax < 14) {
        bd++;
      }
      if (ax >= 14 && bx >= 14) {
        if (ax - 2 >= bx) {
          ad++;
        }
        if (bx - 2 >= ax) {
          bd++;
        }
      }
    } else {
      if (ax == 25 && bx < 24) {
        ad++;
        ax = bx = 0;
      }
      if (bx == 25 && ax < 24) {
        bd++;
        ax = bx = 0;
      }
      if (ax >= 24 && bx >= 24) {
        if (ax - 2 >= bx) {
          ad++;
          ax = bx = 0;
        }
        if (bx - 2 >= ax) {
          bd++;
          ax = bx = 0;
        }
      }
    }
  }
  return 0;
}
