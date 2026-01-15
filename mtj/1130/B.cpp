#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int cnt;
string s, ss[N];

void Scanf() {
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      continue;
    } else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
      string now;
      for (int j = i; j < s.size(); j++) {
        if ((s[j] < '0' || s[j] > '9') && s[j] != '-') {
          i = j;
          break;
        }
        now += s[j];
      }
      ss[++cnt] = now;
    } else if (s[i] == '<') {
      if (s[i + 1] == '=') {
        ss[++cnt] = "<=";
      } else {
        ss[++cnt] = '<';
      }
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      ss[++cnt] = s[i];
    }
  }
}

void Printf() {
  for (int i = 1; i <= cnt; i++) {
    int cntt = 0, cnttt = 0, l = 0, r = 0;
    if (ss[i][0] >= 'a' && ss[i][0] <= 'z') {
      for (int j = i - 1; j >= 1; j--) {
        if (ss[i][0] >= '0' && ss[j][0] <= '9' || ss[j][0] == '-') {
          l = stoll(ss[j]);
          break;
        }
        if (ss[j] == "<") cntt++;
      }
      for (int j = i + 1; j <= cnt; j++) {
        if (ss[j][0] >= '0' && ss[j][0] <= '9' || ss[j][0] == '-') {
          r = stoi(ss[j]);
          break;
        }
        if (ss[j] == "<") {
          cnttt++;
        }
      }
      cout << l + cntt << " <= " << ss[i] << " <= " << r - cnttt << "\n";
    }
  }
}

signed main() {
  Scanf(), Printf();
  return 0;
}