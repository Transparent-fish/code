#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>e[N], g[N];
int n, p, q, book[N], dfn[N], low[N], tot, num, a[N], sum[N], id[N], u[N], v[N];
int f[N], in[N], out[N], mn[N];
stack<int>stk;
map<int, bool>mp[N];

void tarjan(int x) {
	dfn[x] = low[x] = ++tot;
	stk.push(x);
	book[x] = 1;
	for (auto v : e[x]) {
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		} else if (book[v])
			low[x] = min(low[x], dfn[v]);
	}
	if (low[x] == dfn[x]) {
		int v;
		num++;
		sum[num] = 0x3f3f3f3f;
		mn[num] = N;
		do {
			v = stk.top();
			stk.pop();
			book[v] = 0;
			id[v] = num;
			sum[num] = min(sum[num], a[v]);
			mn[num] = min(mn[num], v);
		} while (v != x);
	}
}

int main() {
	cin >> n >> p;
	memset(a, 0x3f3f3f3f, sizeof a);
	for (int i = 1; i <= p; i++) {
		int x, s;
		cin >> x >> s;
		a[x] = s;
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		u[i] = x, v[i] = y;
		e[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= q; i++) {
		int x = id[u[i]], y = id[v[i]];
		if (x != y && mp[x][y] == 0) {
			g[x].push_back(y);
			in[y]++;
			mp[x][y] = 1;
		}
	}
	int res = 0, mi = N;
	for (int i = 1; i <= num; i++) {
		if (in[i] == 0) {
			if (sum[i] == 0x3f3f3f3f) {
				mi = min(mn[i], mi);
			} else {
				res += sum[i];
			}
		}
	}
	if (mi != N) {
		cout << "NO\n" << mi;
	} else
		cout << "YES\n" << res;
	return 0;
}
