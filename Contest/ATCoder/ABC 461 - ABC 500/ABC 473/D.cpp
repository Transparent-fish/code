#include <bits/stdc++.h>
using namespace std;
#define endl cerr<<"------------------I Love Chtholly Tree------------------\n";
#define int long long
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc getchar
#define pc putchar
#endif

#define ds(x) (x=='\r'||x=='\n'||x==' ')
#define MAX 20
namespace fastIO {
    template<typename T>inline void r(T& a) {
        a = 0;
        char ch = gc();
        bool ok = 0;
        for (; ch < '0' || ch > '9';)
            ok ^= (ch == '-'), ch = gc();
        for (; ch >= '0' && ch <= '9';)
            a = (a << 1) + (a << 3) + (ch ^ 48), ch = gc();
        if (ok)
            a = -a;
    }
    template<typename T>inline void w(T a) {
        if (a == 0) {
            pc('0');
            return;
        }
        static char ch[MAX];
        int till = 0;
        if (a < 0) {
            pc('-');
            for (; a;)
                ch[till++] = -(a % 10), a /= 10;
        }
        else
            for (; a;)
                ch[till++] = a % 10, a /= 10;
        for (; till;)
            pc(ch[--till] ^ 48);
    }
    struct Srr {
        inline Srr operator>>(int& a) {
            r(a);
            return{};
        }
        inline Srr operator>>(char& ch) {
            ch = gc();
            for (; ds(ch);)
                ch = gc();
            return{};
        }
        inline Srr operator>>(string& s) {
            s = "";
            char ch = gc();
            for (; ds(ch);)
                ch = gc();
            for (; !(ds(ch) || ch == EOF);) {
                s.push_back(ch);
                ch = gc();
            }
            return{};
        }
        template<typename T>inline Srr operator<<(T& a) {
            r(a);
            return{};
        }
        inline void is(int n, string& s) {
            s = "";
            char ch = gc();
            for (; ds(ch);)
                ch = gc();
            for (; n--;) {
                s.push_back(ch);
                ch = gc();
            }
        }
    } in;
    struct Sww {
        inline Sww operator<<(const int a) {
            w(a);
            return{};
        }
        inline Sww operator<<(const char ch) {
            pc(ch);
            return{};
        }
        inline Sww operator<<(const string s) {
            for (int i = 0; i < s.size(); i++)
                pc(s[i]);
            return{};
        }
        template<typename T>inline Sww operator>>(const T a) {
            w(a);
            return{};
        }
    } out;
} using fastIO::in;
using fastIO::out;
#undef ds
const int N = 200005;
int n, k;
vector<int> now;
bool dp[12][N];
int h[12][N];

void dfs(int x, int sum) {
    if (x == n + 1) {
        for (auto c : now) out << c << " ";
        out << "\n";
        return;
    }
    int res = h[x][k - sum];
    for (;res >= 0;) {
        now.push_back((k - sum - res) / x);
        dfs(x + 1, k - res);
        now.pop_back();
        res = (res >= x) ? h[x][res - x] : -1;
    }
}

signed main() {
    in >> n >> k;
    dp[n + 1][0] = 1;
    for (int x = n; x >= 1; x--) {
        for (int i = 0; i <= k; i++) {
            dp[x][i] = dp[x + 1][i];
            if (i >= x) dp[x][i] = dp[x][i] | dp[x][i - x];
        }
    }
    for (int x = 1; x <= n; x++) {
        for (int i = 0; i <= k; i++) {
            if (dp[x + 1][i]) h[x][i] = i;
            else if (i >= x) h[x][i] = h[x][i - x];
            else h[x][i] = -1;
        }
    }
    dfs(1, 0);
    return 0;
}
