#include <bits/stdc++.h>
using namespace std;
#define int long long
int q;
priority_queue<int, vector<int>, greater<int> >qp;

signed main() {
	cin >> q;
	for (;q--;) {
		int op, x;
		cin >> op;
		if (op == 1) {
			cin >> x;
			qp.push(x);
		}
		else {
			if (!qp.empty()) {
				cout << qp.top() << "\n";
				qp.pop();
			}
		}
	}
	return 0;
}