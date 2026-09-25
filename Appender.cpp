#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

signed main() {
	cin >> s;
	if (s.back() == 'e') s += 'r';
	else s += "er";
	cout << s;
    return 0;
}