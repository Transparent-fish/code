#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2100;
int ain[N][N], num[N][2];
vector<int> a[N];
bool ins[N];
int dfn[N], low[N], b[N];
int tot = 0, cnt = 0;
stack<int> st;
void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    ins[u] = 1;
    for (auto v : a[u]) {
        if (!dfn[v]) tarjan(v), low[u] = min(low[u], low[v]);
        else if (ins[v]) low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u]) {
        cnt++;
        while (st.size()) {
            if (st.top() == u) break;
            b[st.top()] = cnt;
            ins[st.top()] = 0;
            st.pop();
        }
        b[st.top()] = cnt;
        ins[st.top()] = 0;
        st.pop();
    }
    return;
}
int n;
bool check(int t) {
    for (int i = 1;i <= n * 2;i++) {
        a[i].clear();
        ins[i] = dfn[i] = low[i] = b[i] = tot = cnt = 0;
    }
    while (st.size()) st.pop();
    for (int i = 1;i <= n;i++) {
        for (int j = t + 2;j <= n;j++) {
            int x = ain[i][j];
            for (int k = 0;k <= 1;k++) {
                for (int l = 0;l <= 1;l++) {
                    if (num[i][k] == num[x][l]) {
                        a[i + k * n].push_back(x + (1 - l) * n);
                        a[x + l * n].push_back(i + (1 - k) * n);
                    }
                }
            }
        }
    }
    for (int i = 1;i <= n * 2;i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1;i <= n;i++) {
        if (b[i] == b[i + n]) return 0;
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            scanf("%d", &ain[i][j]);
        }
        if (ain[i][1] == 0) num[i][0] = 1, num[i][1] = 2;
        if (ain[i][1] == 1) num[i][0] = 0, num[i][1] = 2;
        if (ain[i][1] == 2) num[i][0] = 0, num[i][1] = 1;
    }
    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}
