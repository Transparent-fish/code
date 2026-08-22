#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n;
int pos[N], a[N][4];
double del = 0.968, t = 100.0, ans = 1e18;

int sum() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += abs(pos[i] - pos[a[i][1]]);
        res += abs(pos[i] - pos[a[i][2]]);
        res += abs(pos[i] - pos[a[i][3]]);
    }
    return (res >> 1);
}

void Scanf() {
    for (int i = 1; i <= n; i++) {
        pos[i] = i;
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }
}

void SA() {
    t = 1e7;
    for (; t > 1e-10;) {
        int x = rand() % n + 1, y = rand() % n + 1, tmp;
        swap(pos[x], pos[y]);
        tmp = sum();
        if (tmp - ans < 0) ans = tmp;
        else if (exp(-(tmp - ans) / t) * RAND_MAX <= rand()) {
            swap(pos[x], pos[y]);
        }
        t *= del;
    }
}

signed main() {
    srand(time(0));
    cin >> n;
    Scanf();
    for (int i = 1; i <= 50; i++) SA();
    cout << ans;
    return 0;
}