#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
    cin >> n >> s;
    if (s.size() == n)cout << s;
    else {
        for (int i = s.size();i < n;i++) {
            cout << "o";
        }
        cout << s;
    }
    return 0;
}