#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int t, n, ans;
int a[N], b[N];

signed main() {
	cin >> t;
	for (;t--;) {
		cin >> n;
		ans = 0;
		for (int i = 1;i <= n;i++) {
			a[i] = 0;
			b[i] = 0;
		}
		for (int i = 1;i <= n;i++) {
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++) {
			cin >> b[i];
		}
		for (int i = 1;i <= n;i++) {
			if (a[i] > b[i]) {
				ans += a[i] - b[i];
			}
		}
		if (ans > 0) {
			cout << ans + 1 << "\n";
		}
		else {
			cout << "1\n";
		}
	}
	return 0;
}