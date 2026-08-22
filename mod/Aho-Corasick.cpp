#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e6 + 5;
int n, m, T, tot, in[N], cnt[N];
string s, str[N];
map<string, int>mp;

struct node {
    int son[50], fail;
}tree[N];

int Get(char x) {
    if (x >= 'A' && x <= 'Z') return x - 'A';
    else if (x >= 'a' && x <= 'z') return 26 + x - 'a';
    else return 52 + x - '0';
}

void insert(string s) {
    int u = 0;
    for (int i = 0;i < s.size();i++) {
        int v = s[i] - 'a', c = tree[u].son[v];
        if (!c)tree[u].son[v] = ++tot;
        u = tree[u].son[v];
    }
    mp[s] = u;
}

void fail() {
    queue<int>q;
    for (int i = 0;i <= 25;i++) {
        int now = tree[0].son[i];
        if (now) {
            q.push(now);
            tree[now].fail = 0;
        }
    }
    for (;!q.empty();) {
        int u = q.front(), f = tree[u].fail;
        q.pop();
        for (int v = 0;v <= 25;v++) {
            int c = tree[u].son[v];
            if (c) {
                q.push(c);
                tree[c].fail = tree[f].son[v];
                in[tree[f].son[v]]++;
            }
            else tree[u].son[v] = tree[f].son[v];
        }
    }
}

void find(string s) {
    int u = 0;
    for (int i = 0;i < s.size();i++) {
        int v = s[i] - 'a', c = tree[u].son[v];
        if (c)cnt[c]++;
        u = tree[u].son[v];
    }
}

void topsort() {
    queue<int>q;
    for (int i = 1;i <= tot;i++) {
        if (in[i] == 0)q.push(i);
    }
    for (;!q.empty();) {
        int u = q.front(), c = tree[u].fail;
        q.pop();
        in[c]--;
        if (in[c] == 0)q.push(c);
        cnt[c] += cnt[u];
    }
}

signed main() {
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> str[i];
        insert(str[i]);
    }
    cin >> s;
    fail(), find(s), topsort();
    for (int i = 1;i <= n;i++) {
        cout << cnt[mp[str[i]]] << "\n";
    }
    return 0;
}

// @pid 222 @tid 6a7afe00f80e134e7823401b @lang cc.cc14o2
