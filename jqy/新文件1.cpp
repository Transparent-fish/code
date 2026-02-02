#include <bits/stdc++.h>
using namespace std;
#define int long long
#define d double
int n, k;
d p;
d ans, cnt, kk, now = 1;

void dfs(int l, int r, d q) {
	if (l == k + 1) {
		if (r > (k >> 1)) {
			kk += q;
			cnt++;
		}
		return;
	}
	dfs(l + 1, r + 1, q * p), dfs(l + 1, r, q * (1 - p));
}

void dfss(int l, int r, d dep) {
	if (l > r)
		return;
	if (r - 1 == l) {
		ans += dep * (2.0 / n);
		return;
	}
	int mid = mid;
	dfss(mid + 1, r, dep * kk), dfss(l, mid - 1, dep * kk);
	ans += dep * (1.0 / n);
}

signed main() {
#ifdef __linux__
	freopen("tiancai.in", "r", stdin);
	freopen("tiancai.out", "w", stdout);
#endif
	cin >> n >> p >> k;
	dfs(1, 0, 1);
	if (n <= 1e5) {
		dfss(1, n, 1);
		cout << fixed << setprecision(4) << ans;
		exit(0);
	}
	int _ = n, tot = 1;
	for (; n;) {
		d now = min(n, tot) * 1.0 / _;
		ans += now * now, n -= min(n, tot), tot *= 2;
		if (n < tot) {
			ans += n * 1.0 / _ * now;
			break;
		}
		now *= kk;
	}
	cout << fixed << setprecision(4) << ans;
	return 0;
}