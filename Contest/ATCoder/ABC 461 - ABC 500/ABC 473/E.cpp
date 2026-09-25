#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, k, cnt, a[N], s[N];
set<int>st;

signed main() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int las = 0;
    for (int i = 1;i <= n;i++) {
        las = (las + a[i]) % k;
        if (st.count(las)) {
            cnt++;
            st.clear(), st.insert(0), las = 0;
        }
        else {
            st.insert(las);
        }
    }
    cout << cnt;
    return 0;
}