#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int cnta, cntb, ansa, ansb;

signed main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'E') {
      cout << ansa << ":" << ansb;
      exit(0);
    }
    if (s[i] == 'A') cnta++;
    else cntb++;
    if (ansb == 2 && ansa == 2) {
      if (cnta == 15 && cntb < 14) ansa++;
      if (cntb == 15 && cnta < 14) ansb++;
      if (cnta >= 14 && cntb >= 14) {
        if (cnta - 2 >= cntb) ansa++;
        if (cntb - 2 >= cnta) ansb++;
      }
    } else {
      if (cnta == 25 && cntb < 24) { ansa++;cnta = cntb = 0;}
      if (cntb == 25 && cnta < 24) { ansb++;cnta = cntb = 0;}
      if (cnta >= 24 && cntb >= 24) {
        if (cnta - 2 >= cntb) { ansa++;cnta = cntb = 0;}
        if (cntb - 2 >= cnta) { ansb++;cnta = cntb = 0;}
      }
    }
  }
  return 0;
}