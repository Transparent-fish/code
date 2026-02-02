#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5+5;
int n, m, cnt, ccnt;
map<string, int> mp;
string a[N], b[N];

struct node {
	int nxt, to;
} e[N * 2];
int dfn[N], low[N], tot, num, head[N], bo[N], in[N];
stack<int> stk;

void add(int x, int y) {
	e[++ccnt].nxt = head[x];
	e[ccnt].to = y;
	head[x] = ccnt;
}

void tarjan(int x, int lst) {
	low[x] = dfn[x] = ++tot;
	stk.push(x);
	in[x] = 1;
	for (int i = head[x]; i != -1; i = e[i].nxt) {
//		cout << 1;
		int v = e[i].to;
		if (!dfn[v]) {
			tarjan(v, i);
			low[x] = min(low[x], low[v]);
		} else if (in[v]) {
			low[x] = min(low[x], dfn[v]);
		}
	}
	if (low[x] == dfn[x]) {
		int v;
		num++;
		do {
			v = stk.top();
			stk.pop();
			in[v] = 0;
			bo[v] = num;
		} while (v != x);
	}
}

signed main() {
	cin >> n;
	memset(head, -1, sizeof head);
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if (!mp[a[i]]) {
			mp[a[i]] = ++cnt;
		}
		if (!mp[b[i]]) {
			mp[b[i]] = ++cnt;
		}
		add(mp[a[i]], mp[b[i]]);
//		add(mp[b[i]], mp[a[i]]);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		string a, b;
		cin >> a >> b;
		int u = mp[a], v = mp[b];
//		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= cnt; i++) {
		if (!dfn[i]) {
			tarjan(i, -1);
		}
	}
	for (int i = 1; i <= n; i++) {
		int u = mp[a[i]], v = mp[b[i]];
		if (bo[u] != bo[v]) {
			cout << "Safe";
		} else {
			cout << "Unsafe";
		}
		cout << endl;
	}
	return 0;
}