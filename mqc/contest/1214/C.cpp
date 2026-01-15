#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n;
vector<int> A, B, C, D;

struct node {
  int a, b, c, d;
  char op;
  vector<int> A, B, C, D;
} a[N];

void Debug() {
  for (int i = 1; i <= n; i++) {
    // cout << i << "\n";
    for (auto j : a[i].A) {
      cout << j;
    }
    cout << " ";
    for (auto j : a[i].B) {
      cout << j;
    }
    cout << " ";
    for (auto j : a[i].C) {
      cout << j;
    }
    cout << " ";
    for (auto j : a[i].D) {
      cout << j;
    }
    cout << "\n";
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a >> a[i].op >> a[i].b >> a[i].op >> a[i].c >> a[i].op >>
        a[i].d;
  }
  for (int i = 1; i <= 8; i++) {
    A.push_back(0);
    B.push_back(0);
    C.push_back(0);
    D.push_back(0);
  }
  for (int i = 1; i <= n; i++) {
    int now = a[i].a;
    for (; now > 0;) {
      a[i].A.push_back(now % 2);
      now /= 2;
    }
    now = a[i].b;
    for (; now > 0;) {
      a[i].B.push_back(now % 2);
      now /= 2;
    }
    now = a[i].c;
    for (; now > 0;) {
      a[i].C.push_back(now % 2);
      now /= 2;
    }
    now = a[i].d;
    for (; now > 0;) {
      a[i].D.push_back(now % 2);
      now /= 2;
    }
    for (; a[i].A.size() != 8;) {
      a[i].A.push_back(0);
    }
    for (; a[i].B.size() != 8;) {
      a[i].B.push_back(0);
    }
    for (; a[i].C.size() != 8;) {
      a[i].C.push_back(0);
    }
    for (; a[i].D.size() != 8;) {
      a[i].D.push_back(0);
    }
    reverse(a[i].A.begin(), a[i].A.end());
    reverse(a[i].B.begin(), a[i].B.end());
    reverse(a[i].C.begin(), a[i].C.end());
    reverse(a[i].D.begin(), a[i].D.end());
  }
  int Max = 0, br = 0;
  for (int j = 0; j < 32; j++) {
    if (br) break;
    int now = j / 8, wz = j % 8, fir;
    if (now == 0)
      fir = a[1].A[wz];
    else if (now == 1)
      fir = a[1].B[wz];
    else if (now == 2)
      fir = a[1].C[wz];
    else if (now == 3)
      fir = a[1].D[wz];
    bool pan = 1;
    for (int i = 2; i <= n; i++) {
      int noow;
      if (now == 0)
        noow = a[i].A[wz];
      else if (now == 1)
        noow = a[i].B[wz];
      else if (now == 2)
        noow = a[i].C[wz];
      else if (now == 3)
        noow = a[i].D[wz];
      if (noow != fir) {
        pan = 0;
        break;
      }
    }
    if (pan) {
      Max++;
    } else {
      br = 1;
    }
  }
  for (int j = 0; j < Max; j++) {
    int now = j / 8, wz = j % 8;
    if (now == 0) {
      A[wz] = a[1].A[wz];
    } else if (now == 1) {
      B[wz] = a[1].B[wz];
    } else if (now == 2) {
      C[wz] = a[1].C[wz];
    } else if (now == 3 && wz < 8) {
      D[wz] = a[1].D[wz];
    }
  }
  int _ = 0, __ = 0, ___ = 0, ____ = 0;
  for (int j = 0; j < 8; j++) {
    _ = _ * 2 + A[j];
    __ = __ * 2 + B[j];
    ___ = ___ * 2 + C[j];
    ____ = ____ * 2 + D[j];
  }
  cout << _ << "." << __ << "." << ___ << "." << ____ << "/" << Max;
  return 0;
}