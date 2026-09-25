#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, sum, a[N], b[N], w[N];

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        sum += (a[i] - b[i]);
        w[i] = 1;
    }
    int id = 0;
    for (int i = 1;i <= n;i++) {
        if (a[i] > b[i]) {
            id = i;
            break;
        }
    }
    if (!id) {
        cout << "No\n";
        exit(0);
    }
    if (sum < 0) {
        w[id] = (-sum) / (a[id] - b[id]) + 2;
    }
    else if (sum == 0) {
        w[id]++;
    }
    cout << "Yes\n";
    for (int i = 1;i <= n;i++) {
        cout << w[i] << " ";
    }
    return 0;
}