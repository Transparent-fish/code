#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 1e6, MIN_N = 1e4, MAX_A = 1e9, MIN_A = 1e6;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

signed main() {
    int n = rt(MIN_N, MAX_N), num;
    cin >> num;
    cout << n << "\n";
    if (num % 2 == 0) {
        int a = rt(MIN_A, MAX_A);
        for (int i = 1;i <= n;i++) {
            cout << a << " ";
        }
    }
    else {
        for (int i = 1;i <= n;i++) {
            cout << rt(MIN_A, MAX_A) << " ";
        }
    }
    cout << flush;
    return 0;
}