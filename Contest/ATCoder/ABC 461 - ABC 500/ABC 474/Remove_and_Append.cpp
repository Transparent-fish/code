#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, q, a[N], b[N], las[N];
vector<pair<int, int>> g;

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.second < y.second;
}

signed main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> b[i];
		las[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		if (las[a[i]]) {
			g.push_back({a[i], las[a[i]]});
		}
		else cout << a[i] << " ";
	}
	sort(g.begin(), g.end(), cmp);
	for (auto v : g) {
		cout << v.first << " ";
	}
	cout << "\n";
	return 0;
}