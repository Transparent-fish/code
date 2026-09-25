#include <bits/stdc++.h>
using namespace std;
#define endl cerr<<"------------------I Love Chtholly Tree------------------\n";
// #define int long long
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
int x_1, y_1, x_2, y_2;

int bfs(int x, int y) {
    if (x == 1 && y == 0)return 3;
    if (x == 2 && y == 2)return 4;
    if (y <= x - y) {
        if ((x & 1) == 0)return x / 2 + (x / 2 - y) % 2;
        else return (x + 1) / 2 + ((x + 1) / 2 - y + 1) % 2;
    }
    if (y > x - y)return bfs(x + 1, y - 1);
}

signed main() {
    in >> x_1 >> y_1 >> x_2 >> y_2;
    int _ = max(abs(x_1 - x_2), abs(y_1 - y_2)), __ = min(abs(x_1 - x_2), abs(y_1 - y_2));
    out << bfs(_, __);
    return 0;
}