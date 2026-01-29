#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int Maxum, nowum;

struct Users {
  string name;
  int type, now_pos;
  bool is_connet_ftp, is_up_do_now;
};
map<string, Users> a;

struct Files {
  string name;
  int siz, fa;
  bool type;
};

struct Fold {
  string name;
  int sum_siz, fa;
  bool type;
  vector<pair<int, int>> son;
};

struct Order {
  bool connect(string name, int x) {
    if (a[name].is_connet_ftp == 0) {
      if ((nowum + 1) <= Maxum) {
        ++nowum;
        a[name].is_connet_ftp = 1;
        return 1;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  }
};

signed main() { return 0; }