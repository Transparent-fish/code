#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 5;
int n, Max, ans, a[N], b[N];

int Cnt(int x) {
	for (int i = 1; i <= n; i++) {
		b[i] = a[i] % x;
	}
	int cnt = 1, now = b[1], Max = 0;
	for (int i = 2; i <= n; i++) {
		if (i == n && now == b[i]) {
			cnt++, Max = max(Max, cnt);
		}
		if (now == b[i])
			cnt++;
		else {
			now = b[i];
			Max = max(Max, cnt);
			cnt = 1;
		}
	}
	return Max;
}

signed main() {
#ifdef __linux__
	freopen("mod.in", "r", stdin);
	freopen("mod.out", "w", stdout);
#endif
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 2; i <= 70; i++) {
		ans = max(ans, Cnt(i));
	}
	cout << ans;
	return 0;
}