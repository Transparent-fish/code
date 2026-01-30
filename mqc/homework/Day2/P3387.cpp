#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 5;
int n, m, a[N];
int dfn[N], low[N], book[N];
int id[N], sum[N], cnt, tot, f[N], in[N];
stack<int>stk;
vector<int>e[N], g[N];

void tarjan(int x) {
	low[x] = dfn[x] = ++cnt;
	stk.push(x);
	book[x] = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int v = e[x][i];
		if (!dfn[v]) {
			tarjan(v);
			low[x] = min(low[x], low[v]);
		} else if (book[v]) {
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (low[x] == dfn[x]) {
		int v;
		++tot;
		do {
			v = stk.top();
			stk.pop();
			book[v] = 0;
			id[v] = tot;
			sum[tot] += a[v];
		} while (x != v);
	}
}

void topsort() {
	queue<int>q;
	for (int i = 1; i <= tot; i++) {
		if (in[i] == 0)
			q.push(i), f[i] = sum[i];
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (auto v : g[tmp]) {
			in[v]--;
			if (in[v] == 0)
				q.push(v);
			f[v] = max(f[v], f[tmp] + sum[v]);
		}
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i])
			tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		for (auto v : e[i]) {
			if (id[i] != id[v]) {
				g[id[i]].push_back(id[v]);
				in[id[v]]++;
			}
		}
	}
	topsort();
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i]);
	}
	cout << res;
	return 0;
}