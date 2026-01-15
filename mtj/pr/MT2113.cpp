#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
stack<int> sk, Min;

signed main() {
  cin >> n;
  for (; n--;) {
    int op;
    cin >> op;
    if (op == 1) {
      int x;
      cin >> x;
      sk.push(x);
      if (Min.empty() || x <= Min.top()) {
        Min.push(x);
      }
    } else if (op == 2 && !sk.empty()) {
      if (sk.top() == Min.top()) {
        Min.pop();
      }
      sk.pop();
    } else if (op == 3 && !sk.empty()) {
      cout << sk.top() << "\n";
    } else if (op == 4 && !Min.empty()) {
      cout << Min.top() << "\n";
    }
  }
  return 0;
}
