#include <bits/stdc++.h>
using namespace std;
int T, n;
string s;

int main() {
  cin >> T;
  for (; T--;) {
    bool pan = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> s;
      if (s.length() > 6) pan = 1;
    }
    if (pan)
      cout << "English\n";
    else
      cout << "Pinyin\n";
  }
  return 0;
}