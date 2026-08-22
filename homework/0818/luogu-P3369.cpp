#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n, m, rt, cnt;

struct node {
    int ch[2], fa, val, cnt, siz;
}tree[N];

void pushup(int x) {
    if (!x)return;
    tree[x].siz = tree[tree[x].ch[0]].siz + tree[tree[x].ch[1]].siz + tree[x].cnt;
}

int Get(int x) {
    return x == tree[tree[x].fa].ch[1];
}

void r(int x) {
    int y = tree[x].fa, z = tree[y].fa, sk = Get(x);
    tree[y].ch[sk] = tree[x].ch[sk ^ 1];
    if (tree[x].ch[sk ^ 1])tree[tree[x].ch[sk ^ 1]].fa = y;
    tree[x].ch[sk ^ 1] = y, tree[y].fa = x;
    if (z)tree[z].ch[y == tree[z].ch[1]] = x;
    tree[x].fa = z, pushup(y), pushup(x);
}

void splay(int x, int k) {
    for (;tree[x].fa != k;) {
        int y = tree[x].fa, z = tree[y].fa;
        if (z != k) {
            if (Get(x) == Get(y)) r(y);
            else r(x);
        }
        r(x);
    }
    if (k == 0)rt = x;
}

void insert(int x) {
    int root = rt, fa = 0;
    for (;root;) {
        if (tree[root].val == x) {
            tree[root].cnt++;
            pushup(root), pushup(fa), splay(root, 0);
            return;
        }
        fa = root;
        root = tree[root].ch[x > tree[root].val];
    }
    root = ++cnt, tree[root].val = x;
    tree[root].fa = fa, tree[root].cnt = 1, tree[fa].ch[x > tree[fa].val] = root;
    pushup(root), pushup(fa), splay(root, 0);
}

int rak(int x) {
    int root = rt, res = 0;
    for (;root;) {
        if (x < tree[root].val) root = tree[root].ch[0];
        else {
            res += tree[tree[root].ch[0]].siz;
            if (x == tree[root].val) {
                splay(root, 0);
                return res + 1;
            }
            else res += tree[root].cnt, root = tree[root].ch[1];
        }
    }
    return res + 1;
}


int kth(int x) {
    int root = rt;
    for (;root;) {
        if (x <= tree[tree[root].ch[0]].siz) root = tree[root].ch[0];
        else {
            x -= tree[tree[root].ch[0]].siz;
            if (x <= tree[root].cnt) {
                splay(root, 0);
                return root;
            }
            else {
                x -= tree[root].cnt;
                root = tree[root].ch[1];
            }
        }
    }
    return -1;
}

int pre(int x) {
    int root = rt, res = -1e9;
    for (;root;) {
        if (x <= tree[root].val) root = tree[root].ch[0];
        else {
            res = max(res, tree[root].val);
            root = tree[root].ch[1];
        }
    }
    return res;
}

int nex(int x) {
    int root = rt, res = 1e9;
    for (;root;) {
        if (x >= tree[root].val) root = tree[root].ch[1];
        else {
            res = min(res, tree[root].val);
            root = tree[root].ch[0];
        }
    }
    return res;
}

void find(int x) {
    int root = rt;
    for (;root;) {
        if (tree[root].val == x) {
            splay(root, 0);
            return;
        }
        else {
            root = tree[root].ch[x > tree[root].val];
        }
    }
}

void del(int x) {
    find(x);
    int l = tree[rt].ch[0], r = tree[rt].ch[1];
    for (;tree[l].ch[1];) l = tree[l].ch[1];
    for (;tree[r].ch[0];) r = tree[r].ch[0];
    splay(l, 0), splay(r, l);
    if (tree[tree[r].ch[0]].cnt == 1) tree[r].ch[0] = 0;
    else tree[tree[r].ch[0]].cnt--;
    pushup(tree[r].ch[0]), pushup(r), pushup(l);
}

signed main() {
    cin >> n;
    insert(-1e9), insert(1e9);
    for (;n--;) {
        int op, x;
        cin >> op >> x;
        switch (op) {
        case 1:insert(x);break;
        case 2:del(x);break;
        case 3:cout << rak(x) - 1 << "\n";break;
        case 4:cout << tree[kth(x + 1)].val << "\n";break;
        case 5:cout << pre(x) << "\n";break;
        default:cout << nex(x) << "\n";break;
        }
    }
    return 0;
}