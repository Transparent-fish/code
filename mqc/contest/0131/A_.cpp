#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
double p;
double ans, cnt, q1, jxj = 1;

void dfs(int x, int z, double q)
{
    if(x == k + 1)
    {
        if(z > k / 2)
        {
            q1 += q;
            cnt++;
        }
        return;
    }
    dfs(x + 1, z + 1, q * p);
    dfs(x + 1, z, q * (1 - p));
}

void dfs1(int l, int r, double pp)
{
    if(l > r) return;
    if(r - 1 == l)
    {
        ans += pp * (2.0 / n);
        return;
    }
    dfs1((l + r >> 1LL) + 1, r, pp * q1);
    dfs1(l, (l + r >> 1LL) - 1, pp * q1);
    ans += pp * (1.0 / n);
}

signed main()
{
    freopen("tiancai.in", "r", stdin);
    freopen("tiancai.out", "w", stdout);
    cin >> n >> p >> k;
    dfs(1, 0, 1);
    if(n <= 1e5)
    {
        dfs1(1, n, 1);
        cout << fixed << setprecision(4) << ans;
        return 0;
    }
    int N = n, tot = 1;
    while(n)
    {
        double p1 = min(n, tot) * 1.0 / N;
        ans += p1 * jxj;
        n -= min(n, tot);
        tot *= 2;
        if(n < tot)
        {
            ans += n * 1.0 / N * jxj;
            break;
        }
        jxj *= q1;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}