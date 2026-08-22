#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int n, a, b, ans;

int fpow(int a, int b, int p) {
	int ans = 1;
	for (;b;) {
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	int num = 1, den = 1;
	for (int i = 0; i < k; i++) {
		num = num * ((n - i) % mod) % mod;
	}
	for (int i = 1; i <= k; i++) {
		den = den * i % mod;
	}
	return num * fpow(den, mod - 2, mod) % mod;
}

signed main() {
	cin >> n >> a >> b;
	cout << (fpow(2, n, mod) - 1 - C(n, a) - C(n, b) + mod + mod + mod) % mod;
	return 0;
}

// @pid 20 @tid 6a6c7e50bdb36af2d80fa4c4 @lang cc.cc14o2
