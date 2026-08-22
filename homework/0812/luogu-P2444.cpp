#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e4 + 5;
int n, tot, ans;
int in[N], cnt[N];
string s;

struct node {
    int son[2], fail;
}tree[N];

void insert(string s) {
    int u = 0;
    for (int i = 0;i < s.size();i++) {
        int v = s[i] - '0', c = tree[u].son[v];
        if (!c)tree[u].son[v] = ++tot;
        u = tree[u].son[v];
    }
    in[u] = 1;
}

void fail() {
    queue<int>q;
    for (int i = 0;i <= 1;i++) {
        int now = tree[0].son[i];
        if (now) {
            q.push(now);
            tree[now].fail = 0;
        }
    }
    for (;!q.empty();) {
        int u = q.front(), f = tree[u].fail;
        q.pop();
        if (in[f])in[u] = 1;
        for (int v = 0;v <= 1;v++) {
            int c = tree[u].son[v];
            if (c) {
                q.push(c);
                tree[c].fail = tree[f].son[v];
            }
            else tree[u].son[v] = tree[f].son[v];
        }
    }
}

void dfs(int u) {
    if (ans)return;
    cnt[u] = 1;
    for (int v = 0;v <= 1;v++) {
        int c = tree[u].son[v];
        if (in[c])continue;
        if (cnt[c] == 1) { ans = true; return; }
        if (cnt[c] == 0)dfs(c);
    }
    cnt[u] = 2;
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s;
        insert(s);
    }
    fail();
    if (!in[0])dfs(0);
    cout << (ans ? "TAK" : "NIE") << "\n";
    return 0;
}

// @pid 223 @tid 6a7afe00f80e134e7823401b @lang cc.cc14o2
