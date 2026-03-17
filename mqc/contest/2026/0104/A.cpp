//A 袋中球的最终颜色(ball) 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a, b;

signed main() {
  cin >> a >> b;
  if (b % 2 != 0)
    cout << "black";
  else
    cout << "white";
  return 0;
}