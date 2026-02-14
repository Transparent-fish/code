#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int n, m;

struct node {
    int h, w, id;
}a[N];

signed mabn() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].h >> a[i].w;
        a[i].id = i;
    }
    return 0;
}