#include <bits/stdc++.h>
#define int long long
using namespace std;
string s, ss[28];
int cnt;

signed main() {
  getline(cin, s);
  int len = s.size();
  for (int i = 0; i < len; i++) {
    string c = "";
    if (s[i] >= '0' && s[i] <= '9' || s[i] == '-') {
      for (int j = i; j < len; j++) {
        if ((s[j] > '9' || s[j] < '0') && s[j] != '-') {
          i = j;
          break;
        }
        c += s[j];
      }
      ss[++cnt] = c;
    } else if (s[i] == '<') {
      if (s[i + 1] == '=') {
        ss[++cnt] = "<=";
      } else {
        ss[++cnt] = "<";
      }
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      ss[++cnt] = s[i];
    }
  }
  for (int i = 1; i <= cnt; i++) {
    if (ss[i][0] >= 'a' && ss[i][0] <= 'z') {
      int res = 0, ress = 0, kt, jw;
      for (int j = i - 1; j >= 1; j--) {
        if (ss[j][0] >= '0' && ss[j][0] <= '9' || ss[j][0] == '-') {
          kt = stoi(ss[j]);
          break;
        }
        if (ss[j] == "<") {
          res++;
        }
      }
      for (int j = i + 1; j <= cnt; j++) {
        if (ss[j][0] >= '0' && ss[j][0] <= '9' || ss[j][0] == '-') {
          jw = stoi(ss[j]);
          break;
        }
        if (ss[j] == "<") {
          ress++;
        }
      }
      cout << kt + res << " <= " << ss[i] << " <= " << jw - ress << "\n";
    }
  }
  return 0;
}