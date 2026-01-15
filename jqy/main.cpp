#include "pzd.h"
//-lgraphics64 -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32
//-lgraphics -luuid -lmsimg32 -lgdi32 -limm32 -lole32 -loleaut32
//#pragma GCC optimize(2) o2
#define ll int
#define FCM(a,b,m) (Pvc=(unsigned ll)a*b-(unsigned ll)((long double)a/m*b+0.5L)*m,Pvc<m?Pvc:m+Pvc)

//#define rw() ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
namespace Pv {
	template<typename T> inline T FMM(T A, T B, T C) {
		T N_UM = 1, Ba_se = A % C;
		unsigned ll Pvc;
		while (B) {
			if (B & 1)
				N_UM = FCM(N_UM, Ba_se, C);
			Ba_se = FCM(Ba_se, Ba_se, C);
			B >>= 1;
		}
		return N_UM;
	}
	template<typename T>inline bool IPan(T x) {
		if (x <= 10) {
			if (x == 2 || x == 3 || x == 5 || x == 7)
				return 1;
			return 0;
		} else {
			if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0)
				return 0;
			if (x < 64)
				return 1;
			if (x <= 10000000) {
				for (ll i = 15;; i += 6) {
					if (x % (i - 4) == 0)
						return 0;
					if ((i - 4) * (i - 4) > x)
						return 1;
					if (x % (i - 2) == 0)
						return 0;
					if ((i - 2) * (i - 2) > x)
						return 1;
				}
				return 1;
			}
			const ll n_um[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
			T A = x - 1, v;
			short t = 0;
			unsigned ll Pvc;
			while (!(A & 1))
				A >>= 1, t++;
			for (ll i = 0; i < 7; i++) {
				v = FMM(n_um[i], A, x);
				if (v == 1)
					continue;
				short u = 0;
				for (; u < t; u++) {
					if (v == x - 1)
						break;
					v = FCM(v, v, x);
				}
				if (u == t)
					return 0;
			}
			return 1;
		}
	}
}
#ifndef rw()
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

namespace Pv {
	template<typename T> inline void r(T &in) {
		in = 0;
		bool bo = 0;
		char ch = getchar();
		while (!isdigit(ch))
			bo ^= (ch == '-'), ch = getchar();
		while (isdigit(ch))
			in = (in << 1) + (in << 3) + (ch ^ 48), ch = getchar();
		if (bo)
			in = -in;
	}
	template<typename T> inline void w(T out) {
		static char op[25];
		int top = 0;
		if (out < 0) {
			putchar('-');
			do {
				op[++top] = -(out % 10) + 48, out /= 10;
			} while (out);
		} else {
			do {
				op[++top] = out % 10 + 48, out /= 10;
			} while (out);
		}
		while (top)
			putchar(op[top--]);
		putchar(' ');
	}
	template<typename T, typename... Ts> inline void r(T &in, Ts &... ins) {
		r(in), r(ins...);
	}
	template<typename T, typename... Ts> inline void w(T out, Ts... outs) {
		w(out), w(outs...);
	}
	inline void w(const char *p) {
		while (*p) {
			putchar(*p++);
		}
	}
}
#undef getchar
#undef putchar
#endif
using namespace Pv;
using namespace std;
using namespace ege;
mt19937 rd(time(0));

color_t ys[8] = {WHITE, RED, EGERGB(0xFF, 0xA5, 0x00), YELLOW, GREEN, BLUE, MAGENTA, EGERGB(0x54, 0x54, 0x54)};
ll fvmod = 1;
ll danx[4], dany[4]; //当前x 格子
ll qkidx[4], qkidy[4]; // 区块id
ll sjid, X[6] = {0, -1, 0, 1}, Y[6] = {-1, 0, 1, 0}, xiaoshi, fen, miao, jishi; //世界id 上，左，下，右
//小时 分钟 秒 计时
ll ve, dengji, tfd, tfg = 10, tfx = 100; // 玩家 方向,血量，攻击力，等级，吸血
long long  Hp, Gong, maxHp;
long long bag[66];// 经验 TREE STONE
ll wpl[10], danwp, ji_nid = -2, chixt, fchixt[6]; // 物品栏 技能id 持续时间
bool can_do = 1, jzd, tzd, cantp, caid, but;
ll ptzdw;


ll XX[6] = {-1, -1, 1, 1}, XY[6] = {-1, 1, -1, 1};
string user;

void schp(ll x, ll y, long long num, long long num1) {
	ll sx = x * 30 + 4, sy = y * 30 + 4, ox = sx + ceil(num * 20.0L / num1);
	setcolor(RED);
	line(sx, sy, ox, sy);
	setcolor(WHITE);
}
void sds(char dsth);
void beigong(ll x, ll y, long long zs = 0);
void scwp(ll x, bool bo);
void scwpcd(ll x);

// 线性插值函数
color_t lerpColor(color_t start, color_t end, float ratio) {
	ratio = fmaxf(0.0f, fminf(1.0f, ratio)); // 确保ratio在[0,1]范围内

	int r1 = GetRValue(start), g1 = GetGValue(start), b1 = GetBValue(start);
	int r2 = GetRValue(end), g2 = GetGValue(end), b2 = GetBValue(end);

	int r = static_cast<int>(r1 + (r2 - r1) * ratio);
	int g = static_cast<int>(g1 + (g2 - g1) * ratio);
	int b = static_cast<int>(b1 + (b2 - b1) * ratio);

	return RGB(r, g, b);
}

void jgshu(ll left, ll top, ll width, ll height, color_t jgys) {
	color_t orange = jgys;  // 更鲜明的橙色
	color_t white = RGB(255, 255, 255); // 白色

	// 矩形位置和尺寸
//    int left = 100, top = 0;
//    int width = 90, height = 200;

	// 绘制整个矩形渐变
	for (int x = 0; x < width; x++) {
		float ratio;
		color_t color;

		if (x < width / 2) {
			// 左半部分：橙色 -> 白色
			ratio = static_cast<float>(x) / (width / 2);
			color = lerpColor(orange, white, ratio);
		} else {
			// 右半部分：白色 -> 橙色
			ratio = static_cast<float>(x - width / 2) / (width / 2);
			color = lerpColor(white, orange, ratio);
		}

		// 绘制当前竖条
		setcolor(color);
		line(left + x, top, left + x, top + height);
	}
}

void jgheng(ll left, ll top, ll width, ll height, color_t jgys) {
	color_t orange = jgys;  // 鲜明的橙色
	color_t white = RGB(255, 255, 255); // 白色

	// 矩形位置和尺寸
//    int left = 120, top = 80;
//    int width = 400, height = 300;

	// 绘制垂直渐变矩形
	for (int y = 0; y < height; y++) {
		float ratio;
		color_t color;

		// 上半部分：橙色到白色渐变
		if (y < height / 2) {
			ratio = static_cast<float>(y) / (height / 2);
			color = lerpColor(orange, white, ratio);
		}
		// 下半部分：白色到橙色渐变
		else {
			ratio = static_cast<float>(y - height / 2) / (height / 2);
			color = lerpColor(white, orange, ratio);
		}

		// 绘制当前水平线
		setcolor(color);
		line(left, top + y, left + width, top + y);
	}
}
void scgz(ll x, ll y, ll num, bool bian, color_t danys = WHITE);
void scbhp(ll x, unsigned long long hp, unsigned long long maxhp, color_t danys = WHITE);
void scgzhp(ll x, ll y);
void scqk();

struct QK { //区块
	ll a[32][22];
	bool bo;
} qk[4][32][32];

struct JIAN { // 剑
	long long gong[8] = {6, 180, 1145, 6700, 19347, 346012, 5094327, 9978541216}, xt, do_jian[8], mdoj[8] = {40, 50, 50, 50, 80, 90, 180, 300},
	                    XI[8] = {0, 0, 104, 512, 1834, 19527, 399680, 8798720}, chixu[8]
	                            = {30, 30, 30, 2, 6, 70, 80, 120}; // max_do_jian 吸血
	long long xishu = 1, x_xishu = 1; // 系数
	bool ha = 0;
	void shengji() {
		if (!ha) {
			return;
		}
		if (xt == 0) {
			if (bag[1] < 260 || bag[2] < 200 || bag[3] < 30 || bag[11] < 3) {
				return;
			}
			bag[1] -= 260;
			bag[2] -= 200;
			bag[3] -= 30;
			bag[11] -= 3;
			if (yyzy[1] - bag[1] != 260 || yyzy[2] - bag[2] != 200 || yyzy[3] - bag[3] != 30 || yyzy[11] - bag[11] != 3) {
				pdzrecg;
			}
			yyzy[1] -= 260;
			yyzy[2] -= 200;
			yyzy[3] -= 30;
			yyzy[11] -= 3;
			xt++;
		} else if (xt == 1) {
			if (bag[1] < 460 || bag[2] < 390 || bag[3] < 50 || bag[11] < 5 || bag[12] < 3 || bag[10] < 1 || bag[5] < 5) {
				return;
			}
			bag[1] -= 460;
			bag[2] -= 290;
			bag[3] -= 50;
			bag[11] -= 5;
			bag[12] -= 3;
			bag[10] -= 1;
			bag[5] -= 5;
			if (yyzy[1] - bag[1] != 460 || yyzy[2] - bag[2] != 290 || yyzy[3] - bag[3] != 50 || yyzy[11] - bag[11] != 5
			        || yyzy[12] - bag[12] != 3 || yyzy[10] - bag[10] != 1 || yyzy[5] - bag[5] != 5) {
				pdzrecg;
			}
			yyzy[1] -= 460;
			yyzy[2] -= 290;
			yyzy[3] -= 50;
			yyzy[11] -= 5;
			yyzy[12] -= 3;
			yyzy[10] -= 1;
			yyzy[5] -= 5;
			xt++;
		} else if (xt == 2) {
			if (bag[1] < 1490 || bag[2] < 1290 || bag[3] < 100 || bag[11] < 35 || bag[12] < 23 || bag[10] < 12 || bag[5] < 10) {
				return;
			}
			bag[1] -= 1490;
			bag[2] -= 1290;
			bag[3] -= 100;
			bag[11] -= 35;
			bag[12] -= 23;
			bag[10] -= 12;
			bag[5] -= 10;
			if (yyzy[1] - bag[1] != 1490 || yyzy[2] - bag[2] != 1290 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 35
			        || yyzy[12] - bag[12] != 23 || yyzy[10] - bag[10] != 12 || yyzy[5] - bag[5] != 10) {
				pdzrecg;
			}
			yyzy[1] -= 1490;
			yyzy[2] -= 1290;
			yyzy[3] -= 100;
			yyzy[11] -= 35;
			yyzy[12] -= 23;
			yyzy[10] -= 12;
			yyzy[5] -= 10;
			xt++;
		} else if (xt == 3) {
			if (bag[1] < 3666 || bag[2] < 2666 || bag[3] < 200 || bag[11] < 70 || bag[12] < 40 || bag[10] < 20 || bag[5] < 30
			        || bag[4] < 2) {
				return;
			}
			bag[1] -= 3666;
			bag[2] -= 2666;
			bag[3] -= 200;
			bag[11] -= 70;
			bag[12] -= 40;
			bag[10] -= 20;
			bag[5] -= 30;
			bag[4] -= 2;
			if (yyzy[1] - bag[1] != 3666 || yyzy[2] - bag[2] != 2666 || yyzy[3] - bag[3] != 200 || yyzy[11] - bag[11] != 70
			        || yyzy[12] - bag[12] != 40 || yyzy[10] - bag[10] != 20 || yyzy[5] - bag[5] != 30 || yyzy[4] - bag[4] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 3666;
			yyzy[2] -= 2666;
			yyzy[3] -= 200;
			yyzy[11] -= 70;
			yyzy[12] -= 40;
			yyzy[10] -= 20;
			yyzy[5] -= 30;
			yyzy[4] -= 2;
			xt++;
		} else if (xt == 4) {
			if (bag[1] < 5000 || bag[2] < 4000 || bag[3] < 500 || bag[11] < 150 || bag[12] < 90 || bag[10] < 114 || bag[5] < 1145
			        || bag[4] < 25 || bag[6] < 2) {
				return;
			}
			bag[1] -= 5000;
			bag[2] -= 4000;
			bag[3] -= 500;
			bag[11] -= 150;
			bag[12] -= 90;
			bag[10] -= 114;
			bag[5] -= 1145;
			bag[4] -= 25;
			bag[6] -= 2;
			if (yyzy[1] - bag[1] != 5000 || yyzy[2] - bag[2] != 4000 || yyzy[3] - bag[3] != 500 || yyzy[11] - bag[11] != 150
			        || yyzy[12] - bag[12] != 90 || yyzy[10] - bag[10] != 114 || yyzy[5] - bag[5] != 1145 || yyzy[4] - bag[4] != 25
			        || yyzy[6] - bag[6] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 5000;
			yyzy[2] -= 4000;
			yyzy[3] -= 500;
			yyzy[11] -= 150;
			yyzy[12] -= 90;
			yyzy[10] -= 114;
			yyzy[5] -= 1145;
			yyzy[4] -= 25;
			yyzy[6] -= 2;
			xt++;
		} else if (xt == 5) {
			if (bag[1] < 10000 || bag[2] < 7000 || bag[3] < 1200 || bag[11] < 350 || bag[12] < 260 || bag[10] < 164 || bag[5] < 9527
			        || bag[4] < 50 || bag[6] < 5 || bag[13] < 2) {
				return;
			}
			bag[1] -= 10000;
			bag[2] -= 7000;
			bag[3] -= 1200;
			bag[11] -= 350;
			bag[12] -= 260;
			bag[10] -= 164;
			bag[5] -= 9527;
			bag[4] -= 50;
			bag[6] -= 5;
			bag[13] -= 2;
			if (yyzy[1] - bag[1] != 10000 || yyzy[2] - bag[2] != 7000 || yyzy[3] - bag[3] != 1200 || yyzy[11] - bag[11] != 350
			        || yyzy[12] - bag[12] != 260 || yyzy[10] - bag[10] != 164 || yyzy[5] - bag[5] != 9527 || yyzy[4] - bag[4] != 50
			        || yyzy[6] - bag[6] != 5 || yyzy[13] - bag[13] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 10000;
			yyzy[2] -= 7000;
			yyzy[3] -= 1200;
			yyzy[11] -= 350;
			yyzy[12] -= 260;
			yyzy[10] -= 164;
			yyzy[5] -= 9527;
			yyzy[4] -= 50;
			yyzy[6] -= 5;
			yyzy[13] -= 2;
			xt++;
		} else if (xt == 6) {
			if (bag[1] < 20000 || bag[2] < 15000 || bag[3] < 2300 || bag[11] < 570 || bag[12] < 420 || bag[10] < 700
			        || bag[5] < 20000
			        || bag[4] < 80 || bag[6] < 18 || bag[13] < 4 || bag[17] < 2) {
				return;
			}
			bag[1] -= 20000;
			bag[2] -= 15000;
			bag[3] -= 2300;
			bag[11] -= 570;
			bag[12] -= 420;
			bag[10] -= 700;
			bag[5] -= 20000;
			bag[4] -= 80;
			bag[6] -= 18;
			bag[13] -= 4;
			bag[17] -= 2;
			if (yyzy[1] - bag[1] != 20000 || yyzy[2] - bag[2] != 15000 || yyzy[3] - bag[3] != 2300 || yyzy[11] - bag[11] != 570
			        || yyzy[12] - bag[12] != 420 || yyzy[10] - bag[10] != 700 || yyzy[5] - bag[5] != 20000 || yyzy[4] - bag[4] != 80
			        || yyzy[6] - bag[6] != 18 || yyzy[13] - bag[13] != 4 || yyzy[17] - bag[17] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 20000;
			yyzy[2] -= 15000;
			yyzy[3] -= 2300;
			yyzy[11] -= 570;
			yyzy[12] -= 420;
			yyzy[10] -= 700;
			yyzy[5] -= 20000;
			yyzy[4] -= 80;
			yyzy[6] -= 18;
			yyzy[13] -= 4;
			yyzy[17] -= 2;
			xt++;
		}
	}
	void fjineng(ll x) {
		if (x < 0 || x > 7) {
			return;
		}
		w(do_jian[x]);
		if (x > xt) {
			return;
		}
		if (!do_jian[x]) {
			ji_nid = x;
			do_jian[x] = mdoj[x];
			chixt = chixu[x];
			if (x == 0) {
				xishu = 2; //增伤
			} else if (x == 1) {
				return;//减伤
			} else if (x == 2) {
				x_xishu = 4;
			} else if (x == 3) {// 蓄力
				can_do = 0;
				xishu = 12;
				x_xishu = 20;
			} else if (x == 4) { //剑气 and 蓄力
				can_do = 0;
				xishu = 13;
				x_xishu = 37;
			} else if (x == 5) { // 强化
				xishu = 3;
				x_xishu = 7;
			} else if (x == 6) {
				//霸体
				but = 1;
			} else if (x == 7) { // 剑气 霸体 强化
				but = 1;
				xishu = 6;
				x_xishu = 8;
				for (ll i = 0; i < 4; i++) {
					ll nx = danx[sjid], ny = dany[sjid];
					while (1) {
						nx += X[i], ny += Y[i];
						if (!(nx >= 0 && nx < 30 && ny >= 0 && ny < 20)) {
							break;
						}
						beigong(nx, ny);
					}
					nx = danx[sjid], ny = dany[sjid];
					while (1) {
						nx += XX[i], ny += XY[i];
						if (!(nx >= 0 && nx < 30 && ny >= 0 && ny < 20)) {
							break;
						}
						beigong(nx, ny);
					}
				}
			}
		}
	}
	void sjineng() {
		if (ji_nid == 0) {
			xishu = 1;
		} else if (ji_nid == 1) {
			return;
		} else if (ji_nid == 2) {
			x_xishu = 1;
		} else if (ji_nid == 3) {
			can_do = 1;
			sds('f');
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 4) {
			can_do = 1;
			ll x = danx[sjid], y = dany[sjid];
			while (1) {
				x += X[ve], y += Y[ve];
				if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
					break;
				}
				beigong(x, y);
			}
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 5) {
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 6) {
			but = 0;
		} else if (ji_nid == 7) {
			for (ll i = 0; i < 4; i++) {
				ll nx = danx[sjid], ny = dany[sjid];
				while (1) {
					nx += X[i], ny += Y[i];
					if (!(nx >= 0 && nx < 30 && ny >= 0 && ny < 20)) {
						break;
					}
					beigong(nx, ny);
				}
				nx = danx[sjid], ny = dany[sjid];
				while (1) {
					nx += XX[i], ny += XY[i];
					if (!(nx >= 0 && nx < 30 && ny >= 0 && ny < 20)) {
						break;
					}
					beigong(nx, ny);
				}
			}
			but = 0;
			xishu = 1;
			x_xishu = 1;
		}
	}
} Jian;

struct DAO { // 刀
	long long gong[8] = {6, 190, 1155, 6900, 20123, 360101, 5100984, 9991521210}, xt, do_jian[8], mdoj[8] = {50, 50, 300, 60, 80, 90, 10, 300},
	                    XI[8]
	                    = {0, 20, 150, 666, 2134, 26381, 498551, 9876543}, chixu[8] = {20, 15, 120, 2, 6, 60, 1, 130};
	long long xishu = 1, x_xishu = 1; // 系数
	bool ha = 0;
	void shengji() {
		if (!ha) {
			return;
		}
		if (xt == 0) {
			if (bag[1] < 260 || bag[2] < 200 || bag[3] < 30 || bag[11] < 7) {
				return;
			}
			bag[1] -= 260;
			bag[2] -= 200;
			bag[3] -= 30;
			bag[11] -= 7;
			if (yyzy[1] - bag[1] != 260 || yyzy[2] - bag[2] != 200 || yyzy[3] - bag[3] != 30 || yyzy[11] - bag[11] != 7) {
				pdzrecg;
			}
			yyzy[1] -= 260;
			yyzy[2] -= 200;
			yyzy[3] -= 30;
			yyzy[11] -= 7;
			xt++;
		} else if (xt == 1) {
			if (bag[1] < 460 || bag[2] < 390 || bag[3] < 50 || bag[11] < 15 || bag[12] < 6 || bag[10] < 1 || bag[5] < 5) {
				return;
			}
			bag[1] -= 460;
			bag[2] -= 290;
			bag[3] -= 50;
			bag[11] -= 15;
			bag[12] -= 6;
			bag[10] -= 1;
			bag[5] -= 5;
			if (yyzy[1] - bag[1] != 460 || yyzy[2] - bag[2] != 290 || yyzy[3] - bag[3] != 50 || yyzy[11] - bag[11] != 15
			        || yyzy[12] - bag[12] != 6 || yyzy[10] - bag[10] != 1 || yyzy[5] - bag[5] != 5) {
				pdzrecg;
			}
			yyzy[1] -= 460;
			yyzy[2] -= 290;
			yyzy[3] -= 50;
			yyzy[11] -= 15;
			yyzy[12] -= 6;
			yyzy[10] -= 1;
			yyzy[5] -= 5;
			xt++;
		} else if (xt == 2) {
			if (bag[1] < 1490 || bag[2] < 1290 || bag[3] < 100 || bag[11] < 45 || bag[12] < 27 || bag[10] < 12 || bag[5] < 10) {
				return;
			}
			bag[1] -= 1490;
			bag[2] -= 1290;
			bag[3] -= 100;
			bag[11] -= 45;
			bag[12] -= 27;
			bag[10] -= 12;
			bag[5] -= 10;
			if (yyzy[1] - bag[1] != 1490 || yyzy[2] - bag[2] != 1290 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 45
			        || yyzy[12] - bag[12] != 27 || yyzy[10] - bag[10] != 12 || yyzy[5] - bag[5] != 10) {
				pdzrecg;
			}
			yyzy[1] -= 1490;
			yyzy[2] -= 1290;
			yyzy[3] -= 100;
			yyzy[11] -= 45;
			yyzy[12] -= 27;
			yyzy[10] -= 12;
			yyzy[5] -= 10;
			xt++;
		} else if (xt == 3) {
			if (bag[1] < 3666 || bag[2] < 2666 || bag[3] < 200 || bag[11] < 89 || bag[12] < 66 || bag[10] < 20 || bag[5] < 30
			        || bag[4] < 2) {
				return;
			}
			bag[1] -= 3666;
			bag[2] -= 2666;
			bag[3] -= 200;
			bag[11] -= 89;
			bag[12] -= 66;
			bag[10] -= 20;
			bag[5] -= 30;
			bag[4] -= 2;
			if (yyzy[1] - bag[1] != 3666 || yyzy[2] - bag[2] != 2666 || yyzy[3] - bag[3] != 200 || yyzy[11] - bag[11] != 89
			        || yyzy[12] - bag[12] != 66 || yyzy[10] - bag[10] != 20 || yyzy[5] - bag[5] != 30 || yyzy[4] - bag[4] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 3666;
			yyzy[2] -= 2666;
			yyzy[3] -= 200;
			yyzy[11] -= 89;
			yyzy[12] -= 66;
			yyzy[10] -= 20;
			yyzy[5] -= 30;
			yyzy[4] -= 2;
			xt++;
		} else if (xt == 4) {
			if (bag[1] < 5000 || bag[2] < 4000 || bag[3] < 500 || bag[11] < 190 || bag[12] < 120 || bag[10] < 114 || bag[5] < 1145
			        || bag[4] < 25 || bag[6] < 2) {
				return;
			}
			bag[1] -= 5000;
			bag[2] -= 4000;
			bag[3] -= 500;
			bag[11] -= 190;
			bag[12] -= 120;
			bag[10] -= 114;
			bag[5] -= 1145;
			bag[4] -= 25;
			bag[6] -= 2;
			if (yyzy[1] - bag[1] != 5000 || yyzy[2] - bag[2] != 4000 || yyzy[3] - bag[3] != 500 || yyzy[11] - bag[11] != 190
			        || yyzy[12] - bag[12] != 120 || yyzy[10] - bag[10] != 114 || yyzy[5] - bag[5] != 1145 || yyzy[4] - bag[4] != 25
			        || yyzy[6] - bag[6] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 5000;
			yyzy[2] -= 4000;
			yyzy[3] -= 500;
			yyzy[11] -= 190;
			yyzy[12] -= 120;
			yyzy[10] -= 114;
			yyzy[5] -= 1145;
			yyzy[4] -= 25;
			yyzy[6] -= 2;
			xt++;
		} else if (xt == 5) {
			if (bag[1] < 10000 || bag[2] < 7000 || bag[3] < 1200 || bag[11] < 400 || bag[12] < 290 || bag[10] < 164 || bag[5] < 9527
			        || bag[4] < 50 || bag[6] < 5 || bag[13] < 2) {
				return;
			}
			bag[1] -= 10000;
			bag[2] -= 7000;
			bag[3] -= 1200;
			bag[11] -= 400;
			bag[12] -= 290;
			bag[10] -= 164;
			bag[5] -= 9527;
			bag[4] -= 50;
			bag[6] -= 5;
			bag[13] -= 2;
			if (yyzy[1] - bag[1] != 10000 || yyzy[2] - bag[2] != 7000 || yyzy[3] - bag[3] != 1200 || yyzy[11] - bag[11] != 400
			        || yyzy[12] - bag[12] != 290 || yyzy[10] - bag[10] != 164 || yyzy[5] - bag[5] != 9527 || yyzy[4] - bag[4] != 50
			        || yyzy[6] - bag[6] != 5 || yyzy[13] - bag[13] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 10000;
			yyzy[2] -= 7000;
			yyzy[3] -= 1200;
			yyzy[11] -= 400;
			yyzy[12] -= 290;
			yyzy[10] -= 164;
			yyzy[5] -= 9527;
			yyzy[4] -= 50;
			yyzy[6] -= 5;
			yyzy[13] -= 2;
			xt++;
		} else if (xt == 6) {
			if (bag[1] < 20000 || bag[2] < 15000 || bag[3] < 2300 || bag[11] < 640 || bag[12] < 490 || bag[10] < 700
			        || bag[5] < 20000
			        || bag[4] < 80 || bag[6] < 18 || bag[13] < 4 || bag[17] < 2) {
				return;
			}
			bag[1] -= 20000;
			bag[2] -= 15000;
			bag[3] -= 2300;
			bag[11] -= 640;
			bag[12] -= 490;
			bag[10] -= 700;
			bag[5] -= 20000;
			bag[4] -= 80;
			bag[6] -= 18;
			bag[13] -= 4;
			bag[17] -= 2;
			if (yyzy[1] - bag[1] != 20000 || yyzy[2] - bag[2] != 15000 || yyzy[3] - bag[3] != 2300 || yyzy[11] - bag[11] != 640
			        || yyzy[12] - bag[12] != 490 || yyzy[10] - bag[10] != 700 || yyzy[5] - bag[5] != 20000 || yyzy[4] - bag[4] != 80
			        || yyzy[6] - bag[6] != 18 || yyzy[13] - bag[13] != 4 || yyzy[17] - bag[17] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 20000;
			yyzy[2] -= 15000;
			yyzy[3] -= 2300;
			yyzy[11] -= 640;
			yyzy[12] -= 490;
			yyzy[10] -= 700;
			yyzy[5] -= 20000;
			yyzy[4] -= 80;
			yyzy[6] -= 18;
			yyzy[13] -= 4;
			yyzy[17] -= 2;
			xt++;
		}
	}
	void fjineng(ll x) {
		if (x < 0 || x > 7) {
			return;
		}
		w(do_jian[x]);
		if (x > xt) {
			return;
		}
		if (!do_jian[x]) {
			ji_nid = x;
			do_jian[x] = mdoj[x];
			chixt = chixu[x];
			if (x == 0) {//增伤
				xishu = 3;
			} else if (x == 1) {//回血
				return;
			} else if (x == 2) {//抢夺
				return;
			} else if (x == 3) {//蓄力
				can_do = 0;
				xishu = 13;
				x_xishu = 21;
			} else if (x == 4) { // 蓄力 and 三飞镖
				can_do = 0;
				xishu = 10;
				x_xishu = 20;
			} else if (x == 5) {//强化
				xishu = 5;
				x_xishu = 10;
			} else if (x == 6) {//闪现
				ll nx = danx[sjid], ny = dany[sjid];
				while (1) {
					nx += X[ve], ny += Y[ve];
					scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
					     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
					scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]) {
							nx -= X[ve], ny -= Y[ve];
							qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = -1;
							qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
							scgz(danx[sjid], dany[sjid], 0, 0);
							scgz(nx, ny, -1, 0);
							schp(nx, ny, Hp, maxHp);
							danx[sjid] = nx, dany[sjid] = ny;
							scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
							     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
							scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
							return;
						}
					} else {
						return;
					}
				}
			} else if (x == 7) { // 有传送，有回血
				xishu = 7;
				x_xishu = 8;
				cantp = 1;
			}
		}
	}
	void sjineng() {
		if (ji_nid == 0) {
			xishu = 1;
		} else if (ji_nid == 1) {
			return;
		} else if (ji_nid == 2) {
			return;
		} else if (ji_nid == 3) {
			can_do = 1;
			sds('f');
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 4) {
			can_do = 1;
			ll cishu = 3;
			while (cishu--) {
				ll x = danx[sjid], y = dany[sjid];
				while (1) {
					x += X[ve], y += Y[ve];
					if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
						break;
					}
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						beigong(x, y);
						break;
					}
				}
			}
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 5) {
			xishu = 1;
			x_xishu = 1;
		} else if (ji_nid == 6) {
			return;
		} else if (ji_nid == 7) {
			xishu = 1;
			x_xishu = 1;
			cantp = 0;
		}
	}
} dao;

struct QIANG {
	long long gong[8] = {11, 310, 2303, 10123, 89854, 984561, 9100000, 13991521210LL}, xt, do_jian[8], mdoj[8] = {30, 30, 70, 70, 100, 100, 100, 300},
	                    XI[8]
	                    = {10, 100, 850, 1450, 4650, 54121, 1240121, 21451201}, chixu[8] = {20, 15, 3, 5, 50, 50, 50, 120};
	long long xishu = 1, x_xishu = 1, zzd = 0, zshang; // 系数
	bool ha = 0;
	void shengji() {
		if (!ha) {
			return;
		}
		if (xt == 0) {
			if (bag[1] < 260 || bag[2] < 200 || bag[3] < 30 || bag[11] < 7) {
				return;
			}
			bag[1] -= 260;
			bag[2] -= 200;
			bag[3] -= 30;
			bag[11] -= 7;
			if (yyzy[1] - bag[1] != 260 || yyzy[2] - bag[2] != 200 || yyzy[3] - bag[3] != 30 || yyzy[11] - bag[11] != 7) {
				pdzrecg;
			}
			yyzy[1] -= 260;
			yyzy[2] -= 200;
			yyzy[3] -= 30;
			yyzy[11] -= 7;
			xt++;
		} else if (xt == 1) {
			if (bag[1] < 460 || bag[2] < 390 || bag[3] < 50 || bag[11] < 15 || bag[12] < 6 || bag[10] < 1 || bag[5] < 5) {
				return;
			}
			bag[1] -= 460;
			bag[2] -= 290;
			bag[3] -= 50;
			bag[11] -= 15;
			bag[12] -= 6;
			bag[10] -= 1;
			bag[5] -= 5;
			if (yyzy[1] - bag[1] != 460 || yyzy[2] - bag[2] != 290 || yyzy[3] - bag[3] != 50 || yyzy[11] - bag[11] != 15
			        || yyzy[12] - bag[12] != 6 || yyzy[10] - bag[10] != 1 || yyzy[5] - bag[5] != 5) {
				pdzrecg;
			}
			yyzy[1] -= 460;
			yyzy[2] -= 290;
			yyzy[3] -= 50;
			yyzy[11] -= 15;
			yyzy[12] -= 6;
			yyzy[10] -= 1;
			yyzy[5] -= 5;
			xt++;
		} else if (xt == 2) {
			if (bag[1] < 1490 || bag[2] < 1290 || bag[3] < 100 || bag[11] < 45 || bag[12] < 27 || bag[10] < 12 || bag[5] < 10) {
				return;
			}
			bag[1] -= 1490;
			bag[2] -= 1290;
			bag[3] -= 100;
			bag[11] -= 45;
			bag[12] -= 27;
			bag[10] -= 12;
			bag[5] -= 10;
			if (yyzy[1] - bag[1] != 1490 || yyzy[2] - bag[2] != 1290 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 45
			        || yyzy[12] - bag[12] != 27 || yyzy[10] - bag[10] != 12 || yyzy[5] - bag[5] != 10) {
				pdzrecg;
			}
			yyzy[1] -= 1490;
			yyzy[2] -= 1290;
			yyzy[3] -= 100;
			yyzy[11] -= 45;
			yyzy[12] -= 27;
			yyzy[10] -= 12;
			yyzy[5] -= 10;
			xt++;
		} else if (xt == 3) {
			if (bag[1] < 3666 || bag[2] < 2666 || bag[3] < 200 || bag[11] < 89 || bag[12] < 66 || bag[10] < 20 || bag[5] < 30
			        || bag[4] < 2) {
				return;
			}
			bag[1] -= 3666;
			bag[2] -= 2666;
			bag[3] -= 200;
			bag[11] -= 89;
			bag[12] -= 66;
			bag[10] -= 20;
			bag[5] -= 30;
			bag[4] -= 2;
			if (yyzy[1] - bag[1] != 3666 || yyzy[2] - bag[2] != 2666 || yyzy[3] - bag[3] != 200 || yyzy[11] - bag[11] != 89
			        || yyzy[12] - bag[12] != 66 || yyzy[10] - bag[10] != 20 || yyzy[5] - bag[5] != 30 || yyzy[4] - bag[4] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 3666;
			yyzy[2] -= 2666;
			yyzy[3] -= 200;
			yyzy[11] -= 89;
			yyzy[12] -= 66;
			yyzy[10] -= 20;
			yyzy[5] -= 30;
			yyzy[4] -= 2;
			xt++;
		} else if (xt == 4) {
			if (bag[1] < 5000 || bag[2] < 4000 || bag[3] < 500 || bag[11] < 190 || bag[12] < 120 || bag[10] < 114 || bag[5] < 1145
			        || bag[4] < 25 || bag[6] < 2) {
				return;
			}
			bag[1] -= 5000;
			bag[2] -= 4000;
			bag[3] -= 500;
			bag[11] -= 190;
			bag[12] -= 120;
			bag[10] -= 114;
			bag[5] -= 1145;
			bag[4] -= 25;
			bag[6] -= 2;
			if (yyzy[1] - bag[1] != 5000 || yyzy[2] - bag[2] != 4000 || yyzy[3] - bag[3] != 500 || yyzy[11] - bag[11] != 190
			        || yyzy[12] - bag[12] != 120 || yyzy[10] - bag[10] != 114 || yyzy[5] - bag[5] != 1145 || yyzy[4] - bag[4] != 25
			        || yyzy[6] - bag[6] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 5000;
			yyzy[2] -= 4000;
			yyzy[3] -= 500;
			yyzy[11] -= 190;
			yyzy[12] -= 120;
			yyzy[10] -= 114;
			yyzy[5] -= 1145;
			yyzy[4] -= 25;
			yyzy[6] -= 2;
			xt++;
		} else if (xt == 5) {
			if (bag[1] < 10000 || bag[2] < 7000 || bag[3] < 1200 || bag[11] < 400 || bag[12] < 290 || bag[10] < 164 || bag[5] < 9527
			        || bag[4] < 50 || bag[6] < 5 || bag[13] < 2) {
				return;
			}
			bag[1] -= 10000;
			bag[2] -= 7000;
			bag[3] -= 1200;
			bag[11] -= 400;
			bag[12] -= 290;
			bag[10] -= 164;
			bag[5] -= 9527;
			bag[4] -= 50;
			bag[6] -= 5;
			bag[13] -= 2;
			if (yyzy[1] - bag[1] != 10000 || yyzy[2] - bag[2] != 7000 || yyzy[3] - bag[3] != 1200 || yyzy[11] - bag[11] != 400
			        || yyzy[12] - bag[12] != 290 || yyzy[10] - bag[10] != 164 || yyzy[5] - bag[5] != 9527 || yyzy[4] - bag[4] != 50
			        || yyzy[6] - bag[6] != 5 || yyzy[13] - bag[13] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 10000;
			yyzy[2] -= 7000;
			yyzy[3] -= 1200;
			yyzy[11] -= 400;
			yyzy[12] -= 290;
			yyzy[10] -= 164;
			yyzy[5] -= 9527;
			yyzy[4] -= 50;
			yyzy[6] -= 5;
			yyzy[13] -= 2;
			xt++;
		} else if (xt == 6) {
			if (bag[1] < 20000 || bag[2] < 15000 || bag[3] < 2300 || bag[11] < 640 || bag[12] < 490 || bag[10] < 700
			        || bag[5] < 20000
			        || bag[4] < 80 || bag[6] < 18 || bag[13] < 4 || bag[17] < 2) {
				return;
			}
			bag[1] -= 20000;
			bag[2] -= 15000;
			bag[3] -= 2300;
			bag[11] -= 640;
			bag[12] -= 490;
			bag[10] -= 700;
			bag[5] -= 20000;
			bag[4] -= 80;
			bag[6] -= 18;
			bag[13] -= 4;
			bag[17] -= 2;
			if (yyzy[1] - bag[1] != 20000 || yyzy[2] - bag[2] != 15000 || yyzy[3] - bag[3] != 2300 || yyzy[11] - bag[11] != 640
			        || yyzy[12] - bag[12] != 490 || yyzy[10] - bag[10] != 700 || yyzy[5] - bag[5] != 20000 || yyzy[4] - bag[4] != 80
			        || yyzy[6] - bag[6] != 18 || yyzy[13] - bag[13] != 4 || yyzy[17] - bag[17] != 2) {
				pdzrecg;
			}
			yyzy[1] -= 20000;
			yyzy[2] -= 15000;
			yyzy[3] -= 2300;
			yyzy[11] -= 640;
			yyzy[12] -= 490;
			yyzy[10] -= 700;
			yyzy[5] -= 20000;
			yyzy[4] -= 80;
			yyzy[6] -= 18;
			yyzy[13] -= 4;
			yyzy[17] -= 2;
			xt++;
		}
	}
	void fjineng(ll x) {
		if (x < 0 || x > 7) {
			return;
		}
		w(do_jian[x]);
		if (x > xt) {
			return;
		}
		if (!do_jian[x]) {
			ji_nid = x;
			do_jian[x] = mdoj[x];
			chixt = chixu[x];
			if (x == 0) {// 15子弹+1000真伤
				zzd = 15;
				zshang = 1000;
			} else if (x == 1) {//强化
				xishu = 3;
				x_xishu = 5;
			} else if (x == 2) {//蓄力穿透+2000真伤
				can_do = 0;
				zshang = 2000;
				xishu = 12;
				x_xishu = 20;
			} else if (x == 3) {//蓄力3*3爆炸+2000真伤
				can_do = 0;
				zshang = 2000;
				xishu = 20;
				x_xishu = 35;
			} else if (x == 4) {//20子弹+1000真伤+穿透
				zzd = 20;
				zshang = 1000;
				xishu = 3;
				x_xishu = 5;
			} else if (x == 5) {//强化+2000真伤
				xishu = 3;
				x_xishu = 7;
				zshang = 2000;
			} else if (x == 6) {//5000真伤+50子弹
				zshang = 5000;
				zzd = 50;
			} else if (x == 7) {//5000真伤+998244353子弹+穿透+强化
				zshang = 12000;
				zzd = 998244353;
				xishu = 6;
				x_xishu = 9;
			}
		}
	}
	void sjineng() {
		if (ji_nid == 0) {
			zzd = 0;
			zshang = 0;
		} else if (ji_nid == 1) {
			xishu = x_xishu = 1;
		} else if (ji_nid == 2) {
			can_do = 1;
			ll x = danx[sjid], y = dany[sjid];
			while (1) {
				x += X[ve], y += Y[ve];
				if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
					break;
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
					beigong(x, y, zshang);
				}
			}
			xishu = 1;
			x_xishu = 1;
			zshang = 0;
		} else if (ji_nid == 3) {
			can_do = 1;
			ll x = danx[sjid], y = dany[sjid];
			while (1) {
				x += X[ve], y += Y[ve];
				if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
					break;
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
					beigong(x, y, zshang);
					for (ll i = 0; i < 4; i++) {
						ll nx = x + X[i], ny = y + Y[i];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
							beigong(nx, ny, zshang);
						}
						nx = x + XX[i], ny = y + XY[i];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
							beigong(nx, ny, zshang);
						}
					}
					break;
				}
			}
			xishu = 1;
			x_xishu = 1;
			zshang = 0;
		} else if (ji_nid == 4) {
			xishu = 1;
			x_xishu = 1;
			zshang = 0;
			zzd = 0;
		} else if (ji_nid == 5) {
			xishu = 1;
			x_xishu = 1;
			zshang = 0;
		} else if (ji_nid == 6) {
			zshang = 0;
			zzd = 0;
		} else if (ji_nid == 7) {
			xishu = 1;
			x_xishu = 1;
			zshang = 0;
			zzd = 0;
		}
	}
} qiang;

struct BIAN { //鞭
	long long gong[8] = {40102, 246351, 1116655, 99521227, 889947569LL, 78897569877LL, 9611200478465LL, 999999999999999LL}, zgong[8]
	                    = {100, 500, 1500, 5500, 16000, 37000, 65000, 1000000000000000LL}, xt, do_jian[9], mdoj[9] = {1, 50, 100, 0, 0, 0, 0, 3},
	                            XI[8]
	                            = {1001, 9876, 31211, 114514, 31415926, 447114441LL, 5744775554LL, 99999999999999LL}, chixu[9] = {1, 1, 2, 0, 0, 0, 0, 0, 2};
	long long xishu = 1, x_xishu = 1; // 系数
	bool ha = 0, boxt, bo[32][22];
	void shengji() {
		if (!ha) {
			ha = 1;
			for (ll i = 0; i < 10; i++) {
				if (!wpl[i]) {
					wpl[i] = 4;
					scwp(i, (i == danwp));
					if (i == danwp) {
						scwpcd(4);
					}
					break;
				}
			}
			return;
		}
		xt = max(__builtin_popcount(ptzdw) - 1LL, xt);
		for (ll i = 0; i < 10; i++) {
			if (wpl[i] == 4) {
				scwp(i, (i == danwp));
				break;
			}
		}
	}
	void fjineng(ll x) {
		if (x < 0 || x > 8) {
			return;
		}
		w(do_jian[x]);
		if (!do_jian[x]) {
			ji_nid = x;
			do_jian[x] = mdoj[x];
			chixt = chixu[x];
			if (x == 0) {//转xt
				boxt ^= 1;
				cantp ^= 1;
				but ^= 1;
			} else if (x == 1) {//回血回满
				Hp = maxHp;
			} else if (x == 2) {//100 10 直线
				xishu=x_xishu=100;
				can_do=0;
				ll nx = danx[sjid] + X[ve], ny = dany[sjid] + Y[ve];
				while(1){
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
						bo[nx][ny] = 1;
						scgz(nx, ny, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny], (danx[sjid] + X[ve] == nx && ny == dany[sjid] + Y[ve]));
						scgzhp(nx, ny);
					}else{
						break;
					}
					nx+=X[ve];
					ny+=Y[ve];
				}
			} else if (x == 3) {//
			} else if (x == 4) {//
			} else if (x == 5) {//
			} else if (x == 6) {//
			} else if (x == 7) {//
			} else if (x == 8) { // 强普
				chixt += (!boxt);
				can_do = 0;
				xishu = 2;
				x_xishu = 2;
				for (ll i = 0; i < 4; i++) {
					if (i != (ve + 2) % 4) {
						ll nx = danx[sjid] + X[i], ny = dany[sjid] + Y[i];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
							bo[nx][ny] = 1;
							scgz(nx, ny, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny], (danx[sjid] + X[ve] == nx && ny == dany[sjid] + Y[ve]));
							scgzhp(nx, ny);
						}
						nx += X[i], ny += Y[i];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
							bo[nx][ny] = 1;
							scgz(nx, ny, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny], (danx[sjid] + X[ve] == nx && ny == dany[sjid] + Y[ve]));
							scgzhp(nx, ny);
						}
					}
				}
				for (ll T = 1, jibo = 0, bocnt = 0; T <= 2; T++) {
					bocnt = (T << 1);
					for (ll i = max(0, danx[sjid] - 2); i <= min(29, danx[sjid] + 2) && bocnt; i++) {
						if (ve == 2) {
							for (ll u = min(19, dany[sjid] + 2); u >= max(0, dany[sjid] - 2) && bocnt; u--) {
								if (bo[i][u] || (i == danx[sjid] && u == dany[sjid])) {
									continue;
								}
								jibo = 0;
								for (ll VE = 0; VE < 4; VE++) {
									ll nx = i + X[VE], ny = u + Y[VE];
									if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
										jibo += bo[nx][ny];
									}
								}
								if (jibo == 2) {
									bocnt--;
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (danx[sjid] + X[ve] == i && u == dany[sjid] + Y[ve]));
									scgzhp(i, u);
								}
							}
						} else {
							for (ll u = max(0, dany[sjid] - 2); u <= min(19, dany[sjid] + 2) && bocnt; u++) {
								if (bo[i][u] || (i == danx[sjid] && u == dany[sjid])) {
									continue;
								}
								jibo = 0;
								for (ll VE = 0; VE < 4; VE++) {
									ll nx = i + X[VE], ny = u + Y[VE];
									if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
										jibo += bo[nx][ny];
									}
								}
								if (jibo == 2) {
									bocnt--;
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (danx[sjid] + X[ve] == i && u == dany[sjid] + Y[ve]));
									scgzhp(i, u);
								}
							}
						}

					}
				}
			}
		}
	}
	void sjineng() {
		if (ji_nid == 0) {
			return;
		} else if (ji_nid == 1) {
			return;
		} else if (ji_nid == 2) {
			can_do = 1;
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					if (bo[i][u]) {
						bo[i][u] = 0;
						beigong(i, u, zgong[xt]*10);
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (danx[sjid] + X[ve] == i && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
			}
			xishu = x_xishu = 1;
		} else if (ji_nid == 3) {
		} else if (ji_nid == 4) {
		} else if (ji_nid == 5) {
		} else if (ji_nid == 6) {
		} else if (ji_nid == 7) {
		} else if (ji_nid == 8) {
			can_do = 1;
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					if (bo[i][u]) {
						bo[i][u] = 0;
						beigong(i, u, zgong[xt]);
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (danx[sjid] + X[ve] == i && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
			}
			xishu = x_xishu = 1;
		}
	}
} bian;

void wqjia(long long x, long long y) {
	if (x == 1) {
		Gong += Jian.gong[Jian.xt] * y * Jian.xishu;
	} else if (x == 2) {
		Gong += dao.gong[dao.xt] * y * dao.xishu;
	} else if (x == 3) {
		Gong += qiang.gong[qiang.xt] * y * qiang.xishu;
	} else if (x == 4) {
		Gong += bian.gong[bian.xt] * y * bian.xishu;
	}
}

void wqxi(ll x) {
	if (x == 1) {
		Hp = min(maxHp, Hp + Jian.XI[Jian.xt] * Jian.x_xishu);
	} else if (x == 2) {
		Hp = min(maxHp, Hp + dao.XI[dao.xt] * dao.x_xishu);
	} else if (x == 3) {
		Hp = min(maxHp, Hp + qiang.XI[qiang.xt] * qiang.x_xishu);
	} else if (x == 4) {
		Hp = min(maxHp, Hp + bian.XI[bian.xt] * bian.x_xishu);
	}
}

void wqlq(ll x) {
	if (x == 1) {
		for (ll i = 0; i < 8; i++) {
			if (Jian.do_jian[i])
				Jian.do_jian[i]--;
		}
	} else if (x == 2) {
		for (ll i = 0; i < 8; i++) {
			if (dao.do_jian[i])
				dao.do_jian[i]--;
		}
	} else if (x == 3) {
		for (ll i = 0; i < 8; i++) {
			if (qiang.do_jian[i])
				qiang.do_jian[i]--;
		}
	} else if (x == 4) {
		for (ll i = 0; i < 9; i++) {
			if (bian.do_jian[i]) {
				bian.do_jian[i]--;
			}
		}
	}
}

void scwpcd(ll x) {
	for (ll jn = 0; jn < 8; jn++) {
		for (ll i = 900; i < 930; i++) {
			for (ll u = (11 + jn) * 30; u < (11 + jn) * 30 + 30; u++) {
				if (i == 900 || i == 929 || u == (11 + jn) * 30 || u == (11 + jn) * 30 + 29) {
					putpixel(i, u, ys[jn]);
				} else {
					putpixel(i, u, BLACK);
				}
			}
		}
	}
	string out;
	switch (x) {
		case 1: {
			for (ll jn = 0; jn < 8; jn++) {
				if (ji_nid == jn) {
					setcolor(ys[4]);
					if (chixt < 1000) {
						out = to_string(chixt);
					} else {
						out = "+++";
					}
				} else {
					setcolor(ys[0]);
					if (Jian.do_jian[jn] < 1000) {
						out = to_string(Jian.do_jian[jn]);
					} else {
						out = "+++";
					}
				}
				xyprintf(903, (11 + jn) * 30 + 8, out.c_str());
			}
			break;
		}
		case 2: {
			for (ll jn = 0; jn < 8; jn++) {
				if (ji_nid == jn) {
					setcolor(ys[4]);
					if (chixt < 1000) {
						out = to_string(chixt);
					} else {
						out = "+++";
					}
				} else {
					setcolor(ys[0]);
					if (dao.do_jian[jn] < 1000) {
						out = to_string(dao.do_jian[jn]);
					} else {
						out = "+++";
					}
				}
				xyprintf(903, (11 + jn) * 30 + 8, out.c_str());
			}
			break;
		}
		case 3: {
			for (ll jn = 0; jn < 8; jn++) {
				if (ji_nid == jn) {
					setcolor(ys[4]);
					if (chixt < 1000) {
						out = to_string(chixt);
					} else {
						out = "+++";
					}
				} else {
					setcolor(ys[0]);
					if (qiang.do_jian[jn] < 1000) {
						out = to_string(qiang.do_jian[jn]);
					} else {
						out = "+++";
					}
				}
				xyprintf(903, (11 + jn) * 30 + 8, out.c_str());
			}
			break;
		}
		case 4: {
			for (ll jn = 0; jn < 8; jn++) {
				if (ji_nid == jn) {
					setcolor(ys[4]);
					if (chixt < 1000) {
						out = to_string(chixt);
					} else {
						out = "+++";
					}
				} else {
					setcolor(ys[0]);
					if (bian.do_jian[jn] < 1000) {
						out = to_string(bian.do_jian[jn]);
					} else {
						out = "+++";
					}
				}
				xyprintf(903, (11 + jn) * 30 + 8, out.c_str());
			}
			break;
		}
	}
}

void scwp(ll x, bool bo) {
	for (ll i = 900; i < 930; i++) {
		for (ll u = x * 30; u < x * 30 + 30; u++) {
			if (i == 900 || i == 929 || u == x * 30 || u == x * 30 + 29) {
				if (bo) {
					putpixel(i, u, RED);
				} else {
					putpixel(i, u, WHITE);
				}
			}
		}
	}
	switch (wpl[x]) {
		case 1: {
			setcolor(ys[Jian.xt]);
			xyprintf(907, x * 30 + 7, "剑");
			break;
		}
		case 2: {
			setcolor(ys[dao.xt]);
			xyprintf(907, x * 30 + 7, "刀");
			break;
		}
		case 3: {
			setcolor(ys[qiang.xt]);
			xyprintf(907, x * 30 + 7, "枪");
			break;
		}
		case 4: {
			setcolor(ys[bian.xt]);
			xyprintf(907, x * 30 + 7, "鞭");
			break;
		}
	}
}

void wj_jhp(long long gong, ll op) {
	if (wpl[danwp] == 1 && (ji_nid == 1 || ji_nid == 4 || ji_nid == 6 || ji_nid == 7)) {
		gong -= min((long long)(gong * (Jian.xt + 1) / 10.0), (Jian.gong[Jian.xt] << 1));
	}
	if (gong <= 0) {
		return;
	}
	Hp -= gong;
	if (Hp <= 0) {
		for (ll i = 0; i < 930; i++) {
			for (ll u = 0; u < 660; u++) {
				putpixel(i, u, BLACK);
			}
		}
		freopen(user.c_str(), "w", stdout);
		setcolor(ys[0]);
		if (op == 3) {
			xyprintf(7, 7, "怪：小怪得了MVP！");
		} else if (op == 4) {
			xyprintf(7, 7, "帝：这就不行了吗？这只是我的虚影啊。");
		} else if (op == 6) {
			xyprintf(7, 7, "FVV：比FVV还废物。");
		} else if (op == 13) {
			xyprintf(7, 7, "FX：你收集石头了吗？一点石粒都没有。");
		} else if (op == 14) {
			xyprintf(7, 7, "X：别忘了还有我。");
		} else if (op == 15) {
			xyprintf(7, 7, "Pv：外卖放门口——菜到家了。");
		} else if (op == 16) {
			if (caid) {
				xyprintf(7, 7, "帝：下辈子注意");
			} else if (jzd) {
				xyprintf(7, 7, "帝：这是御驾亲征的力量");
			} else if (tzd) {
				xyprintf(7, 7, "帝：别妄想挑战帝威");
			}
		} else if (op == 17) {
			xyprintf(7, 7, "兵：皇家护卫军获得胜利");
		} else if (op == 18) {
			xyprintf(7, 7, "耐罚王：罚时吃饱了");
		}
		char dsth = getch();
		while (dsth != 27) {
			dsth = getch();
		}
		exit(0);
	}
	scgz(danx[sjid], dany[sjid], -1, 0);
	schp(danx[sjid], dany[sjid], Hp, maxHp);
}
ll bfs(ll x, ll y);

ll xbfs(ll x, ll y) {
	queue<pair<ll, ll> >q;
	ll dis[32][22];
	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			dis[i][u] = -1;
		}
	}
	dis[x][y] = 0;
	for (ll i = 0; i < 4; i++) {
		ll nx = x + X[i], ny = y + Y[i];
		if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
		        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1)) {
			dis[nx][ny] = i;
			q.push({nx, ny});
		}
	}
	for (ll i = 0; i < 4; i++) {
		ll nx = x + XX[i], ny = y + XY[i];
		if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
		        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1)) {
			dis[nx][ny] = i + 4;
			q.push({nx, ny});
		}
	}
	if (dis[danx[sjid]][dany[sjid]] != -1) {
		return dis[danx[sjid]][dany[sjid]];
	}
	while (q.size()) {
		ll xx = q.front().first, yy = q.front().second;
		q.pop();
		for (ll i = 0; i < 4; i++) {
			ll nx = xx + X[i], ny = yy + Y[i];
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && dis[nx][ny] == -1 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
			        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1)) {
				dis[nx][ny] = dis[xx][yy];
				q.push({nx, ny});
			}
		}
		for (ll i = 0; i < 4; i++) {
			ll nx = xx + XX[i], ny = yy + XY[i];
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && dis[nx][ny] == -1 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
			        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1)) {
				dis[nx][ny] = dis[xx][yy];
				q.push({nx, ny});
			}
		}
		if (dis[danx[sjid]][dany[sjid]] != -1) {
			return dis[danx[sjid]][dany[sjid]];
		}
	}
	return -1;
}

struct FVVX {
	ll cnt, mcnt = 0, do_jian[32][22], jian_ge, id[32][22];
	bool bl[32][22], bo[1006];
	set<ll>op[32][22];
	void scfvvx() {
		if (cnt < mcnt) {
//			jian_ge++;
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 14;
						scgz(x, y, 14, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						while (1) {
							ll num = rd() % 1000 + 1;
							if (!bo[num]) {
								bo[num] = 1;
								id[x][y] = num;
								break;
							}
						}
						break;
					}
				}
			}
		}
	}
	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if (bl[x][y]) {
			if (do_jian[x][y] == 9) {
				bl[x][y] = 0;
				do_jian[x][y] = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (op[i][u].find(id[x][y]) == op[i][u].end()) {
							continue;
						}
						op[i][u].erase(id[x][y]);
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case -1: {
								wj_jhp((maxHp - Hp) >> 2, 14);
								break;
							}
						}
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
			}
		} else {
			if (do_jian[x][y] < 3) {
				return;
			}
			do_jian[x][y] = 0;
			if (rd() % 100 <= 90) {
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
						scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						bo[id[x][y]] = 0;
						cnt--;
						wj_jhp(maxHp >> 2, 14);
						return;
					}
				}
				for (ll i = 0; i < 4; i++) {
					ll nx = x + XX[i], ny = y + XY[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
						scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						bo[id[x][y]] = 0;
						cnt--;
						wj_jhp(maxHp >> 2, 14);
						return;
					}
				}
				ll VE = xbfs(x, y);
				if (VE == -1) {
					goto fvvxfjn;
				}
				ll nx, ny;
				if (VE >= 4) {
					nx = x + XX[VE - 4], ny = y + XY[VE - 4];
				} else {
					nx = x + X[VE], ny = y + Y[VE];
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 14;
				swap(id[x][y], id[nx][ny]);
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 14, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				return;
			}
fvvxfjn:
			bl[x][y] = 1;
			op[x][y].insert(id[x][y]);
			scgz(x, y, 14, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			for (ll i = 0; i < 4; i++) {
				ll nx = x + XX[i], ny = y + XY[i];
				while (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
					op[nx][ny].insert(id[x][y]);
					scgz(nx, ny, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny], (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					nx += XX[i], ny += XY[i];
				}
			}
		}
	}
} fvvx[4][32][32];

struct BING { // 兵
	ll cnt, mcnt = 0, do_jian[32][22], id[32][22];
	long long hp[32][22], maxhp = 1000000000000LL;
	bool bl[32][22];
	set<ll>op[32][22];
	void scbing(ll x, ll y, ll vid) {
		if (cnt < mcnt) {
			cnt++;
			hp[x][y] = maxhp;
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 17;
			scgz(x, y, 17, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
//			schp(x, y, 1, 1);
			id[x][y] = vid;
		}
	}
	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if (bl[x][y]) {
			if (do_jian[x][y] >= 7) {
				bl[x][y] = 0;
				do_jian[x][y] = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (!op[i][u].size() || op[i][u].find(id[x][y]) == op[i][u].end()) {
							continue;
						}
						op[i][u].erase(id[x][y]);
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case -1: {
								wj_jhp((maxHp >> 4), 17);
								break;
							}
						}
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
			}
		} else {
			if (do_jian[x][y] < 4) {
				return;
			}
			do_jian[x][y] = 0;
//			if (rd() % 100 <= 90) {
			if (danx[sjid] == x) {
				bl[x][y] = 1;
				if (y < dany[sjid]) {
					for (ll i = y + 1; i < 20; i++) {
						op[x][i].insert(id[x][y]);
						scgz(x, i, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][i], (x == danx[sjid] + X[ve] && i == dany[sjid] + Y[ve]));
					}
				} else {
					for (ll i = y - 1; i >= 0; i--) {
						op[x][i].insert(id[x][y]);
						scgz(x, i, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][i], (x == danx[sjid] + X[ve] && i == dany[sjid] + Y[ve]));
					}
				}
				return;
			}
			if (y == dany[sjid]) {
				bl[x][y] = 1;
				if (x < danx[sjid]) {
					for (ll i = x + 1; i < 30; i++) {
						op[i][y].insert(id[x][y]);
						scgz(i, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][y], (i == danx[sjid] + X[ve] && y == dany[sjid] + Y[ve]));
					}
				}
				if (x > danx[sjid]) {
					for (ll i = x - 1; i >= 0; i--) {
						op[i][y].insert(id[x][y]);
						scgz(i, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][y], (i == danx[sjid] + X[ve] && y == dany[sjid] + Y[ve]));
					}
				}
				return;
			}
			ll VE = bfs(x, y);
			if (VE == -1) {
				return;
			}
			ll nx, ny;
//				if (VE >= 4) {
//					nx = x + XX[VE - 4], ny = y + XY[VE - 4];
//				} else {
			nx = x + X[VE], ny = y + Y[VE];
//				}
			if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]) {
				return;
			}
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 17;
			swap(id[x][y], id[nx][ny]);
			scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			scgz(nx, ny, 17, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
			scgzhp(nx, ny);
			return;
//			}
		}
	}
} bing[4][32][32];

char dh[32][32] = { // 帝画
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000010000000000000000",
	"000000000000001000000000000000",
	"000000000111111111110000000000",
	"000000000000000000000000000000",
	"000000000001000001000000000000",
	"000000000000100010000000000000",
	"000000001111111111111100000000",
	"000000001000001000000100000000",
	"000000010000001000001000000000",
	"000000000011111111100000000000",
	"000000000010001000100000000000",
	"000000000010001000100000000000",
	"000000000010001010100000000000",
	"000000000010001001000000000000",
	"000000000000001000000000000000",
	"000000000000001000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
	"000000000000000000000000000000",
};
void initd(ll x, unsigned long long lahp = 0);

struct D {//最终BOSS 10000000 13
	unsigned long long hp[32][22], maxhp[9] = {100000000000000000LL, 10000000000000LL, 10000000000000LL, 10000000000000LL, 10000000000000LL, 10000000000000LL, 10000000, 1000000000000000LL, 18446744073709551615ull},
	        gong[9] = {10000000000LL, 10000000, 10000000, 10000000, 10000000, 10000000, 10000000, 1000000000, 300000000000000LL},
	                  mcxt[9] = {30, 90, 1, 70, 50, 60, 60, 90, 114514};
	ll xt[32][22], do_jian[32][22], id[32][22], bo[32][22][6], cxt;
	bool bl[32][22], idbo[6], kills[32][6], killh[22][6], killbl[6], bkills[32][6], bkillh[22][6];
	void hdh(ll x) { // 画帝画
		ll cnt = 3;
		for (ll i = 0; i < 900; i++) {
			for (ll u = 0; u < 600; u++) {
				putpixel(i, u, BLACK);
			}
		}
//		for (ll i=750;i<900;i++){
//			for (ll u=0;u<600;u++){
//				putpixel(i,u,BLACK);
//			}
//		}
		do {
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 30; u++) {
					if (dh[i][u] == '1') {
						if (rd() % cnt == 0)
							for (ll xy = 20 * i; xy < 20 * i + 20; xy++) {
								for (ll xx = 150 + u * 20; xx < 150 + u * 20 + 20; xx++) {
									putpixel(xx, xy, ys[x]);
								}
							}
					} else {
						for (ll xy = 20 * i; xy < 20 * i + 20; xy++) {
							for (ll xx = 150 + u * 20; xx < 150 + u * 20 + 20; xx++) {
								putpixel(xx, xy, BLACK);
							}
						}
					}
				}
			}
			cnt--;
			auto x = clock();
			while (x + 300 > clock()) {

			}
//			usleep(300000);
		} while (cnt);
	}
	void tpsj() {
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				scgz(i, u, 0, 0);
			}
		}
		scgz(0, 0, 0, 1);
		xyprintf(1 * 30 + 7, 7, "世界0");
		xyprintf(1 * 30 + 7, 1 * 30 + 7, "世界1");
		xyprintf(1 * 30 + 7, 2 * 30 + 7, "世界2");
		xyprintf(1 * 30 + 7, 3 * 30 + 7, "世界3");
		ll xzid = 0;
		char dsth = getch();
		while (dsth) {
			if (dsth == 13) {
				sjid = xzid;
				break;
			} else {
				scgz(0, xzid, 0, 0);
				if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(3, xzid + 1);
				}
				scgz(0, xzid, 0, 1);
			}
			dsth = getch();
		}
	}
	void tzxt() {
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				scgz(i, u, 0, 0);
			}
		}
		setcolor(ys[0]);
		xyprintf(7, 7, "帝：选择一个形态。");
		scgz(0, 1, 0, 1);
		setcolor(ys[1]);
		xyprintf(1 * 30 + 7, 1 * 30 + 7, "帝：召唤X");
		setcolor(ys[2]);
		xyprintf(1 * 30 + 7, 2 * 30 + 7, "帝：分身术");
		setcolor(ys[3]);
		xyprintf(1 * 30 + 7, 3 * 30 + 7, "帝：控制");
		setcolor(ys[4]);
		xyprintf(1 * 30 + 7, 4 * 30 + 7, "帝：回血");
		setcolor(ys[5]);
		xyprintf(1 * 30 + 7, 5 * 30 + 7, "帝：超快攻速");
		setcolor(ys[6]);
		xyprintf(1 * 30 + 7, 6 * 30 + 7, "帝：逆天防御，少血量");
		setcolor(ys[7]);
		xyprintf(1 * 30 + 7, 7 * 30 + 7, "帝：高血量，高攻击");
		ll xzid = 1;
		char dsth = getch();
		while (dsth) {
			if (dsth == 13) {
				tzd = 1;
				initd(xzid);
				break;
			} else {
				scgz(0, xzid, 0, 0);
				if (dsth == '&') {
					xzid = max(1, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(7, xzid + 1);
				}
				scgz(0, xzid, 0, 1);
			}
			dsth = getch();
		}
	}
	unsigned long long dmaxhp(ll x, ll y) {
		if (jzd) {
			return maxhp[0];
		}
		if (caid) {
			return maxhp[8];
		}
		return maxhp[xt[x][y]];
	}
	void hdosth(ll x = 0) {
		if (jzd || tzd) {
			return;
		}
		ll xzid = 0;
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				scgz(i, u, 0, 0);
			}
		}
		if (x == 1) {
			tpsj();
			return;
		} else if (x == 2) {
			tzxt();
			return;
		}
		xyprintf(7, 7, "帝：你要做什么，我可以帮你。");
		scgz(0, 1, 0, 1);
		xyprintf(1 * 30 + 7, 1 * 30 + 7, "没事");
		xyprintf(1 * 30 + 7, 2 * 30 + 7, "传送到");
		xyprintf(1 * 30 + 7, 3 * 30 + 7, "挑战");
		char dsth = getch();
		while (dsth) {
			if (dsth == 13) {
				if (xzid == 0) {
					break;
				} else if (xzid == 1) {
					tpsj();
				} else if (xzid == 2) {
					tzxt();
					return;
				}
				break;
			} else {
				scgz(0, xzid + 1, 0, 0);
				if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(2, xzid + 1);
				}
				scgz(0, xzid + 1, 0, 1);
			}
			dsth = getch();
		}
		scqk();
	}
	void dsth(ll x, ll y) {
		do_jian[x][y]++;
		if (cxt && !idbo[2]) {
			cxt--;
		}
		if ((do_jian[x][y] == 2 && (xt[x][y] == 5 || caid)) || (do_jian[x][y] == 5 && xt[x][y] != 5 && !caid)
		        || (do_jian[x][y] == 3
		            && killbl[id[x][y]])) {
			do_jian[x][y] = 0;
			if (bl[x][y]) {
				bl[x][y] = 0;
				for (ll i = 0; i < 30; i++) {
					if (kills[i][id[x][y]]) {
						jgshu(i * 30 - 30, 0, 90, 599, ys[2]);
						killbl[id[x][y]] = 1;
//						continue;
					}
					if (bkills[i][id[x][y]]) {
						jgshu(i * 30, 0, 30, 599, ys[7]);
						killbl[id[x][y]] = 1;
					}
					for (ll u = 0; u < 20; u++) {
						if (killh[u][id[x][y]]) {
							jgheng(0, u * 30 - 30, 899, 90, ys[2]);
							killbl[id[x][y]] = 1;
//							continue;
						}
						if (bkillh[u][id[x][y]]) {
							jgheng(0, u * 30, 899, 30, ys[7]);
							killbl[id[x][y]] = 1;
						}
						if (!bo[i][u][id[x][y]]) {
							continue;
						}
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case -1: {
								if (bo[i][u][id[x][y]] == 2) {
									fchixt[0] += 6;
								} else if (bo[i][u][id[x][y]] == 3) {
									fchixt[1] += 15;
								} else if (bo[i][u][id[x][y]] == 4) {
									fchixt[2] += 15;
								}
								wj_jhp(gong[xt[x][y]], 16);
								if (xt[x][y] == 4) {
									hp[x][y] = min(hp[x][y] + 60 * min(gong[xt[x][y]], 1uLL * Hp), dmaxhp(x, y));
								} else {
									if (tzd && xt[x][y] == 6) {
										hp[x][y] = min(hp[x][y] + (dmaxhp(x, y) >> 7), dmaxhp(x, y));
									} else {
										hp[x][y] = min(hp[x][y] + 8 * min(gong[xt[x][y]], 1uLL * Hp), dmaxhp(x, y));
									}
								}
								break;
							}
							case 16: {
								if (bo[i][u][id[x][y]] == 3) {
									if (xt[x][y] == 4 || caid) {
										hp[x][y] = min(dmaxhp(x, y), hp[x][y] + (dmaxhp(x, y) >> 5));
									} else if (xt[x][y] == 6) {
										if (tzd) {
											hp[x][y] = min(dmaxhp(x, y), hp[x][y] + (dmaxhp(x, y) >> 9));
										} else {
											hp[x][y] = min(dmaxhp(x, y), hp[x][y] + (dmaxhp(x, y) >> 7));
										}
									} else {
										hp[x][y] = min(dmaxhp(x, y), hp[x][y] + (dmaxhp(x, y) >> 7));
									}
								}
								break;
							}
						}
						bo[i][u][id[x][y]] = 0;
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
				scbhp(16, hp[x][y], dmaxhp(x, y), ys[xt[x][y]]);
				return;
			}
			if (killbl[id[x][y]]) {
				killbl[id[x][y]] = 0;
				for (ll i = 0; i < 30; i++) {
					bkills[i][id[x][y]] = kills[i][id[x][y]] = 0;
					for (ll u = 0; u < 20; u++) {
						bkillh[u][id[x][y]] = killh[u][id[x][y]] = 0;
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
				}
				return;
			}
			if (!cxt && jzd && id[x][y] == 1) {
				while (1) {
					ll nxt = rd() % 8;
//					if (xt[x][y]!=1){
//						nxt=1;
//					}
					if (nxt != xt[x][y]) {
						initd(nxt, hp[x][y]);
						break;
					}
				}
				return;
			}
			bool bol = 0;
			bool pan = (rd() % 10 <= 7);
			if (!pan)
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						if (xt[x][y] != 6) {
							if (xt[x][y] == 4) {
								hp[x][y] = min(hp[x][y] + 100 * min(gong[xt[x][y]], 1uLL * Hp), dmaxhp(x, y));
							} else {
								hp[x][y] = min(hp[x][y] + 10 * min(gong[xt[x][y]], 1uLL * Hp), dmaxhp(x, y));
							}
						} else {
							hp[x][y] = min(dmaxhp(x, y), hp[x][y] + (dmaxhp(x, y) >> 8));
						}
						bol = 1;
						scbhp(16, hp[x][y], (dmaxhp(x, y)), ys[xt[x][y]]);
						wj_jhp(gong[xt[x][y]], 16);
						break;
					}
				}
			if (!bol) {
				bl[x][y] = 1;
				ll op;
				if (caid) {
					op = 114514;
				} else if (hp[x][y] * 10 < dmaxhp(x, y)) {
					op = 3;
				} else if ((tzd && xt[x][y]) || (jzd && xt[x][y] > 0 && xt[x][y] < 7)) {
					op = rd() % 4;
				} else if (!xt[x][y]) {
					op = rd() % 2 + 4;
				} else {
					op = 6;
				}
				if (op == 2) {
					bool boshu = (rd() & 1), boheng = (rd() & 1);
					for (ll i = boheng; i < 29 + boheng; i++) {
						for (ll u = boshu; u < 19 + boshu; u++) {
							bo[i][u][id[x][y]] = 2;
							scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						}
					}
				} else if (op == 0) {
dop1bucheng:
					ll cnt = 11;
					short heng[22], shu[32];
					memset(heng, 0, sizeof heng);
					memset(shu, 0, sizeof shu);
					heng[dany[sjid]] = shu[danx[sjid]] = rd() % 2 + 2;
					while (cnt--) {
						while (1) {
							ll num = rd() % 30;
							if (!shu[num]) {
								shu[num] = rd() % 4 + 1;
								break;
							}
						}
						while (1) {
							ll num = rd() % 20;
							if (!heng[num]) {
								heng[num] = rd() % 4 + 1;
								break;
							}
						}
					}
					for (ll u = 0; u < 20; u++) {
						if (heng[u]) {
							if (xt[x][y] == 3) {
								heng[u] = 2;
							}
							for (ll i = 0; i < 30; i++) {
								bo[i][u][id[x][y]] = heng[u];
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					}
					for (ll i = 0; i < 30; i++) {
						if (shu[i]) {
							if (xt[x][y] == 3) {
								shu[i] = 2;
							}
							for (ll u = 0; u < 20; u++) {
								bo[i][u][id[x][y]] = shu[i];
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					}
				} else if (op == 1) {
					ll nx, ny;
					while (1) {
						ll VE = rd() % 4;
						nx = danx[sjid] + X[VE], ny = dany[sjid] + Y[VE];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
							break;
						}
					}
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] && nx != x && ny != y) {
						goto dop1bucheng;
					}
					swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
					swap(xt[x][y], xt[nx][ny]);
					swap(id[x][y], id[nx][ny]);
					swap(bl[x][y], bl[nx][ny]);
					scgz(x, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
					scgz(nx, ny, 16, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					swap(hp[x][y], hp[nx][ny]);
					for (ll i = max(0, nx - 7); i < min(30, nx + 7 + 1); i++) {
						for (ll u = max(0, ny - 7); u < min(20, ny + 7 + 1); u++) {
							if (xt[nx][ny] == 3) {
								bo[i][u][id[nx][ny]] = 2;
							} else {
								bo[i][u][id[nx][ny]] = 4 - ((abs(i - nx) + abs(u - ny) <= 2) << 1);
							}
							scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						}
					}
				} else if (op == 3) {
					for (ll i = 0; i < 30; i++) {
						for (ll u = 0; u < 20; u++) {
//								if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							bo[i][u][id[x][y]] = 3 - (xt[x][y] == 3);
//									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
//								}
						}
					}
					ll cnt = 30;
					while (cnt--) {
						while (1) {
							ll xx = rd() % 30, yy = rd() % 20;
							if (bo[xx][yy][id[x][y]] && !qk[sjid][qkidx[sjid]][qkidy[sjid]].a[xx][yy]) {
								bo[xx][yy][id[x][y]] = 0;
								break;
							}
						}
					}
					for (ll i = 0; i < 30; i++) {
						for (ll u = 0; u < 20; u++) {
							scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						}
					}
				} else if (op == 4) {
					if (dany[sjid] == 0) {
						killh[1][id[x][y]] = 1;
					} else if (dany[sjid] == 19) {
						killh[18][id[x][y]] = 1;
					} else {
						killh[dany[sjid]][id[x][y]] = 1;
					}
					ll cnt = 2;
					while (cnt) {
						while (1) {
							ll xx = rd() % 17 + 2;
							if (!killh[xx - 1][id[x][y]] && !killh[xx + 1][id[x][y]] && !killh[xx][id[x][y]] && !killh[xx - 2][id[x][y]]
							        && !killh[xx + 2][id[x][y]]) {
								killh[xx][id[x][y]] = 1;
								cnt--;
								break;
							}
						}
					}
					scqk();
				} else if (op == 5) {
					if (danx[sjid] == 0) {
						kills[1][id[x][y]] = 1;
					} else if (danx[sjid] == 29) {
						kills[28][id[x][y]] = 1;
					} else {
						kills[danx[sjid]][id[x][y]] = 1;
					}
					ll cnt = 3;
					while (cnt) {
						while (1) {
							ll xx = rd() % 27 + 2;
							if (!kills[xx - 1][id[x][y]] && !kills[xx + 1][id[x][y]] && !kills[xx][id[x][y]] && !kills[xx - 2][id[x][y]]
							        && !kills[xx + 2][id[x][y]]) {
								kills[xx][id[x][y]] = 1;
								cnt--;
								break;
							}
						}
					}
					scqk();
				} else if (op == 6) {
					bkills[danx[sjid]][id[x][y]] = bkillh[dany[sjid]][id[x][y]] = 1;
					ll cnt = 17;
					while (cnt--) {
						while (1) {
							ll xx = rd() % 30;
							if (!bkills[xx][id[x][y]]) {
								bkills[xx][id[x][y]] = 1;
								break;
							}
						}
					}
					cnt = 11;
					while (cnt--) {
						while (1) {
							ll xx = rd() % 20;
							if (!bkillh[xx][id[x][y]]) {
								bkillh[xx][id[x][y]] = 1;
								break;
							}
						}
					}
					scqk();
				}
				return;
			}
		}
	}
} dd[4][32][32];

void initd(ll x, unsigned long long lahp) {
//		fv[3][0][0].mcnt = tree[3][0][0].mcnt = stone[3][0][0].mcnt = mei[3][0][0].mcnt = Fe[3][0][0].mcnt = Au[3][0][0].mcnt =
//		        C[3][0][0].mcnt = f_xie[3][0][0].mcnt = 0;
	sjid = 3;
	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 14) {
				fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
			}
			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].op[i][u].clear();
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].do_jian[i][u] = 0;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u] = 0;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].id[i][u] = 0;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] = 0;
		}
	}
	if (caid) {
		qkidx[sjid] = qkidy[sjid] = 9;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[15][10] = 0;
		if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1])
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[15][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[8];
		else
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[15][10] = lahp;
		if (x == 1) {
			dd[sjid][qkidx[sjid]][qkidy[sjid]].id[15][10] = 1;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] = 1;
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 16;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].cxt = dd[sjid][qkidx[sjid]][qkidy[sjid]].mcxt[8];
			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 4;
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][15] = -1;
			danx[sjid] = 15, dany[sjid] = 15;
			ve = 0;
		}
//		if (x == 1) {
//			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 4;
//		} else if (x == 2) {
//			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[10][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[x];
//			dd[sjid][qkidx[sjid]][qkidy[sjid]].id[10][10] = 2;
//			dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2] = 1;
//			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[10][10] = 16;
//			dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[10][10] = 2;
//		}
		for (ll i = 0; i < 8; i++) {
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hdh(i);
		}
		scqk();
		return;
	}
	if (x == -1) {
		qkidx[sjid] = qkidy[sjid] = 10;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[15][10] = 0;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 16;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][15] = -1;
		danx[sjid] = 15, dany[sjid] = 15;
		ve = 0;
		return;
	}
	if (x == 8) {
		qkidx[sjid] = qkidy[sjid] = 8;
		bing[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 20;
		for (ll i = 0; i < 20; i++) {
			bing[sjid][qkidx[sjid]][qkidy[sjid]].scbing(0, i, i + 1);
		}
		danx[sjid] = 15, dany[sjid] = 15;
		ve = 1;
		scgz(15, 15, -1, 0);
		scgz(15 + X[ve], 15 + Y[ve], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15 + X[ve]][15 + Y[ve]], 1);
		return;
	}
	if (jzd) {
		qkidx[sjid] = qkidy[sjid] = 0;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[15][10] = x;
		if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1])
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[15][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[0];
		else
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[15][10] = lahp;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].id[15][10] = 1;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] = 1;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 16;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].cxt = dd[sjid][qkidx[sjid]][qkidy[sjid]].mcxt[x];
		fvvx[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 0;
		if (x == 1) {
			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 4;
		} else if (x == 2) {
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[10][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[x];
			dd[sjid][qkidx[sjid]][qkidy[sjid]].id[10][10] = 2;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2] = 1;
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[10][10] = 16;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[10][10] = 2;
		}
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][15] = -1;
		danx[sjid] = 15, dany[sjid] = 15;
		ve = 0;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].hdh(x);
		scqk();
		return;
	} else if (tzd) {
		qkidx[sjid] = qkidy[sjid] = x;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[15][10] = x;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[15][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[x];
		dd[sjid][qkidx[sjid]][qkidy[sjid]].id[15][10] = 1;
		dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] = 1;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 16;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][15] = -1;
		danx[sjid] = 15, dany[sjid] = 15;
		ve = 0;
		if (x == 1) {
			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].mcnt = 4;
		} else if (x == 2) {
			dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[10][10] = x;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[10][10] = dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[x];
			dd[sjid][qkidx[sjid]][qkidy[sjid]].id[10][10] = 2;
			dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2] = 2;
			qk[sjid][qkidx[sjid]][qkidy[sjid]].a[10][10] = 16;
		}
		dd[sjid][qkidx[sjid]][qkidy[sjid]].hdh(x);
		scqk();
		return;
	}
}

struct TREE {
	ll cnt, jian_ge, mcnt = 115; //区块树量 时间间隔 max量
	ll hp[32][22];//血量
	void sct() {// 生成 tree
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 1;
						hp[x][y] = 30;
						scgz(x, y, 1, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 30, 30);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} tree[4][32][32];

struct STONE {
	ll cnt, jian_ge, mcnt = 75; //区块石量 时间间隔 max量
	ll hp[32][22];//血量
	void scs() {// 生成 stone
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 2;
						hp[x][y] = 55;
						scgz(x, y, 2, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 55, 55);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} stone[4][32][32];

struct ZZT { // 制造台
	ll hp[32][22], maxhp = 30;
	void sczzt() {
		if (bag[1] >= 20) {
			if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]]) {
				bag[1] -= 20;
				if (yyzy[1] - bag[1] != 20) {
					pdzrecg;
				}
				yyzy[1] -= 20;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]] = 7;
				hp[danx[sjid] + X[ve]][dany[sjid] + Y[ve]] = maxhp;
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve], 7, 1);
				schp(danx[sjid] + X[ve], dany[sjid] + Y[ve], 1, 1);
			}
		}
	}

	void use_zzt() {
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 30; u++) {
				scgz(i, u, 0, 0);
			}
		}
		scgz(0, 0, 0, 1);
		string out = "剑：";
		if (Jian.xt == 0) {
			out += "260木头,200石头,30金币,3铁锭";
		} else if (Jian.xt == 1) {
			out += "460木头,390石头,50金币,5铁锭,3金锭,1钻石,5血块";
		} else if (Jian.xt == 2) {
			out += "1490木头,1290石头,100金币,35铁锭,23金锭,12钻石,10血块";
		} else if (Jian.xt == 3) {
			out += "3666木头,2666石头,200金币,70铁锭,40金锭,20钻石,30血块,2影子碎片";
		} else if (Jian.xt == 4) {
			out += "5000木头,4000石头,500金币,150铁锭,90金锭,114钻石,1145血块,25影子碎片,2FVV";
		} else if (Jian.xt == 5) {
			out += "10000木头,7000石头,1200金币,350铁锭,260金锭,164钻石,9527血块,50影子碎片,5FVV,2FX";
		} else if (Jian.xt == 6) {
			out += "20000木头,15000石头,2300金币,570铁锭,420金锭,700钻石,20000血块,80影子碎片,18FVV,4FX,2Pv";
		}
		xyprintf(37, 7, out.c_str());
		out = "刀：";
		if (dao.xt == 0) {
			out += "260木头,200石头,30金币,7铁锭";
		} else if (dao.xt == 1) {
			out += "460木头,390石头,50金币,15铁锭,6金锭,1钻石,5血块";
		} else if (dao.xt == 2) {
			out += "1490木头,1290石头,100金币,45铁锭,27金锭,12钻石,10血块";
		} else if (dao.xt == 3) {
			out += "3666木头,2666石头,200金币,89铁锭,66金锭,20钻石,30血块,2影子碎片";
		} else if (dao.xt == 4) {
			out += "5000木头,4000石头,500金币,190铁锭,120金锭,114钻石,1145血块,25影子碎片,2FVV";
		} else if (dao.xt == 5) {
			out += "10000木头,7000石头,1200金币,400铁锭,290金锭,164钻石,9527血块,50影子碎片,5FVV,2FX";
		} else if (dao.xt == 6) {
			out += "20000木头,15000石头,2300金币,640铁锭,490金锭,700钻石,20000血块,80影子碎片,18FVV,4FX,2Pv";
		}
		xyprintf(37, 1 * 30 + 7, out.c_str());
		out = "FVV刷怪蛋：100木头,100石头,100金币,100铁锭,100金锭,100钻石,2535血块,1影子碎片";
		xyprintf(37, 2 * 30 + 7, out.c_str());
		out = "FX刷怪蛋：100木头,100石头,100金币,100铁锭,100金锭,100钻石,25125血块,1影子碎片";
		xyprintf(37, 3 * 30 + 7, out.c_str());
		out = "Pv刷怪蛋：100木头,100石头,100金币,100铁锭,100金锭,100钻石,40100血块,1影子碎片";
		xyprintf(37, 4 * 30 + 7, out.c_str());
		out = "枪：";
		if (qiang.xt == 0) {
			out += "260木头,200石头,30金币,7铁锭";
		} else if (qiang.xt == 1) {
			out += "460木头,390石头,50金币,15铁锭,6金锭,1钻石,5血块";
		} else if (qiang.xt == 2) {
			out += "1490木头,1290石头,100金币,45铁锭,27金锭,12钻石,10血块";
		} else if (qiang.xt == 3) {
			out += "3666木头,2666石头,200金币,89铁锭,66金锭,20钻石,30血块,2影子碎片";
		} else if (qiang.xt == 4) {
			out += "5000木头,4000石头,500金币,190铁锭,120金锭,114钻石,1145血块,25影子碎片,2FVV";
		} else if (qiang.xt == 5) {
			out += "10000木头,7000石头,1200金币,400铁锭,290金锭,164钻石,9527血块,50影子碎片,5FVV,2FX";
		} else if (qiang.xt == 6) {
			out += "20000木头,15000石头,2300金币,640铁锭,490金锭,700钻石,20000血块,80影子碎片,18FVV,4FX,2Pv";
		}
		xyprintf(37, 5 * 30 + 7, out.c_str());
		out = "10子弹：4铁锭，1金锭";
		xyprintf(37, 6 * 30 + 7, out.c_str());
		ll xzid = 0;
		char dsth = getch();
		while (dsth) {
			if (dsth == 13) {
				if (xzid == 0) {
					Jian.shengji();
				} else if (xzid == 1) {
					dao.shengji();
				} else if (xzid == 2) {
					if (bag[1] < 100 || bag[2] < 100 || bag[3] < 100 || bag[11] < 100 || bag[12] < 100 || bag[10] < 100 || bag[5] < 2535
					        || bag[4] < 1) {
						break;
					}
					bag[1] -= 100;
					bag[2] -= 100;
					bag[3] -= 100;
					bag[11] -= 100;
					bag[12] -= 100;
					bag[10] -= 100;
					bag[5] -= 2535;
					bag[4] -= 1;
					bag[14]++;
					if (yyzy[1] - bag[1] != 100 || yyzy[2] - bag[2] != 100 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 100
					        || yyzy[12] - bag[12] != 100 || yyzy[10] - bag[10] != 100 || yyzy[5] - bag[5] != 2535 || yyzy[4] - bag[4] != 1
					        || bag[14] - yyzy[14] != 1) {
						pdzrecg;
					}
					yyzy[1] -= 100;
					yyzy[2] -= 100;
					yyzy[3] -= 100;
					yyzy[11] -= 100;
					yyzy[12] -= 100;
					yyzy[10] -= 100;
					yyzy[5] -= 2535;
					yyzy[4] -= 1;
					yyzy[14]++;
				} else if (xzid == 3) {
					if (bag[1] < 100 || bag[2] < 100 || bag[3] < 100 || bag[11] < 100 || bag[12] < 100 || bag[10] < 100 || bag[5] < 25125
					        || bag[4] < 1) {
						break;
					}
					bag[1] -= 100;
					bag[2] -= 100;
					bag[3] -= 100;
					bag[11] -= 100;
					bag[12] -= 100;
					bag[10] -= 100;
					bag[5] -= 25125;
					bag[4] -= 1;
					bag[15]++;
					if (yyzy[1] - bag[1] != 100 || yyzy[2] - bag[2] != 100 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 100
					        || yyzy[12] - bag[12] != 100 || yyzy[10] - bag[10] != 100 || yyzy[5] - bag[5] != 25125 || yyzy[4] - bag[4] != 1
					        || bag[15] - yyzy[15] != 1) {
						pdzrecg;
					}
					yyzy[1] -= 100;
					yyzy[2] -= 100;
					yyzy[3] -= 100;
					yyzy[11] -= 100;
					yyzy[12] -= 100;
					yyzy[10] -= 100;
					yyzy[5] -= 25125;
					yyzy[4] -= 1;
					yyzy[15]++;
				} else if (xzid == 4) {
					if (bag[1] < 100 || bag[2] < 100 || bag[3] < 100 || bag[11] < 100 || bag[12] < 100 || bag[10] < 100 || bag[5] < 40100
					        || bag[4] < 1) {
						break;
					}
					bag[1] -= 100;
					bag[2] -= 100;
					bag[3] -= 100;
					bag[11] -= 100;
					bag[12] -= 100;
					bag[10] -= 100;
					bag[5] -= 40100;
					bag[4] -= 1;
					bag[16]++;
					if (yyzy[1] - bag[1] != 100 || yyzy[2] - bag[2] != 100 || yyzy[3] - bag[3] != 100 || yyzy[11] - bag[11] != 100
					        || yyzy[12] - bag[12] != 100 || yyzy[10] - bag[10] != 100 || yyzy[5] - bag[5] != 40100 || yyzy[4] - bag[4] != 1
					        || bag[16] - yyzy[16] != 1) {
						pdzrecg;
					}
					yyzy[1] -= 100;
					yyzy[2] -= 100;
					yyzy[3] -= 100;
					yyzy[11] -= 100;
					yyzy[12] -= 100;
					yyzy[10] -= 100;
					yyzy[5] -= 40100;
					yyzy[4] -= 1;
					yyzy[16]++;
				} else if (xzid == 5) {
					qiang.shengji();
				} else if (xzid == 6) {
					if (bag[11] < 4 || bag[12] < 1) {
						break;
					}
					bag[11] -= 4;
					bag[12]--;
					bag[18] += 10;
					if (yyzy[11] - bag[11] != 4 || yyzy[12] - bag[12] != 1 || bag[18] - yyzy[18] != 10) {
						pdzrecg;
					}
					yyzy[11] -= 4;
					yyzy[12]--;
					yyzy[18] += 10;
				}
				for (ll i = 0; i < 10; i++) {
					scwp(i, (i == danwp));
				}
				break;
			} else {
				scgz(0, xzid, 0, 0);
				if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(6, xzid + 1);
				}
				scgz(0, xzid, 0, 1);
			}
			dsth = getch();
		}
		scqk();
	}
} zzt[4][32][32];

struct MEI { //煤
	ll hp[32][22], maxhp = 70, jian_ge, cnt, mcnt = 55;
	void scmei() {
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 8;
						hp[x][y] = maxhp;
						scgz(x, y, 8, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 30, 30);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} mei[4][32][32];

struct FE {
	ll hp[32][22], maxhp = 200, jian_ge, cnt, mcnt = 30;
	void scFe() {
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 9;
						hp[x][y] = maxhp;
						scgz(x, y, 9, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 30, 30);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} Fe[4][32][32];

struct AU {
	ll hp[32][22], maxhp = 300, jian_ge, cnt, mcnt = 18;
	void scAu() {
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 10;
						hp[x][y] = maxhp;
						scgz(x, y, 10, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 30, 30);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} Au[4][32][32];

struct C_zuan {
	ll hp[32][22], maxhp = 500, jian_ge, cnt, mcnt = 3;
	void scC() {
		if (cnt < mcnt) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 11;
						hp[x][y] = maxhp;
						scgz(x, y, 11, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 30, 30);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}
} C[4][32][32];

struct ronglu { //熔炉
	ll hp[32][22], maxhp = 55;
	void scrong() {
		if (bag[2] >= 40) {
			if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]]) {
				bag[2] -= 40;
				if (yyzy[2] - bag[2] != 40) {
					pdzrecg;
				}
				yyzy[2] = bag[2];
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]] = 12;
				hp[danx[sjid] + X[ve]][dany[sjid] + Y[ve]] = maxhp;
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve], 12, 1);
				schp(danx[sjid] + X[ve], dany[sjid] + Y[ve], 1, 1);
			}
		}
	}

	void use_rong() {
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 30; u++) {
				scgz(i, u, 0, 0);
			}
		}
		scgz(0, 0, 0, 1);
		xyprintf(37, 7, "铁锭：3Fe,10煤");
		xyprintf(37, 1 * 30 + 7, "金锭：3Au,10煤");
		xyprintf(37, 2 * 30 + 7, "9金币：1金锭");
		xyprintf(37, 3 * 30 + 7, "10铁锭：30Fe,100煤");
		xyprintf(37, 4 * 30 + 7, "10金锭：30Au,100煤");
		ll xzid = 0;
		char dsth = getch();
		while (dsth) {
			if (dsth == 13) {
				if (xzid == 0) {
					if (bag[8] >= 3 && bag[7] >= 10) {
						bag[8] -= 3;
						bag[7] -= 10;
						bag[11]++;
						if (yyzy[8] - bag[8] != 3 || yyzy[7] - bag[7] != 10 || bag[11] - yyzy[11] != 1) {
							pdzrecg;
						}
						yyzy[8] -= 3;
						yyzy[7] -= 10;
						yyzy[11]++;
					}
				} else if (xzid == 1) {
					if (bag[9] >= 3 && bag[7] >= 10) {
						bag[9] -= 3;
						bag[7] -= 10;
						bag[12]++;
						if (yyzy[9] - bag[9] != 3 || yyzy[7] - bag[7] != 10 || bag[12] - yyzy[12] != 1) {
							pdzrecg;
						}
						yyzy[12]++;
						yyzy[9] -= 3;
						yyzy[7] -= 10;
					}
				} else if (xzid == 2) {
					if (bag[12] >= 1) {
						bag[12]--;
						bag[3] += 9;
						if (yyzy[12] - bag[12] != 1 || bag[3] - yyzy[3] != 9) {
							pdzrecg;
						}
						yyzy[12]--;
						yyzy[3] += 9;
					}
				} else if (xzid == 3) {
					if (bag[8] >= 30 && bag[7] >= 100) {
						bag[8] -= 30;
						bag[7] -= 100;
						bag[11] += 10;
						if (yyzy[8] - bag[8] != 30 || yyzy[7] - bag[7] != 100 || bag[11] - yyzy[11] != 10) {
							pdzrecg;
						}
						yyzy[8] -= 30;
						yyzy[7] -= 100;
						yyzy[11] += 10;
					}
				} else if (xzid == 4) {
					if (bag[9] >= 30 && bag[7] >= 100) {
						bag[9] -= 30;
						bag[7] -= 100;
						bag[12] += 10;
						if (yyzy[9] - bag[9] != 30 || yyzy[7] - bag[7] != 100 || bag[12] - yyzy[12] != 10) {
							pdzrecg;
						}
						yyzy[12] += 10;
						yyzy[9] -= 30;
						yyzy[7] -= 100;
					}
				}
				break;
			} else {
				scgz(0, xzid, 0, 0);
				if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(4, xzid + 1);
				}
				scgz(0, xzid, 0, 1);
			}
			dsth = getch();
		}
		scqk();
	}
} rong[4][32][32];

ll bfs(ll x, ll y) {
	queue<pair<ll, ll> >q;
	ll dis[32][22];
	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			dis[i][u] = -1;
		}
	}
	dis[x][y] = 0;

	for (ll i = 0; i < 4; i++) {
		ll nx = x + X[i], ny = y + Y[i];
		if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
		        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1)) {
			dis[nx][ny] = i;
			q.push({nx, ny});
		}
	}

	if (dis[danx[sjid]][dany[sjid]] != -1) {
		return dis[danx[sjid]][dany[sjid]];
	}

	while (q.size()) {
		ll xx = q.front().first, yy = q.front().second;
		q.pop();
		for (ll i = 0; i < 4; i++) {
			ll nx = xx + X[i], ny = yy + Y[i];
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && dis[nx][ny] == -1 && (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]
			        || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1 || qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 3)) {
				dis[nx][ny] = dis[xx][yy];
				q.push({nx, ny});
			}
		}
		if (dis[danx[sjid]][dany[sjid]] != -1) {
			return dis[danx[sjid]][dany[sjid]];
		}
	}
	return -1;
}


struct FV { // 怪
	ll hp[32][22], maxhp[8] = {40, 900, 2300, 8999, 21234, 66666, 114151, 917813}, gong[8] = {4, 200, 500, 1145, 4800, 9999, 10415, 31415},
	                          cnt, jian_ge, do_jian[32][22], mcnt = 50,

	                                                         xt[32][22]; // 血 攻击 数量 间隔 do sth. 间隔 max量 形态
	void scg() {
		if (cnt < mcnt && (18 <= xiaoshi || xiaoshi <= 6)) {
			if (jian_ge == 0) {
				jian_ge = 0;
				cnt++;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						xt[x][y] = rd() % fvmod + fvmod / 10;
						xt[x][y] /= 1000;
//						xt[x][y] = 6;
						xt[x][y] = min(7, xt[x][y]);
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 3;
						hp[x][y] = maxhp[xt[x][y]];
						scgz(x, y, 3, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, maxhp[xt[x][y]], maxhp[xt[x][y]]);
						break;
					}
				}
			} else {
				jian_ge++;
			}
		}
	}

	void dosth(ll x, ll y) {
		if (do_jian[x][y] == 3) {
			do_jian[x][y] = 0;
			bool bol = 0;
			for (ll i = 0; i < 4; i++) {
				ll nx = x + X[i], ny = y + Y[i];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
					bol = 1;
					wj_jhp(gong[xt[x][y]], 3);
					break;
				}
			}
			if (!bol) {
				ll VE = bfs(x, y);
				if (VE == -1) {
					ll minn = abs(x - danx[sjid]) + abs(y - dany[sjid]);
					for (ll i = 0; i < 4; i++) {
						ll nx = x + X[i], ny = y + Y[i];
						if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && !qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]) {
							if (abs(nx - danx[sjid]) + abs(ny - dany[sjid]) < minn) {
								minn = abs(nx - danx[sjid]) + abs(ny - dany[sjid]);
								VE = i;
							}
						}
					}
					if (VE == -1) {
						return;
					}
				}
				ll nx = x + X[VE], ny = y + Y[VE];
				swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
				swap(xt[x][y], xt[nx][ny]);
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 3, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				swap(hp[x][y], hp[nx][ny]);
				schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
			}
		} else {
			do_jian[x][y]++;
		}
	}
} fv[4][32][32];


struct Fvv { //  FVV虚影
	ll hp[32][22], maxhp[4] = {50000, 2000000, 18000000}, gong[4] = {4500, 150000, 940000}, jian_ge, do_jian[32][22];
	bool bo;

	void scFvv(ll x, ll y) {
		if (!bo && (qkidx[sjid] || qkidy[sjid])) {
			if (jian_ge == 20) {
				jian_ge = 0;
				bo = 1;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 4;
				hp[x][y] = maxhp[sjid];
				scgz(x, y, 4, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				schp(x, y, hp[x][y], maxhp[sjid]);
//				scbhp(4, maxhp, maxhp);
			} else {
				jian_ge++;
			}
		}
	}

	void dosth(ll x, ll y) {
		if (do_jian[x][y] == 2) {
			do_jian[x][y] = 0;
			bool bol = 0;
			for (ll i = 0; i < 4; i++) {
				ll nx = x + X[i], ny = y + Y[i];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
					bol = 1;
					wj_jhp(gong[sjid], 4);
					break;
				}
			}
			if (!bol) {
				ll minn = abs(x - danx[sjid]) + abs(y - dany[sjid]), VE;
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
						if (abs(nx - danx[sjid]) + abs(ny - dany[sjid]) < minn) {
							minn = abs(nx - danx[sjid]) + abs(ny - dany[sjid]);
							VE = i;
						}
					}
				}
				ll nx = x + X[VE], ny = y + Y[VE];
				switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]) {
					case 1: {
						hp[x][y] = min(hp[x][y] + tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny] = 0;
						tree[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
//						scbhp(4, hp[x][y], maxhp);
						break;
					}
					case 2: {
						hp[x][y] = min(hp[x][y] + stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						stone[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
//						scbhp(4, hp[x][y], maxhp);
						break;
					}
					case 3: {
						hp[x][y] = min(hp[x][y] + fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
//						scbhp(4, hp[x][y], maxhp);
						break;
					}
					case 7: {
						hp[x][y] = min(hp[x][y] + zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						break;
					}
					case 8: {
						hp[x][y] = min(hp[x][y] + mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						mei[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 9: {
						hp[x][y] = min(hp[x][y] + Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						Fe[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 10: {
						hp[x][y] = min(hp[x][y] + Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						Au[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 11: {
						hp[x][y] = min(hp[x][y] + C[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						C[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 12: {
						hp[x][y] = min(hp[x][y] + rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[nx][ny], maxhp[sjid]);
						rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 0;
						break;
					}
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 4;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 4, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				swap(hp[x][y], hp[nx][ny]);
				schp(nx, ny, hp[nx][ny], maxhp[sjid]);
			}
		} else {
			do_jian[x][y]++;
		}
	}
} fvv[4][32][32];

struct F_xie {
	ll hp[32][22], maxhp = 20000, cnt = 0, jian_ge = 0, mcnt = 0;
	void scx() {
		if (cnt < mcnt) {
			jian_ge++;
			if (jian_ge == 1) {
				jian_ge = 0;
				while (1) {
					ll x = rd() % 30, y = rd() % 20;
					if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 5;
						hp[x][y] = maxhp;
						scgz(x, y, 5, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						schp(x, y, 1, 1);
						cnt++;
						break;
					}
				}
			}
		}
	}
} f_xie[4][32][32];

struct NFW {// 耐罚王
	ll hp[32][22], maxhp = 10000, gong = 7;
	ll do_jian[32][22], bo[32][22];
	bool bl;
	void init(ll x, ll y) {
		fv[0][x][y].mcnt = tree[0][x][y].mcnt = stone[0][x][y].mcnt = mei[0][x][y].mcnt = Fe[0][x][y].mcnt = Au[0][x][y].mcnt =
		        C[0][x][y].mcnt = 0;
		f_xie[0][x][y].mcnt = 0;
		bl = 0;
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
					case 18: {
						do_jian[i][u] = 0;
						break;
					}
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = min(0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]);
				bo[i][u] = 0;
				do_jian[i][u] = 0;
			}
		}
		hp[15][10] = maxhp;
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 18;
	}
	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if ((do_jian[x][y] == 6 && bl) || (do_jian[x][y] == 2 && !bl)) {
			do_jian[x][y] = 0;
			if (bl) {
				bl = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (!bo[i][u]) {
							continue;
						}
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == -1) {
							wj_jhp(maxHp >> gong, 18);
							bl = 1;
							switch (bo[i][u]) {
								case 2: { //控
									fchixt[0] += 7;
									break;
								}
								case 3: { //毒
									fchixt[1] += 8;
									break;
								}
								case 4: { //沉默
									fchixt[2] += 10;
									break;
								}
							}
						}
						bo[i][u] = 0;
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
					}
				}
				if (!bl) {
					hp[x][y] += (maxhp - hp[x][y] >> 2);
					scgzhp(x, y);
				}
				bl = 0;
				return;
			}
			bl = 1;
			ll cnt = hp[x][y] / 1000 + 1;
			cnt <<= 3;
			while (cnt--) {
				ll rx = rd() % 30, ry = rd() % 20;
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[rx][ry]) {
					cnt++;
					continue;
				}
				bo[rx][ry] = rd() % 4 + 1;
				scgz(rx, ry, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[rx][ry], (rx == danx[sjid] + X[ve] && ry == dany[sjid] + Y[ve]));
			}
		}
	}
} nfw[4][32][32];

struct FVV {// 世界0的BOSS
	ll hp[32][22], maxhp[8] = {0, 80000, 110000, 200000, 380000, 800000, 1300000, 2200000}, gong[8] = {0, 7000, 8000, 10000, 21000, 52000, 83000, 160000};
	ll xt[32][22], do_jian[32][22];
	bool bo[32][22], bl, slm = 0;

	void init(ll x) {
		fv[0][0][0].mcnt = tree[0][0][0].mcnt = stone[0][0][0].mcnt = mei[0][0][0].mcnt = Fe[0][0][0].mcnt = Au[0][0][0].mcnt =
		        C[0][0][0].mcnt = 0;
		f_xie[0][0][0].mcnt = 100;
		bl = 0;
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u   < 20; u++) {
				switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
					case 3: {
						fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 5: {
						f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 4: {
						fvv[sjid][qkidx[sjid]][qkidy[sjid]].bo = 0;
						break;
					}
					case 6: {
						do_jian[i][u] = 0;
						break;
					}
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = min(0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]);
				bo[i][u] = 0;
				do_jian[i][u] = 0;
			}
		}
		if (slm && !bag[14]) {
			return;
		}
		bag[14] -= slm;
		slm &= 0;
		xt[15][10] = x;
		hp[15][10] = maxhp[x];
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 6;
	}

	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if ((do_jian[x][y] == 6 && bl) || (do_jian[x][y] == 2 && !bl)) {
			do_jian[x][y] = 0;
			if (bl) {
				bl = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (!bo[i][u]) {
							continue;
						}
						bo[i][u] = 0;
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case 3: {
								hp[x][y] += min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case 5: {
								hp[x][y] += min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case -1: {
								wj_jhp(gong[xt[x][y]], 6);
								break;
							}
						}
						if (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve])
							scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], 1);
						else
							scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], 1, BLACK);
						scgzhp(i, u);
					}
					schp(x, y, hp[x][y], maxhp[xt[x][y]]);
					scbhp(6, hp[x][y], maxhp[xt[x][y]]);
				}
				return;
			}
			bool bol = 0;
			bool pan = (rd() % 4 <= 2);
			if (!pan)
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						hp[x][y] = min(hp[x][y] + min(gong[xt[x][y]] * 1LL, Hp), maxhp[xt[x][y]] * 1LL);
						bol = 1;
						scbhp(6, hp[x][y], maxhp[xt[x][y]]);
						wj_jhp(gong[xt[x][y]], 6);
						break;
					}
				}
			if (!bol) {
				ll VE = bfs(x, y);
				if (VE == -1 || pan) {
					bl = 1;
					ll op;
					if (hp[x][y] * 4 <= maxhp[xt[x][y]]) {
						op = 3;
					} else if (xt[x][y] <= 2) {
						op = 0;
					} else if (xt[x][y] <= 4) {
						op = rd() & 1;
					} else {
						op = rd() % 3;
					}
					if (op == 2) {
						ll cnt = xt[x][y] + 8;
						while (cnt--) {
							while (1) {
								ll sx = rd() % (31 - xt[x][y]), sy = rd() % (21 - xt[x][y]);
								for (ll i = sx; i <= sx + xt[x][y] - 1; i++) {
									for (ll u = sy; u <= sy + xt[x][y] - 1; u++) {
										bo[i][u] = 1;
										scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
									}
								}
								break;
							}
						}
					} else if (op == 0) {
fvvop1bucheng:
						ll cnt = xt[x][y] - 1;
						bool heng[22], shu[32];
						memset(heng, 0, sizeof heng);
						memset(shu, 0, sizeof shu);
						heng[dany[sjid]] = shu[danx[sjid]] = 1;
						while (cnt--) {
							while (1) {
								ll x = rd() % 30;
								if (!shu[x]) {
									shu[x] = 1;
									break;
								}
							}
							while (1) {
								ll y = rd() % 20;
								if (!heng[y]) {
									heng[y] = 1;
									break;
								}
							}
						}
						for (ll u = 0; u < 20; u++) {
							if (heng[u]) {
								for (ll i = 0; i < 30; i++) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							if (shu[i]) {
								for (ll u = 0; u < 20; u++) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					} else if (op == 1) {
						ll nx, ny;
						while (1) {
							VE = rd() % 4;
							nx = danx[sjid] + X[VE], ny = dany[sjid] + Y[VE];
							if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
								break;
							}
						}
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] && nx != x && ny != y) {
							goto fvvop1bucheng;
						}
						swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
						swap(xt[x][y], xt[nx][ny]);
						scgz(x, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						scgz(nx, ny, 6, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
						swap(hp[x][y], hp[nx][ny]);
						schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
						for (ll i = max(0, nx - xt[nx][ny]); i < min(30, nx + xt[nx][ny] + 1); i++) {
							for (ll u = max(0, ny - xt[nx][ny]); u < min(20, ny + xt[nx][ny] + 1); u++) {
								bo[i][u] = 1;
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					} else if (op == 3) {
						ll cnt = xt[x][y];
						while (cnt--) {
							while (1) {
								ll x = rd() % 30, y = rd() % 20;
								if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 5;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp;
									scgz(x, y, 5, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
									schp(x, y, 1, 1);
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt++;
									break;
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							for (ll u = 0; u < 20; u++) {
								if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					}
					return;
				}
				ll nx = x + X[VE], ny = y + Y[VE];
				swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
				swap(xt[x][y], xt[nx][ny]);
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 6, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				swap(hp[x][y], hp[nx][ny]);
				schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
			}
		}
	}
} F_fvv[4][32][32];


struct FX { // 世界1的BOSS
	ll hp[32][22], maxhp[8] = {0, 1150000, 2000000, 2600000, 4800000, 8000000, 12700000, 19000000}, gong[8] = {0, 150000, 180000, 200000, 250000, 450000, 580000, 650000};
	ll xt[32][22], do_jian[32][22];
	bool bo[32][22], bl, slm;

	void init(ll x) {
		fv[1][0][0].mcnt = tree[1][0][0].mcnt = stone[1][0][0].mcnt = mei[1][0][0].mcnt = Fe[1][0][0].mcnt = Au[1][0][0].mcnt =
		        C[1][0][0].mcnt = 0;
		f_xie[1][0][0].mcnt = 100;
		fvvx[1][0][0].mcnt = 2;
		bl = 0;
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
					case 3: {
						fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 5: {
						f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 4: {
						fvv[sjid][qkidx[sjid]][qkidy[sjid]].bo = 0;
						break;
					}
					case 13: {
						do_jian[i][u] = 0;
						break;
					}
					case 14: {
						fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bo[fvvx[sjid][qkidx[sjid]][qkidy[sjid]].id[i][u]] = 0;
						break;
					}
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = min(0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]);
				bo[i][u] = 0;
				do_jian[i][u] = 0;
				fvvx[sjid][qkidx[sjid]][qkidy[sjid]].op[i][u].clear();
			}
		}
		if (slm && !bag[15]) {
			return;
		}
		bag[15] -= slm;
		slm &= 0;
		xt[15][10] = x;
		hp[15][10] = maxhp[x];
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 13;
	}

	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if ((do_jian[x][y] == 6 && bl) || (do_jian[x][y] == 2 && !bl)) {
			do_jian[x][y] = 0;
			if (bl) {
				bl = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (!bo[i][u]) {
							continue;
						}
						bo[i][u] = 0;
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case 3: {
								hp[x][y] += min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case 5: {
								hp[x][y] += min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case -1: {
								wj_jhp(gong[xt[x][y]], 13);
								break;
							}
						}
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
					schp(x, y, hp[x][y], maxhp[xt[x][y]]);
					scbhp(13, hp[x][y], maxhp[xt[x][y]]);
				}
				return;
			}
			bool bol = 0;
			bool pan = (rd() % 4 <= 2);
			if (!pan)
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						hp[x][y] = min(hp[x][y] + min(gong[xt[x][y]] * 1LL, Hp), maxhp[xt[x][y]] * 1LL);
						bol = 1;
						scbhp(13, hp[x][y], maxhp[xt[x][y]]);
						wj_jhp(gong[xt[x][y]], 13);
						break;
					}
				}
			if (!bol) {
				ll VE = bfs(x, y);
				if (VE == -1 || pan) {
					for (ll i = max(0.0, danx[sjid] - log2(xt[x][y] + 1)); i < min(30.0, danx[sjid] + log2(xt[x][y] + 1) + 1); i++) {
						for (ll u = max(0.0, dany[sjid] - log2(xt[x][y] + 1)); u < min(20.0, dany[sjid] + log2(xt[x][y] + 1) + 1); u++) {
							if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
								qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 5;
								scgz(i, u, 5, (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] = f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp;
								schp(i, u, 1, 1);
								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt++;
							}
						}
					}
					bl = 1;
					ll op;
					if (hp[x][y] * 4 <= maxhp[xt[x][y]]) {
						op = 3;
					} else if (xt[x][y] <= 2) {
						op = 0;
					} else if (xt[x][y] <= 4) {
						op = rd() & 1;
					} else {
						op = rd() % 3;
					}
					if (op == 2) {
						ll cnt = xt[x][y] + 8;
						while (cnt--) {
							while (1) {
								ll sx = rd() % (31 - xt[x][y]), sy = rd() % (21 - xt[x][y]);
								for (ll i = sx; i <= sx + xt[x][y] - 1; i++) {
									for (ll u = sy; u <= sy + xt[x][y] - 1; u++) {
										bo[i][u] = 1;
										scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
									}
								}
								break;
							}
						}
					} else if (op == 0) {
fxop1bucheng:
						ll cnt = xt[x][y] - 1 + 2;
						bool heng[22], shu[32];
						memset(heng, 0, sizeof heng);
						memset(shu, 0, sizeof shu);
						heng[dany[sjid]] = shu[danx[sjid]] = 1;
						while (cnt--) {
							while (1) {
								ll x = rd() % 30;
								if (!shu[x]) {
									shu[x] = 1;
									break;
								}
							}
							while (1) {
								ll y = rd() % 20;
								if (!heng[y]) {
									heng[y] = 1;
									break;
								}
							}
						}
						for (ll u = 0; u < 20; u++) {
							if (heng[u]) {
								for (ll i = 0; i < 30; i++) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							if (shu[i]) {
								for (ll u = 0; u < 20; u++) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					} else if (op == 1) {
						ll nx, ny;
						while (1) {
							VE = rd() % 4;
							nx = danx[sjid] + X[VE], ny = dany[sjid] + Y[VE];
							if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
								break;
							}
						}
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] && nx != x && ny != y) {
							goto fxop1bucheng;
						}
						swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
						swap(xt[x][y], xt[nx][ny]);
						scgz(x, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						scgz(nx, ny, 13, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
						swap(hp[x][y], hp[nx][ny]);
						schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
						for (ll i = max(0, nx - xt[nx][ny]); i < min(30, nx + xt[nx][ny] + 1); i++) {
							for (ll u = max(0, ny - xt[nx][ny]); u < min(20, ny + xt[nx][ny] + 1); u++) {
								bo[i][u] = 1;
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					} else if (op == 3) {
						ll cnt = xt[x][y] + 16;
						while (cnt--) {
							while (1) {
								ll x = rd() % 30, y = rd() % 20;
								if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 5;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp;
									scgz(x, y, 5, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
									schp(x, y, 1, 1);
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt++;
									break;
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							for (ll u = 0; u < 20; u++) {
								if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
									bo[i][u] = 1;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					}
					return;
				}
				ll nx = x + X[VE], ny = y + Y[VE];
				swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
				swap(xt[x][y], xt[nx][ny]);
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 13, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				swap(hp[x][y], hp[nx][ny]);
				schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
			}
		}
	}
} fx[4][32][32];


struct PV { //世界2的BOSS
	ll hp[32][22], maxhp[8] = {0, 18000000, 27000000, 39000000, 77000000, 105000000, 201000000, 335000000}, gong[8] = {0, 640000, 910000, 1400000, 2900000, 4000000, 5200000, 6660000};
	ll xt[32][22], do_jian[32][22];
	short bo[32][22];
	bool bl, slm;

	void init(ll x) {
		fv[2][0][0].mcnt = tree[2][0][0].mcnt = stone[2][0][0].mcnt = mei[2][0][0].mcnt = Fe[2][0][0].mcnt = Au[2][0][0].mcnt =
		        C[2][0][0].mcnt = 0;
		f_xie[2][0][0].mcnt = 100;
		bl = 0;
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
					case 3: {
						fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 5: {
						f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
						break;
					}
					case 4: {
						fvv[sjid][qkidx[sjid]][qkidy[sjid]].bo = 0;
						break;
					}
					case 15: {
						do_jian[i][u] = 0;
						break;
					}
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = min(0, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]);
				bo[i][u] = 0;
				do_jian[i][u] = 0;
			}
		}
		if (slm && !bag[16]) {
			return;
		}
		bag[16] -= slm;
		slm &= 0;
		xt[15][10] = x;
		hp[15][10] = maxhp[x];
		qk[sjid][qkidx[sjid]][qkidy[sjid]].a[15][10] = 15;
	}

	void dosth(ll x, ll y) {
		do_jian[x][y]++;
		if ((do_jian[x][y] == 3 && bl) || (do_jian[x][y] == 2 && !bl)) {
			do_jian[x][y] = 0;
			if (bl) {
				bl = 0;
				for (ll i = 0; i < 30; i++) {
					for (ll u = 0; u < 20; u++) {
						if (!bo[i][u]) {
							continue;
						}
						switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
							case 3: {
								hp[x][y] += min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case 5: {
								hp[x][y] += min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) * 3;
								hp[x][y] = min(hp[x][y], maxhp[xt[x][y]]);
								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] -= min(gong[xt[x][y]], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]);
								if (!f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
								}
								break;
							}
							case -1: {
								if (bo[i][u] == 2) {
									fchixt[0] += xt[x][y];
								}
								wj_jhp(gong[xt[x][y]], 15);
								break;
							}
						}
						bo[i][u] = 0;
						scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
						scgzhp(i, u);
					}
					schp(x, y, hp[x][y], maxhp[xt[x][y]]);
					scbhp(15, hp[x][y], maxhp[xt[x][y]]);
				}
				return;
			}
			bool bol = 0;
			bool pan = (rd() % 4 <= 2);
			if (!pan)
				for (ll i = 0; i < 4; i++) {
					ll nx = x + X[i], ny = y + Y[i];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20 && qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == -1) {
						hp[x][y] = min(hp[x][y] + min(gong[xt[x][y]] * 1LL, Hp), maxhp[xt[x][y]] * 1LL);
						bol = 1;
						scbhp(15, hp[x][y], maxhp[xt[x][y]]);
						wj_jhp(gong[xt[x][y]], 15);
						break;
					}
				}
			if (!bol) {
				ll VE = bfs(x, y);
				if (VE == -1 || pan) {
//					for (ll i = max(0.0, danx[sjid] - log2(xt[x][y] + 1)); i < min(30.0, danx[sjid] + log2(xt[x][y] + 1) + 1); i++) {
//						for (ll u = max(0.0, dany[sjid] - log2(xt[x][y] + 1)); u < min(20.0, dany[sjid] + log2(xt[x][y] + 1) + 1); u++) {
//							if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
//								qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 5;
//								scgz(i, u, 5, (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
//								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] = f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp;
//								schp(i, u, 1, 1);
//								f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt++;
//							}
//						}
//					}
					bl = 1;
					ll op;
					if (hp[x][y] * 4 <= maxhp[xt[x][y]]) {
						op = 3;
					} else if (xt[x][y] <= 2) {
						op = 0;
					} else if (xt[x][y] <= 4) {
						op = rd() & 1;
					} else {
						op = rd() % 3;
					}
					if (op == 2) {
						bool boshu = (rd() & 1), boheng = (rd() & 1);
						for (ll i = boheng; i < 29 + boheng; i++) {
							for (ll u = boshu; u < 19 + boshu; u++) {
								bo[i][u] = 2;
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					} else if (op == 0) {
pvop1bucheng:
						ll cnt = xt[x][y] - 1 + 2;
						short heng[22], shu[32];
						memset(heng, 0, sizeof heng);
						memset(shu, 0, sizeof shu);
						heng[dany[sjid]] = shu[danx[sjid]] = 2;
						while (cnt--) {
							while (1) {
								ll num = rd() % 30;
								if (!shu[num]) {
									shu[num] = (rd() % 7 < xt[x][y]) + 1;
									break;
								}
							}
							while (1) {
								ll num = rd() % 20;
								if (!heng[num]) {
									heng[num] = (rd() % 7 < xt[x][y]) + 1;
									break;
								}
							}
						}
						for (ll u = 0; u < 20; u++) {
							if (heng[u]) {
								for (ll i = 0; i < 30; i++) {
									bo[i][u] = heng[u];
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							if (shu[i]) {
								for (ll u = 0; u < 20; u++) {
									bo[i][u] = shu[i];
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					} else if (op == 1) {
						ll nx, ny;
						while (1) {
							VE = rd() % 4;
							nx = danx[sjid] + X[VE], ny = dany[sjid] + Y[VE];
							if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
								break;
							}
						}
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] && nx != x && ny != y) {
							goto pvop1bucheng;
						}
						swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
						swap(xt[x][y], xt[nx][ny]);
						scgz(x, y, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
						scgz(nx, ny, 15, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
						swap(hp[x][y], hp[nx][ny]);
						schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
						for (ll i = max(0, nx - xt[nx][ny]); i < min(30, nx + xt[nx][ny] + 1); i++) {
							for (ll u = max(0, ny - xt[nx][ny]); u < min(20, ny + xt[nx][ny] + 1); u++) {
								bo[i][u] = 1 + (abs(i - nx) + abs(u - ny) <= 2);
								scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
							}
						}
					} else if (op == 3) {
						ll cnt = xt[x][y] + 31;
						while (cnt--) {
							while (1) {
								ll x = rd() % 30, y = rd() % 20;
								if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
									qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 5;
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp;
									scgz(x, y, 5, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
									schp(x, y, 1, 1);
									f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt++;
									break;
								}
							}
						}
						for (ll i = 0; i < 30; i++) {
							for (ll u = 0; u < 20; u++) {
								if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u]) {
									bo[i][u] = 2;
									scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (i == danx[sjid] + X[ve] && u == dany[sjid] + Y[ve]));
								}
							}
						}
					}
					return;
				}
				ll nx = x + X[VE], ny = y + Y[VE];
				swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y], qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny]);
				swap(xt[x][y], xt[nx][ny]);
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				scgz(nx, ny, 15, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
				swap(hp[x][y], hp[nx][ny]);
				schp(nx, ny, hp[nx][ny], maxhp[xt[nx][ny]]);
			}
		}
	}
} pv[4][32][32];

void scbhp(ll x, unsigned long long hp, unsigned long long maxhp, color_t danys) {
	string str = to_string(hp) + "/" + to_string(maxhp);
//	if (x == 4) {
//		str = "FVV的虚影 " + str;
//	}
	if (x == 6) {
		str = "FVV " + str;
	} else if (x == 13) {
		str = "FX " + str;
	} else if (x == 15) {
		str = "Pv " + str;
	} else if (x == 16) {
		if (caid) {
			str = "帝！！！ " + str;
		} else {
			str = "帝 " + str;
		}
	} else if (x == 18) {
		str = "耐罚王 " + str;
	}
	setcolor(danys);
	for (ll i = 0; i < 900; i++) {
		for (ll u = 600; u < 630; u++) {
			putpixel(i, u, BLACK);
		}
	}
//	str += "                                 ";
	xyprintf(7, 607, str.c_str());
	ll ox = ceil(900.0L * hp / maxhp);
	for (ll i = 0; i < 900; i++) {
		for (ll u = 630; u < 660; u++) {
			if (i == 0 || i == 899 || u == 630 || u == 659) {
				putpixel(i, u, WHITE);
			} else if (i <= ox) {
				putpixel(i, u, RED);
			} else {
				putpixel(i, u, BLACK);
			}
		}
	}
}

void scgz(ll x, ll y, ll num, bool biank, color_t danys) { //生成格子
	if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
		return;
	}
	for (ll did = 1; did <= 2; did++) {
		if (dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[did]) {
			for (ll i = max(0, x - 1); i <= min(29, x + 1); i++) {
				if (dd[sjid][qkidx[sjid]][qkidy[sjid]].kills[i][did]) {
					return;
				}
			}
			for (ll i = max(0, y - 1); i <= min(19, y + 1); i++) {
				if (dd[sjid][qkidx[sjid]][qkidy[sjid]].killh[i][did]) {
					return;
				}
			}
			if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkills[x][did]) {
				return;
			}
			if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkillh[y][did]) {
				return;
			}
		}
	}
	if (!biank) {
		if (dd[sjid][qkidx[sjid]][qkidy[sjid]].kills[x][1] || dd[sjid][qkidx[sjid]][qkidy[sjid]].killh[y][1]
		        || dd[sjid][qkidx[sjid]][qkidy[sjid]].kills[x][2] || dd[sjid][qkidx[sjid]][qkidy[sjid]].killh[y][2]) {
			danys = ys[2];
			biank = 1;
		} else if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkills[x][1] || dd[sjid][qkidx[sjid]][qkidy[sjid]].bkillh[y][1]
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bkills[x][2] || dd[sjid][qkidx[sjid]][qkidy[sjid]].bkillh[y][2]) {
			danys = ys[7];
			biank = 1;
		} else if (bian.bo[x][y]) {
			danys = ys[0];
			biank = 1;
		} else if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][1] == 3 || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][2] == 3
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][3] == 3  || nfw[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] == 3) {
			danys = ys[4];
			biank = 1;
		} else if (pv[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] == 2 || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][1] == 2
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][2] == 2 || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][3] == 2
		           || nfw[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] == 2) {
			danys = ys[3];
			biank = 1;
		} else if (F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] || fx[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y]
		           || fvvx[sjid][qkidx[sjid]][qkidy[sjid]].op[x][y].size() || bing[sjid][qkidx[sjid]][qkidy[sjid]].op[x][y].size()
		           || pv[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][1] == 1
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][2] == 1 || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][3] == 1
		           || nfw[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] == 1) {
			danys = RED;
			biank = 1;
		} else if (nfw[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y] == 4 || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][1] == 4
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][2] == 4
		           || dd[sjid][qkidx[sjid]][qkidy[sjid]].bo[x][y][3] == 4) {
			danys = ys[5];
			biank = 1;
		}
	}
	ll sx = x * 30, sy = y * 30, ox = sx + 30, oy = sy + 30;
	for (ll i = sx; i < ox; i++) {
		for (ll u = sy; u < oy; u++) {
			putpixel(i, u, EGERGB(0, 0, 0));
			if (biank) {
				if (i == sx || i == ox - 1 || u == sy || u == oy - 1) {
//					if (abs(i - u - sx - sy) <= 5 || (abs(i - u - sx - sy)) >= 25) {
					putpixel(i, u, danys);
//					}
				}
			}
		}
	}

	if (num == 1) {
		setcolor(GREEN);
		xyprintf(sx + 7, sy + 7, "树");

	} else if (num == 2) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "石");

	} else if (num == -1) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "你");

	} else if (num == 3) {
		setcolor(ys[fv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
		xyprintf(sx + 7, sy + 7, "怪");

	} else if (num == 4) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "帝");

	} else if (num == 5) {
		setcolor(RED);
		xyprintf(sx + 7, sy + 7, "血");

	} else if (num == 6) {
		setcolor(ys[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
		xyprintf(sx + 3, sy + 5, "FVV");

	} else if (num == 7) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "制");

	} else if (num == 8) {
		setcolor(ys[7]);
		xyprintf(sx + 7, sy + 7, "煤");

	} else if (num == 9) {
		setcolor(ys[0]);
		xyprintf(sx + 7, sy + 7, "Fe");

	} else if (num == 10) {
		setcolor(ys[3]);
		xyprintf(sx + 7, sy + 7, "Au");

	} else if (num == 11) {
		setcolor(ys[5]);
		xyprintf(sx + 10, sy + 7, "C");

	} else if (num == 12) {
		setcolor(ys[0]);
		xyprintf(sx + 7, sy + 7, "熔");

	} else if (num == 13) {
		setcolor(ys[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
		xyprintf(sx + 7, sy + 7, "FX");

	} else if (num == 14) {
		setcolor(ys[0]);
		xyprintf(sx + 10, sy + 7, "X");

	} else if (num == 15) {
		setcolor(ys[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
		xyprintf(sx + 7, sy + 7, "Pv");

	} else if (num == 16) {
		setcolor(ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
		xyprintf(sx + 7, sy + 7, "帝");

	} else if (num == 17) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "兵");
	} else if (num == 18) {
		setcolor(WHITE);
		xyprintf(sx + 7, sy + 7, "王");
	}
}

void scgzhp(ll x, ll y) {
	switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
		case -1: {
			schp(x, y, Hp, maxHp);
			break;
		}
		case 1: {
			schp(x, y, tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], 30);
			break;
		}
		case 2: {
			schp(x, y, stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], 55);
			break;
		}
		case 3: {
			schp(x, y, fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     fv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[fv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 4: {
			schp(x, y, fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[sjid]);
//			scbhp(4, fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 5: {
			schp(x, y, f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 6: {
			schp(x, y, F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			scbhp(6, F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 7: {
			schp(x, y, zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], zzt[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 8: {
			schp(x, y, mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], mei[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 9: {
			schp(x, y, Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], Fe[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 10: {
			schp(x, y, Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], Au[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 11: {
			schp(x, y, C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], C[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 12: {
			schp(x, y, rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], rong[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 13: {
			schp(x, y, fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     fx[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			scbhp(13, fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      fx[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 15: {
			schp(x, y, pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     pv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			scbhp(15, pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      pv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 16: {
//			schp(x, y, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
//			     dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      dd[sjid][qkidx[sjid]][qkidy[sjid]].dmaxhp(x, y), ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 17: {
			schp(x, y, bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], bing[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
		case 18: {
			schp(x, y, nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     nfw[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			scbhp(18, nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      nfw[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			break;
		}
	}
}

void scqk() { //生成区块
	if (qkidx[sjid] == qkidy[sjid] && !qkidx[sjid]) {
		if (sjid == 0) {
			F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].init(1);
		} else if (sjid == 1) {
			fx[sjid][qkidx[sjid]][qkidy[sjid]].init(1);
		} else if (sjid == 2) {
			pv[sjid][qkidx[sjid]][qkidy[sjid]].init(1);
		}
	} else if (sjid == 3 && !tzd && !jzd && !caid) {
		initd(-1);
	} else if (sjid == 0 && qkidx[sjid] == 2 && qkidy[sjid] == 2) {
		nfw[sjid][qkidx[sjid]][qkidy[sjid]].init(2, 2);
	}
	bool bo = 0;
	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			scgz(i, u, qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u], (danx[sjid] + X[ve] == i && u == dany[sjid] + Y[ve]));
			scgzhp(i, u);
			if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 6) {
				scbhp(6, F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u],
				      F_fvv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidx[sjid]].xt[i][u]]);
				bo = 1;
			} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 13) {
				scbhp(13, fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u],
				      fx[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidx[sjid]].xt[i][u]]);
				bo = 1;
			} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 15) {
				scbhp(15, pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u],
				      pv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidx[sjid]].xt[i][u]]);
				bo = 1;
			} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 16) {
				scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u],
				      dd[sjid][qkidx[sjid]][qkidx[sjid]].dmaxhp(i, u), ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u]]);
				bo = 1;
			}
		}
	}

	if (!bo) {
		if (sjid == 0)
			scbhp(6, 0, F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[1]);
		else if (sjid == 1)
			scbhp(13, 0, fx[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[1]);
		else if (sjid == 2)
			scbhp(15, 0, pv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[1]);
		else if (sjid == 3)
			scbhp(16, 0, dd[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[0]);
	}
}

struct F {
	ll a[3][3];
	F() {
		memset(a, 0, sizeof a);
	}
	F operator*(const F &X) const {
		F res;
		for (ll i = 0; i < 2; i++) {
			for (ll u = 0; u < 2; u++) {
				for (ll k = 0; k < 2; k++) {
					res.a[i][u] += a[i][k] * X.a[k][u];
					res.a[i][u] %= 1000;
				}
			}
		}
		return res;
	}
	F operator^(long long X) const {
		F res, base;
		for (ll i = 0; i < 2; i++) {
			res.a[i][i] = 1;
		}
		for (ll i = 0; i < 2; i++) {
			for (ll u = 0; u < 2; u++) {
				base.a[i][u] = a[i][u];
			}
		}
		while (X) {
			if (X & 1) {
				res = res * base;
			}
			base = base * base;
			X >>= 1;
		}
		return res;
	}
} A;

void beigong(ll x, ll y, long long zs) {
	wqjia(wpl[danwp], 1);
	w(Gong), w("\n");
	switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
		case 1: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 1, 1);
			tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], 30);
			if (!tree[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[1] += rd() % 5 + 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 40;
				yyjy += Trjy;
				if (bag[1] - yyzy[1] > 5 + (wpl[danwp] == 2 && ji_nid == 2)) {
					pdzrecg;
				}
				yyzy[1] = bag[1];
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				tree[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 2: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 2, 1);
			stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], 55);
			if (!stone[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[2] += rd() % 3 + 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 40;
				yyjy += Stjy;
				if (bag[2] - yyzy[2] > 3 + (wpl[danwp] == 2 && ji_nid == 2)) {
					pdzrecg;
				}
				yyzy[2] = bag[2];
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				stone[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 3: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 3, 1);
			fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     fv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[fv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			if (!fv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[3] += rd() % 3 + 1 + (wpl[danwp] == 2 && ji_nid == 2);
				if (bag[3] - yyzy[3] > 3 + (wpl[danwp] == 2 && ji_nid == 2)) {
					pdzrecg;
				}
				yyzy[3] = bag[3];
				switch (fv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]) {
					case 0: {
						bag[0] += 40;
						yyjy += Gwjy;
						break;
					}
					case 1: {
						bag[0] += 150;
						yyjy += Gwjy1;
						break;
					}
					case 2: {
						bag[0] += 400;
						yyjy += Gwjy2;
						break;
					}
					case 3: {
						bag[0] += 1200;
						yyjy += Gwjy3;
						break;
					}
					case 4: {
						bag[0] += 4900;
						yyjy += Gwjy4;
						break;
					}
					case 5: {
						bag[0] += 6800;
						yyjy += Gwjy5;
						break;
					}
					case 6: {
						bag[0] += 10000;
						yyjy += Gwjy6;
						break;
					}
					case 7: {
						bag[0] += 56000;
						yyjy += Gwjy7;
						break;
					}
				}
//						bag[0] += 550;
//						yyjy+=550;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				fv[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				fvv[sjid][qkidx[sjid]][qkidy[sjid]].scFvv(x, y);
			}
			break;
		}
		case 4: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 4, 1);
			fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     fvv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[sjid]);
			if (!fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[4] += 1;
				if (bag[4] - yyzy[4] != 1) {
					pdzrecg;
				}
				yyzy[4]++;
				bag[0] += 90000;
				yyjy += Fvvjy;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				fvv[sjid][qkidx[sjid]][qkidy[sjid]].bo = 0;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
//					scbhp(4, fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
//					      fvv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp);
			break;
		}
		case 5: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 5, 1);
			f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     f_xie[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!f_xie[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[5] += 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 1000;
				yyjy += 1000;
				if (bag[5] - yyzy[5] != 1 + (wpl[danwp] == 2 && ji_nid == 2)) {
					pdzrecg;
				}
				yyzy[5] = bag[5];
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				f_xie[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 6: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 6, 1);
			F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     F_fvv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			if (!F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				if (F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].bl) {
					F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
					break;
				}
				if (F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] == 7) {
					bag[0] += 9999000;
					yyjy += 9999000;
					bag[6] += 1;
					F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].slm = 1;
					if (bag[6] - yyzy[6] != 1) {
						pdzrecg;
					}
					yyzy[6]++;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				} else {
					F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]++;
					F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] =
					    F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]];
					scgz(x, y, 6, 1);
					schp(x, y, 1, 1);
				}
			}
			scbhp(6, F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      F_fvv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 7: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 7, 1);
			zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     zzt[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!zzt[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[1] += 20;
				if (bag[1] - yyzy[1] != 20) {
					pdzrecg;
				}
				yyzy[1] += 20;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 8: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 8, 1);
			mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     mei[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!mei[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[7] += rd() % 3 + 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 60;
				bag[2]++;
				yyjy += Mejy;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				mei[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				if (bag[7] - yyzy[7] > 3 + (wpl[danwp] == 2 && ji_nid == 2) || bag[2] - yyzy[2] != 1) {
					pdzrecg;
				}
				yyzy[7] = bag[7];
				yyzy[2]++;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 9: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 9, 1);
			Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     Fe[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!Fe[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[8] += 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 60;
				bag[2]++;
				if (bag[8] - yyzy[8] != 1 + (wpl[danwp] == 2 && ji_nid == 2) || bag[2] - yyzy[2] != 1) {
					pdzrecg;
				}
				yyzy[8] = bag[8];
				yyzy[2]++;
				yyjy += Fejy;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				Fe[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 10: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 10, 1);
			Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     Au[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!Au[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[9] += 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 60;
				bag[2]++;
				yyjy += Aujy;
				if (bag[9] - yyzy[9] != 1 + (wpl[danwp] == 2 && ji_nid == 2) || bag[2] - yyzy[2] != 1) {
					pdzrecg;
				}
				yyzy[9] = bag[9];
				yyzy[2]++;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				Au[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 11: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 11, 1);
			C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y], C[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!C[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[10] += 1 + (wpl[danwp] == 2 && ji_nid == 2);
				bag[0] += 80;
				bag[2]++;
				yyjy += Czjy;
				if (bag[10] - yyzy[10] != 1 + (wpl[danwp] == 2 && ji_nid == 2) || bag[2] - yyzy[2] != 1) {
					pdzrecg;
				}
				yyzy[10] = bag[10];
				yyzy[2]++;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				C[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 12: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 12, 1);
			rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     rong[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!rong[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				bag[2] += 40;
				if (bag[2] - yyzy[2] != 40) {
					pdzrecg;
				}
				yyzy[2] += 40;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
			}
			break;
		}
		case 13: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 13, 1);
			fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     fx[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			if (!fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				if (fx[sjid][qkidx[sjid]][qkidy[sjid]].bl) {
					fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
					break;
				}
				if (fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] == 7) {
					bag[0] += 9999900000LL;
					yyjy += 9999900000LL;
					bag[13] += 1;
					fx[sjid][qkidx[sjid]][qkidy[sjid]].slm = 1;
					if (bag[13] - yyzy[13] != 1) {
						pdzrecg;
					}
					yyzy[13]++;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				} else {
					fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]++;
					fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] =
					    fx[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]];
					scgz(x, y, 13, 1);
					schp(x, y, 1, 1);
				}
			}
			scbhp(13, fx[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      fx[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[fx[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 15: {
			wqxi(wpl[danwp]);
			scgz(danx[sjid], dany[sjid], -1, 0);
			schp(danx[sjid], dany[sjid], Hp, maxHp);
			scgz(x, y, 15, 1);
			pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
			schp(x, y,
			     pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			     pv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			if (!pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				if (pv[sjid][qkidx[sjid]][qkidy[sjid]].bl) {
					pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
					break;
				}
				if (pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] == 7) {
					bag[0] += 9999999999999LL;
					yyjy += 9999999999999LL;
					bag[17] += 1;
					pv[sjid][qkidx[sjid]][qkidy[sjid]].slm = 1;
					if (bag[17] - yyzy[17] != 1) {
						pdzrecg;
					}
					yyzy[17]++;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				} else {
					pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]++;
					pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] =
					    pv[sjid][qkidx[sjid]][qkidy[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]];
					scgz(x, y, 15, 1);
					schp(x, y, 1, 1);
				}
			}
			scbhp(15, pv[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
			      pv[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[pv[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			break;
		}
		case 17: {
			scgz(x, y, 17, 1);
			bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(Gong + zs,
			        bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] * 1LL);
//			schp(x, y,
//			     bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
//			     bing[sjid][qkidx[sjid]][qkidy[sjid]].maxhp);
			if (!bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
				if (bing[sjid][qkidx[sjid]][qkidy[sjid]].bl[x][y]) {
					bing[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
					break;
				}
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
				bing[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
				scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
				if (!bing[sjid][qkidx[sjid]][qkidy[sjid]].cnt) {
					initd(0);
				}
			}
			break;
		}
		case 16: {
			if (!jzd && !tzd && !caid) {
				if (__builtin_popcount(ptzdw) == 7) {
					for (ll i = 0; i < 30; i++) {
						for (ll u = 0; u < 20; u++) {
							scgz(i, u, 0, 0);
						}
					}
					xyprintf(7, 7, "帝：你想跟我决战？");
					getch();
					jzd = 1;
					for (ll i = 0; i < 30; i++) {
						for (ll u = 0; u < 20; u++) {
							scgz(i, u, 0, 0);
						}
					}
					initd(8);
				} else {
					for (ll i = 0; i < 30; i++) {
						for (ll u = 0; u < 20; u++) {
							scgz(i, u, 0, 0);
						}
					}
					xyprintf(7, 7, "帝：你想挑战我？");
					getch();
					dd[sjid][qkidx[sjid]][qkidy[sjid]].hdosth(2);
				}
			} else if (tzd) {
				wqxi(wpl[danwp]);
				scgz(danx[sjid], dany[sjid], -1, 0);
				schp(danx[sjid], dany[sjid], Hp, maxHp);
				scgz(x, y, 16, 1);
				long long gong = 0;
				if (dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] == 6) {
					A.a[0][0] = 8, A.a[0][1] = 999, A.a[1][0] = 1, A.a[1][1] = 0;
					A = A ^ (Gong - 1);
					gong = 8 * A.a[0][0] + 2 * A.a[0][1];
					gong = (gong - 1 + 1000) % 1000;
				} else {
					gong = Gong;
				}
				dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(gong * 1uLL + zs,
				        dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]);
				if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
					if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bl[x][y]) {
						dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
						break;
					}
					dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[dd[sjid][qkidx[sjid]][qkidy[sjid]].id[x][y]] = 0;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
					if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] && !dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2]) {
						tzd = 0;
						ptzdw |= (1 << (dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] - 1));
						initd(-1);
						bian.shengji();
						scqk();
					}
				}
				scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
				      dd[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]],
				      ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			} else if (jzd) {
				wqxi(wpl[danwp]);
				scgz(danx[sjid], dany[sjid], -1, 0);
				schp(danx[sjid], dany[sjid], Hp, maxHp);
				scgz(x, y, 16, 1);
				long long gong = 0;
				if (dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y] == 6) {
					A.a[0][0] = 8, A.a[0][1] = 999, A.a[1][0] = 1, A.a[1][1] = 0;
					A = A ^ (Gong - 1);
					gong = 8 * A.a[0][0] + 2 * A.a[0][1];
					gong = (gong - 1 + 1000) % 1000;
				} else {
					gong = Gong;
				}
				dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(gong * 1uLL + zs,
				        dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]);
				if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
					if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bl[x][y]) {
						dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
						break;
					}
					dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[dd[sjid][qkidx[sjid]][qkidy[sjid]].id[x][y]] = 0;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
					if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] && !dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2]) {
						jzd = 0;
						scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
						      dd[sjid][qkidx[sjid]][qkidy[sjid]].dmaxhp(x, y), ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
						caid = 1;
//						ptzdw|=(1<<(dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]-1));
						initd(1);
						scqk();
					}
				}
				scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
				      dd[sjid][qkidx[sjid]][qkidy[sjid]].dmaxhp(x, y), ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			} else if (caid) {
				wqxi(wpl[danwp]);
				scgz(danx[sjid], dany[sjid], -1, 0);
				schp(danx[sjid], dany[sjid], Hp, maxHp);
				scgz(x, y, 16, 1);
				long long gong = 0;
				A.a[0][0] = 8, A.a[0][1] = 999, A.a[1][0] = 1, A.a[1][1] = 0;
				A = A ^ (Gong - 1);
				gong = 8 * A.a[0][0] + 2 * A.a[0][1];
				gong = (gong - 1 + 1000) % 1000;
				dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] -= min(gong * 1uLL + zs,
				        dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]);
				if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y]) {
					if (dd[sjid][qkidx[sjid]][qkidy[sjid]].bl[x][y]) {
						dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y] = 1;
						break;
					}
					dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[dd[sjid][qkidx[sjid]][qkidy[sjid]].id[x][y]] = 0;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y] = 0;
					scgz(x, y, 0, (x == danx[sjid] + X[ve]) && (y == dany[sjid] + Y[ve]));
					if (!dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[1] && !dd[sjid][qkidx[sjid]][qkidy[sjid]].idbo[2]) {
						caid = 0;
//						ptzdw|=(1<<(dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]-1));
						initd(-1);
						scqk();
					}
				}
				scbhp(16, dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[x][y],
				      dd[sjid][qkidx[sjid]][qkidx[sjid]].maxhp[8], ys[dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[x][y]]);
			}
			break;
		}
	}
	while (bag[0] >= (dengji + 1) * (dengji + 1)) {
		bag[0] -= (dengji + 1) * (dengji + 1);
		dengji++;
		tfd++;
		maxHp += (dengji << 2);
		Hp += (dengji << 2);
		Gong += (dengji + 1 >> 1);
	}
//			pjyj(dengji,bag[0]);
	wqjia(wpl[danwp], -1);
//	w(Gong), w("\n");
	pbz(bag);
}
map<string,long long>Sll;
bool usezl[1006];
long long getzlnum(string zzl,ll i){
	string blm;
	for (;i<zzl.size() && usezl[i];){
		i++;
	}
	if (isdigit(zzl[i])){
		long long zlnum=0;
		while(isdigit(zzl[i])){
			zlnum=(zlnum<<1)+(zlnum<<3)+(zzl[i]^48);
			i++;
		}
		return zlnum;
	}
	for (;i<zzl.size();i++){
		usezl[i]=1;
		if (zzl[i]=='\\'){
			break;
		}
		blm+=zzl[i];
	}
	long long zlsz[10];
	if (Sll.find(blm)!=Sll.end()){
		return Sll[blm];
	}else if (blm=="fvmod"){
		return fvmod;
	}else if (blm=="danx"){
		return danx[getzlnum(zzl,i+1)];
	}else if (blm=="dany"){
		return dany[getzlnum(zzl,i+1)];
	}else if (blm=="qkidx"){
		return qkidx[getzlnum(zzl,i+1)];
	}else if (blm=="qkidy"){
		return qkidy[getzlnum(zzl,i+1)];
	}else if (blm=="sjid"){
		return sjid;
	}else if (blm=="xiaoshi"){
		return xiaoshi;
	}else if (blm=="fen"){
		return fen;
	}else if (blm=="miao"){
		return miao;
	}else if (blm=="jishi"){
		return jishi;
	}else if (blm=="ve"){
		return ve;
	}else if (blm=="dengji"){
		return dengji;
	}else if (blm=="tfd"){
		return tfd;
	}else if (blm=="tfg"){
		return tfg;
	}else if (blm=="tfx"){
		return tfx;
	}else if (blm=="Hp"){
		return Hp;
	}else if (blm=="Gong"){
		return Gong;
	}else if (blm=="maxHp"){
		return maxHp;
	}else if (blm=="bag"){
		return bag[getzlnum(zzl,i+1)];
	}else if (blm=="wpl"){
		return wpl[getzlnum(zzl,i+1)];
	}else if (blm=="danwp"){
		return danwp;
	}else if (blm=="ji_nid"){
		return ji_nid;
	}else if (blm=="chixt"){
		return chixt;
	}else if (blm=="fchixt"){
		return fchixt[getzlnum(zzl,i+1)];
	}else if (blm=="can_do"){
		return can_do;
	}else if (blm=="jzd"){
		return jzd;
	}else if (blm=="tzd"){
		return tzd;
	}else if (blm=="cantp"){
		return cantp;
	}else if (blm=="caid"){
		return caid;
	}else if (blm=="but"){
		return but;
	}else if (blm=="ptzdw"){
		return ptzdw;
	}else if (blm=="qk.a"){
		return qk[getzlnum(zzl,i+1)][getzlnum(zzl,i+1)][getzlnum(zzl,i+1)].a[getzlnum(zzl,i+1)][getzlnum(zzl,i+1)];
	}else if (blm=="qk.bo"){
		return qk[getzlnum(zzl,i+1)][getzlnum(zzl,i+1)][getzlnum(zzl,i+1)].bo;
	}else if (blm=="Jian.gong"){
		return Jian.gong[getzlnum(zzl,i+1)];
	}else if (blm=="Jian.xt"){
		return Jian.xt;
	}else if (blm=="Jian.do_jian"){
		return Jian.do_jian[getzlnum(zzl,i+1)];
	}else if (blm=="Jian.mdoj"){
		return Jian.mdoj[getzlnum(zzl,i+1)];
	}else if (blm=="Jian.XI"){
		return Jian.XI[getzlnum(zzl,i+1)];
	}else if (blm=="Jian.chixu"){
		return Jian.chixu[getzlnum(zzl,i+1)];
	}else if (blm=="Jian.xishu"){
		return Jian.xishu;
	}else if (blm=="Jian.x_xishu"){
		return Jian.x_xishu;
	}else if (blm=="Jian.ha"){
		return Jian.ha;
	}else if (blm=="dao.gong"){
		return dao.gong[getzlnum(zzl,i+1)];
	}else if (blm=="dao.xt"){
		return dao.xt;
	}else if (blm=="dao.do_jian"){
		return dao.do_jian[getzlnum(zzl,i+1)];
	}else if (blm=="dao.mdoj"){
		return dao.mdoj[getzlnum(zzl,i+1)];
	}else if (blm=="dao.XI"){
		return dao.XI[getzlnum(zzl,i+1)];
	}else if (blm=="dao.chixu"){
		return dao.chixu[getzlnum(zzl,i+1)];
	}else if (blm=="dao.xishu"){
		return dao.xishu;
	}else if (blm=="dao.x_xishu"){
		return dao.x_xishu;
	}else if (blm=="dao.ha"){
		return dao.ha;
	}else if (blm=="qiang.gong"){
		return qiang.gong[getzlnum(zzl,i+1)];
	}else if (blm=="qiang.xt"){
		return qiang.xt;
	}else if (blm=="qiang.do_jian"){
		return qiang.do_jian[getzlnum(zzl,i+1)];
	}else if (blm=="qiang.mdoj"){
		return qiang.mdoj[getzlnum(zzl,i+1)];
	}else if (blm=="qiang.XI"){
		return qiang.XI[getzlnum(zzl,i+1)];
	}else if (blm=="qiang.chixu"){
		return qiang.chixu[getzlnum(zzl,i+1)];
	}else if (blm=="qiang.xishu"){
		return qiang.xishu;
	}else if (blm=="qiang.x_xishu"){
		return qiang.x_xishu;
	}else if (blm=="qiang.zzd"){
		return qiang.zzd;
	}else if (blm=="qiang.zshang"){
		return qiang.zshang;
	}else if (blm=="qiang.ha"){
		return qiang.ha;
	}
	return 0;
}
void sds(char dsth) { // sb. doing sth. 玩家做的事
	if ((!can_do || fchixt[0]) && dsth != 'L')
		return;
	if (ji_nid == -1 && dsth == 8) { //格挡

	}
	if (isdigit(dsth)) {
//		w(ji_nid), w("FVVVVV\n");
		if (ji_nid == -2) {
			scwp(danwp, 0);
			danwp = (dsth ^ 48);
			scwp(danwp, 1);
			scwpcd(wpl[danwp]);
			if (wpl[danwp] == 4) {
				but = bian.boxt;
				cantp = but ^ 1;
			} else {
				but = cantp = 0;
			}
		} else if (ji_nid == -1 && !fchixt[2]) {
			if (dsth == 48) {
				ji_nid--;
				return;
			}
			dsth--;
			switch (wpl[danwp]) {
				case 1: {
					Jian.fjineng(dsth ^ 48);
					break;
				}
				case 2: {
					dao.fjineng(dsth ^ 48);
					break;
				}
				case 3: {
					qiang.fjineng(dsth ^ 48);
					break;
				}
				case 4: {
					bian.fjineng(dsth ^ 48);
					break;
				}
			}
			scwpcd(wpl[danwp]);
		}
		return;
	}
	if (ji_nid == -1) {
		ji_nid--;
	}
	switch (dsth) {
		case '&': {
			ll nx = danx[sjid] + X[0], ny = dany[sjid] + Y[0];
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 0;
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 14 && !fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bl[nx][ny]) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 0;
					scgz(nx, ny, 0, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bo[fvvx[sjid][qkidx[sjid]][qkidy[sjid]].id[nx][ny]] = 0;
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
					wj_jhp(maxHp >> 2, 14);
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 0) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = -1;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
					scgz(danx[sjid], dany[sjid], 0, 0);
					scgz(nx, ny, -1, 0);
					schp(nx, ny, Hp, maxHp);
					danx[sjid] = nx, dany[sjid] = ny;
				}
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
				scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			} else if (sjid != 3) {
				nx = qkidx[sjid] + X[ve], ny = qkidy[sjid] + Y[ve];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 30 && !qk[sjid][nx][ny].a[danx[sjid]][19]) {
					swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]], qk[sjid][nx][ny].a[danx[sjid]][19]);
					dany[sjid] = 19;
					qkidx[sjid] = nx, qkidy[sjid] = ny;
					scqk();
				}
			}
			break;
		}
		case '%': {
			ll nx = danx[sjid] + X[1], ny = dany[sjid] + Y[1];
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 1;
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 14 && !fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bl[nx][ny]) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 0;
					scgz(nx, ny, 0, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bo[fvvx[sjid][qkidx[sjid]][qkidy[sjid]].id[nx][ny]] = 0;
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
					wj_jhp(maxHp >> 2, 14);
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 0) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = -1;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
					scgz(danx[sjid], dany[sjid], 0, 0);
					scgz(nx, ny, -1, 0);
					schp(nx, ny, Hp, maxHp);
					danx[sjid] = nx, dany[sjid] = ny;
				}
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
				scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			} else if (sjid != 3) {
				nx = qkidx[sjid] + X[ve], ny = qkidy[sjid] + Y[ve];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 30 && !qk[sjid][nx][ny].a[29][dany[sjid]]) {
					swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]], qk[sjid][nx][ny].a[29][dany[sjid]]);
					danx[sjid] = 29;
					qkidx[sjid] = nx, qkidy[sjid] = ny;
					scqk();
				}
			}
			break;
		}
		case '(': {
			ll nx = danx[sjid] + X[2], ny = dany[sjid] + Y[2];
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 2;
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 14 && !fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bl[nx][ny]) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 0;
					scgz(nx, ny, 0, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bo[fvvx[sjid][qkidx[sjid]][qkidy[sjid]].id[nx][ny]] = 0;
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
					wj_jhp(maxHp >> 2, 14);
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 0) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = -1;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
					scgz(danx[sjid], dany[sjid], 0, 0);
					scgz(nx, ny, -1, 0);
					schp(nx, ny, Hp, maxHp);
					danx[sjid] = nx, dany[sjid] = ny;
				}
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
				scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			} else if (sjid != 3) {
				nx = qkidx[sjid] + X[ve], ny = qkidy[sjid] + Y[ve];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 30 && !qk[sjid][nx][ny].a[danx[sjid]][0]) {
					swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]], qk[sjid][nx][ny].a[danx[sjid]][0]);
					dany[sjid] = 0;
					qkidx[sjid] = nx, qkidy[sjid] = ny;
					scqk();
				}
			}
			break;
		}
		case '\'': {
			ll nx = danx[sjid] + X[3], ny = dany[sjid] + Y[3];
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 3;
			if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 14 && !fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bl[nx][ny]) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = 0;
					scgz(nx, ny, 0, (nx == danx[sjid] + X[ve]) && (ny == dany[sjid] + Y[ve]));
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].bo[fvvx[sjid][qkidx[sjid]][qkidy[sjid]].id[nx][ny]] = 0;
					fvvx[sjid][qkidx[sjid]][qkidy[sjid]].cnt--;
					wj_jhp(maxHp >> 2, 14);
				}
				if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] == 0) {
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[nx][ny] = -1;
					qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
					scgz(danx[sjid], dany[sjid], 0, 0);
					scgz(nx, ny, -1, 0);
					schp(nx, ny, Hp, maxHp);
					danx[sjid] = nx, dany[sjid] = ny;
				}
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
				scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			} else if (sjid != 3) {
				nx = qkidx[sjid] + X[ve], ny = qkidy[sjid] + Y[ve];
				if (nx >= 0 && nx < 30 && ny >= 0 && ny < 30 && !qk[sjid][nx][ny].a[0][dany[sjid]]) {
					swap(qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]], qk[sjid][nx][ny].a[0][dany[sjid]]);
					danx[sjid] = 0;
					qkidx[sjid] = nx, qkidy[sjid] = ny;
					scqk();
				}
			}
			break;
		}
		case 'w': {
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 0;
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			break;
		}
		case 'a': {
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 1;
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			break;
		}
		case 's': {
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 2;
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			break;
		}
		case 'd': {
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			ve = 3;
			scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
			     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
			scgzhp(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			break;
		}
		case 'f': { // 攻击
			ll x = danx[sjid], y = dany[sjid];
//			while(1){
			if (wpl[danwp] == 3) {
				if (qiang.zzd) {
					bag[18]++;
					yyzy[18]++;
					qiang.zzd--;
				}
				if (!bag[18]) {
					break;
				}
				bag[18]--;
				yyzy[18]--;
				while (1) {
					x += X[ve], y += Y[ve];
					if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
						break;
					}
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						beigong(x, y, qiang.zshang);
						if (ji_nid == 4 || ji_nid == 7) {
							continue;
						}
						break;
					}
				}
				break;
			} else if (wpl[danwp] == 4) {
				if (bian.boxt) {
					bian.fjineng(8);
				} else {
					x += X[ve], y += Y[ve];
					if (x >= 0 && x < 30 && y >= 0 && y < 20) {
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
							beigong(x, y);
						}
					}
					x += Y[ve], y += X[ve];
					if (x >= 0 && x < 30 && y >= 0 && y < 20) {
						if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
							beigong(x, y);
						}
					}
					x -= (Y[ve] << 1), y -= (X[ve] << 1);
					if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
						break;
					}
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
						beigong(x, y);
						break;
					}
				}
				break;
			}
			x += X[ve], y += Y[ve];
			if (!(x >= 0 && x < 30 && y >= 0 && y < 20)) {
				break;
			}
			if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[x][y]) {
				beigong(x, y);
				break;
			}
//			}
//			beigong(danx[sjid] + X[ve], dany[sjid] + Y[ve]);
			break;
		}
		case 't': {
			w(xiaoshi, fen, miao), w("\n");
			break;
		}
		case 'T': {
			for (ll i = 0; i < 930; i++) {
				for (ll u = 0; u < 660; u++) {
					putpixel(i, u, BLACK);
				}
			}
			ll xzid = 0;
			xyprintf(7, 7, "准备好挑战劝退树了吗？");
			scgz(0, 1, 0, xzid == 0), xyprintf(1 * 30 + 7, 1 * 30 + 7, "准备好了");
			scgz(0, 2, 0, xzid == 1), xyprintf(1 * 30 + 7, 2 * 30 + 7, "还没有");
			dsth = getch();
			while (dsth) {
				if (dsth == 13) {
					if (xzid == 0) {
						tztree();
					}
					break;
				} else if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(1, xzid + 1);
				}
				scgz(0, 1, 0, xzid == 0);
				scgz(0, 2, 0, xzid == 1);
				dsth = getch();
			}
			initgraph(930, 660, 0);
			scqk();
			for (ll i = 0; i < 10; i++) {
				scwp(i, i == danwp);
			}
			scwpcd(wpl[danwp]);
			break;
		}
		case 'b': {
			if (!(qkidx[sjid] || qkidy[sjid]) && sjid != 3) {
				return;
			}
			setcolor(WHITE);
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 30; u++) {
					scgz(i, u, 0, 0);
				}
			}
			string out = "生命：" + to_string(Hp) + "/" + to_string(maxHp);
			xyprintf(7, 7, out.c_str());
			out = "等级：" + to_string(dengji);
			xyprintf(10 * 30 + 7, 7, out.c_str());
			wqjia(wpl[danwp], 1);
			out = "攻击：" + to_string(Gong);
			xyprintf(20 * 30 + 7, 7, out.c_str());
			wqjia(wpl[danwp], -1);
			out = "经验：" + to_string(bag[0]) + "/" + to_string((dengji + 1) * (dengji + 1));
			xyprintf(7, 1 * 30 + 7, out.c_str());
			out = "木头：" + to_string(bag[1]);
			xyprintf(10 * 30 + 7, 1 * 30 + 7, out.c_str());
			out = "石头：" + to_string(bag[2]);
			xyprintf(20 * 30 + 7, 1 * 30 + 7, out.c_str());
			out = "金币：" + to_string(bag[3]);
			xyprintf(7, 2 * 30 + 7, out.c_str());
			out = "影子碎片：" + to_string(bag[4]);
			xyprintf(10 * 30 + 7, 2 * 30 + 7, out.c_str());
			out = "血块：" + to_string(bag[5]);
			xyprintf(20 * 30 + 7, 2 * 30 + 7, out.c_str());
			out = "FVV：" + to_string(bag[6]);
			xyprintf(7, 3 * 30 + 7, out.c_str());
			out = "煤：" + to_string(bag[7]);
			xyprintf(10 * 30 + 7, 3 * 30 + 7, out.c_str());
			out = "Fe：" + to_string(bag[8]);
			xyprintf(20 * 30 + 7, 3 * 30 + 7, out.c_str());
			out = "Au：" + to_string(bag[9]);
			xyprintf(7, 4 * 30 + 7, out.c_str());
			out = "钻石：" + to_string(bag[10]);
			xyprintf(10 * 30 + 7, 4 * 30 + 7, out.c_str());
			out = "铁锭：" + to_string(bag[11]);
			xyprintf(20 * 30 + 7, 4 * 30 + 7, out.c_str());
			out = "金锭：" + to_string(bag[12]);
			xyprintf(7, 5 * 30 + 7, out.c_str());
			out = "FX：" + to_string(bag[13]);
			xyprintf(10 * 30 + 7, 5 * 30 + 7, out.c_str());
			out = "FVV刷怪蛋：" + to_string(bag[14]);
			xyprintf(20 * 30 + 7, 5 * 30 + 7, out.c_str());
			out = "FX刷怪蛋：" + to_string(bag[15]);
			xyprintf(7, 6 * 30 + 7, out.c_str());
			out = "Pv刷怪蛋：" + to_string(bag[16]);
			xyprintf(10 * 30 + 7, 6 * 30 + 7, out.c_str());
			out = "Pv：" + to_string(bag[17]);
			xyprintf(20 * 30 + 7, 6 * 30 + 7, out.c_str());
			out = "子弹：" + to_string(bag[18]);
			xyprintf(7, 7 * 30 + 7, out.c_str());
			out = "王：" + to_string(bag[19]);
			xyprintf(10 * 30 + 7, 7 * 30 + 7, out.c_str());
			xyprintf(7, 19 * 30 + 7, "现在时间是 %d:%d:%d", xiaoshi, fen, miao);
			getch();
			scqk();
			pjyj(dengji, bag[0]);
//			for (ll i = 0; i < 7; i++) {
//				w(bag[i]);
//			}
//			w("\n");
			break;
		}
		case 27: {
			if (!(qkidx[sjid] || qkidy[sjid]) && sjid != 3) {
				return;
			}
			for (ll i = 0; i < 930; i++) {
				for (ll u = 0; u < 660; u++) {
					putpixel(i, u, BLACK);
				}
			}
			freopen(user.c_str(), "w", stdout);
			//pzd
			w(yyjy);
			for (ll i = 0; i < 60; i++) {
				w(yyzy[i]);
			}
			xyprintf(7, 7, "1/19");
			//wj
			w(fvmod);
			for (ll i = 0; i < 4; i++) {
				w(danx[i], dany[i], qkidx[i], qkidy[i]);
			}
			w(sjid, xiaoshi, fen, miao, jishi, ve, dengji, Hp, Gong, maxHp);
			for (ll i = 0; i < 60; i++) {
				w(bag[i]);
			}
			for (ll i = 0; i < 10; i++) {
				w(wpl[i]);
			}
			w(danwp, ji_nid, chixt, can_do, tfd, tfx, tfg);
			xyprintf(7, 7, "2/19");
			//JIAN
			w(Jian.xt);
			for (ll i = 0; i < 8; i++) {
				w(Jian.do_jian[i]);
			}
			cout << Jian.xishu << " " <<  Jian.x_xishu << " ";
			w(Jian.ha);
			xyprintf(7, 7, "3/19");
			// DAO
			w(dao.xt);
			for (ll i = 0; i < 8; i++) {
				w(dao.do_jian[i]);
			}
			cout << dao.xishu << " " <<  dao.x_xishu << " ";
			w(dao.ha);
			xyprintf(7, 7, "4/19");
			//QIANG
			w(qiang.xt);
			for (ll i = 0; i < 8; i++) {
				w(qiang.do_jian[i]);
			}
			cout << qiang.xishu << " " <<  qiang.x_xishu << " ";
			w(qiang.ha);
			//BIAN
			w(bian.xt, bian.boxt);
			for (ll i = 0; i < 9; i++) {
				w(bian.do_jian[i]);
			}
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					w(bian.bo[i][u]);
				}
			}
			cout << bian.xishu << " " <<  bian.x_xishu << " ";
			w(bian.ha);
			//qk
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(qk[i][u][j].bo);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(qk[i][u][j].a[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "5/19");
			//FVVX
			/*for (ll i=0;i<4;i++){
				for (ll u=0;u<30;u++){
					for (ll j=0;j<30;j++){
						w(fvvx[i][u][j].cnt,fvv[i][u][j].jian_ge);
						for (ll k=0;k<30;k++){
							for (ll o=0;o<20;o++){
								w(fvvx[i][u][j].do_jian[k][o],fvvx[i][u][j].bl[k][o],fvvx[i][u][j].id[k][o],fvvx[i][u][j].op[k][o].size());
								for (auto num:fvvx[i][u][j].op[k][o]){
									w(num);
								}
							}
						}
						for (ll k=0;k<1000;k++){
							w(fvvx[i][u][j].bo[k]);
						}
					}
				}
			}*/
			xyprintf(7, 7, "6/19");
			//D
			w(ptzdw);
			xyprintf(7, 7, "7/19");
			//TREE
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(tree[i][u][j].cnt, tree[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(tree[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "8/19");
			//STONE
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(stone[i][u][j].cnt, stone[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(stone[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "9/19");
			//ZZT
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(zzt[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "10/19");
			//MEI
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(mei[i][u][j].cnt, mei[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(mei[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "11/19");
			//FE
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(Fe[i][u][j].cnt, Fe[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(Fe[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "12/19");
			//AU
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(Au[i][u][j].cnt, Au[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(Au[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "13/19");
			//C
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(C[i][u][j].cnt, C[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(C[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "14/19");
			//ronglu
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(rong[i][u][j].hp[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "15/19");
			//FV
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(fv[i][u][j].cnt, fv[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(fv[i][u][j].hp[k][o], fv[i][u][j].do_jian[k][o], fv[i][u][j].xt[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "16/19");
			//Fvv
			for (ll i = 0; i < 4; i++) {
				for (ll u = 0; u < 30; u++) {
					for (ll j = 0; j < 30; j++) {
						w(fvv[i][u][j].bo, fvv[i][u][j].jian_ge);
						for (ll k = 0; k < 30; k++) {
							for (ll o = 0; o < 20; o++) {
								w(fvv[i][u][j].hp[k][o], fvv[i][u][j].do_jian[k][o]);
							}
						}
					}
				}
			}
			xyprintf(7, 7, "17/19");
			// FVV
			w(F_fvv[0][0][0].slm);
			/*for (ll i=0;i<4;i++){
				for (ll u=0;u<30;u++){
					for (ll j=0;j<30;j++){
						w(F_fvv[i][u][j].bl,F_fvv[i][u][j].slm);
						for (ll k=0;k<30;k++){
							for (ll o=0;o<20;o++){
								w(F_fvv[i][u][j].hp[k][o],F_fvv[i][u][j].do_jian[k][o],F_fvv[i][u][j].xt[k][o],F_fvv[i][u][j].bo[k][o]);
							}
						}
					}
				}
			}*/
			xyprintf(7, 7, "18/19");
			// FX
			w(fx[1][0][0].slm);
			/*for (ll i=0;i<4;i++){
				for (ll u=0;u<30;u++){
					for (ll j=0;j<30;j++){
						w(fx[i][u][j].bl,fx[i][u][j].slm);
						for (ll k=0;k<30;k++){
							for (ll o=0;o<20;o++){
								w(fx[i][u][j].hp[k][o],fx[i][u][j].do_jian[k][o],fx[i][u][j].xt[k][o],fx[i][u][j].bo[k][o]);
							}
						}
					}
				}
			}*/
			// Pv
			w(pv[2][0][0].slm);
			xyprintf(7, 7, "19/19");
			getch();
			exit(0);
			break;
		}
		case 65: {
			switch (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]]) {
				case 12: {
					rong[sjid][qkidx[sjid]][qkidy[sjid]].use_rong();
					break;
				}
				case 7: {
					zzt[sjid][qkidx[sjid]][qkidy[sjid]].use_zzt();
					break;
				}
				case 16: {
					dd[sjid][qkidx[sjid]][qkidy[sjid]].hdosth();
					break;
				}
			}
			break;
		}
		case 'm': { // 制造建筑
			if (qk[sjid][qkidx[sjid]][qkidy[sjid]].bo) {
				return;
			}
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					scgz(i, u, 0, 0);
				}
			}
			ll xzid = 0;
			scgz(0, 0, 7, xzid == 0), xyprintf(1 * 30 + 7, 7, "20木头");
			scgz(0, 1, 12, xzid == 1), xyprintf(1 * 30 + 7, 1 * 30 + 7, "40石头");
			dsth = getch();
			while (dsth) {
				if (dsth == 13) {
					if (xzid == 0) {
						zzt[sjid][qkidx[sjid]][qkidy[sjid]].sczzt();
					} else if (xzid == 1) {
						rong[sjid][qkidx[sjid]][qkidy[sjid]].scrong();
					}
					break;
				} else if (dsth == '&') {
					xzid = max(0, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(1, xzid + 1);
				}
				scgz(0, 0, 7, xzid == 0), xyprintf(1 * 30 + 7, 7, "20木头");
				scgz(0, 1, 12, xzid == 1), xyprintf(1 * 30 + 7, 1 * 30 + 7, "40石头");
				dsth = getch();
			}
			scqk();
			break;
		}
		case 13: {
			if (ji_nid == -2 && wpl[danwp]) {
				ji_nid++;
			}
			break;
		}
		case 'C':{
			for (ll i = 0; i < 930; i++) {
				for (ll u = 0; u < 660; u++) {
					putpixel(i, u, BLACK);
				}
			}
			long long ha1 = 0;
			unsigned long long ha2 = 0;
			char ch = getch();
			while (ch) {
				if (ch == 8) {
					break;
				}
				ha1 = ha1 * 131LL % 998244853 + ch;
				ha1 %= 998244853;
				ha2 = ha2 * 1145141LL + ch;
				ch = getch();
			}
			if (ha1 == 821633857 && ha2 == 9327832143477642014ULL) {
				initgraph(1600,660,0);
				scqk();
				for (ll i = 0; i < 10; i++) {
					scwp(i, i == danwp);
				}
				scwpcd(wpl[danwp]);
				setcolor(ys[0]);
				line(940,0,940,659);
				ll y=0;
				string zzl="C:>",zszl;
				Sll.clear();
				while(1){
					zszl="";
					string out=zzl+zszl+' ';
					xyprintf(950,y,out.c_str());
					ch=getch();
					while(ch){
						if (ch==13){
							y+=20;
							if (y>=650){
								for (ll i = 950; i < 1600; i++) {
									for (ll u = 0; u < 660; u++) {
										putpixel(i, u, BLACK);
									}
								}
								y=0;
							}
							break;
						}
						if (ch==8){
							if (zszl.size()){
								zszl.erase(zszl.end()-1);
							}
						}else{
							zszl+=ch;
						}
						string out=zzl+zszl+' ';
						xyprintf(950,y,out.c_str());
						ch=getch();
					}
					if (zszl=="ck"){
						if (zzl=="C:>"){
							break;
						}else{
							for (ll i=0;i<zzl.size();i++){
								usezl[i]=0;
							}
							zzl[zzl.size()-1]='\\';
							ll i=3;
							string zlxt;
							for (;i<zzl.size();i++){
								if (zzl[i]=='\\'){
									break;
								}
								zlxt+=zzl[i];
							}
							if (zlxt=="long long"){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								long long zlnum=0;
								++i;
								bool blfu=0;
								while(!isdigit(zzl[i])){
									blfu^=(zzl[i]=='-');
									i++;
								}
								while(isdigit(zzl[i])){
									zlnum=(zlnum<<1)+(zlnum<<3)+(zzl[i]^48);
									i++;
								}
								if (blfu){
									zlnum=-zlnum;
								}
								Sll[blm]=zlnum;
							}else if (zlxt=="wout"){
								if(y+20>650){
									for (ll i = 950; i < 1600; i++) {
										for (ll u = 0; u < 660; u++) {
											putpixel(i, u, BLACK);
										}
									}
									y=0;
								}
								string woutnum;
								++i;
								woutnum=to_string(getzlnum(zzl,i));
								xyprintf(950,y,woutnum.c_str());
								y+=20;
							}else if (zlxt=="jags"){
								
							}else if (zlxt=="="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="+="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]+=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="-="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]-=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="*="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]*=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="/="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]/=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="^="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]^=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="|="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]|=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="&="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]&=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="%="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]%=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="=+"){
							}else if (zlxt=="=-"){
							}else if (zlxt=="=*"){
							}else if (zlxt=="=/"){
							}else if (zlxt=="=^"){
							}else if (zlxt=="=~"){
							}else if (zlxt=="=&"){
							}else if (zlxt=="=|"){
							}else if (zlxt=="=%"){
							}else if (zlxt=="=!"){
							}else if (zlxt=="=<<"){
							}else if (zlxt=="=>>"){
							}else if (zlxt=="<<="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]<<=getzlnum(zzl,i+1);
								}
							}else if (zlxt==">>="){
								string blm;
								for (i++;i<zzl.size();i++){
									if (zzl[i]=='\\'){
										break;
									}
									blm+=zzl[i];
								}
								if (Sll.find(blm)!=Sll.end()){
									Sll[blm]>>=getzlnum(zzl,i+1);
								}
							}else if (zlxt=="=>"){
							}else if (zlxt=="=<"){
							}else if (zlxt=="==="){
							}else if (zlxt=="=<="){
							}else if (zlxt=="=>="){
							}
							zzl="C:>";
						}
					}else if (zszl=="cls"){
						if (zzl=="C:>"){
							for (ll i = 950; i < 1600; i++) {
								for (ll u = 0; u < 660; u++) {
									putpixel(i, u, BLACK);
								}
							}
							y=0;
						}else{
							while(zzl.size()){
								if (zzl[zzl.size()-1]!='\\'){
									zzl.erase(zzl.end()-1);
								}else{
									break;
								}
							}
							zzl[zzl.size()-1]='>';
						}
					}else if (zszl.size()){
						zzl.erase(zzl.end()-1);
						zzl+='\\';
						zzl+=zszl;
						zzl+=">";
					}
				}
				initgraph(930,660,0);
			}
			scqk();
			for (ll i = 0; i < 10; i++) {
				scwp(i, i == danwp);
			}
			scwpcd(wpl[danwp]);
			break;
		}
		case 'L': { //防摸鱼被抓
			if (sjid == 3) {
				return;
			}
			for (ll i = 0; i < 930; i++) {
				for (ll u = 0; u < 660; u++) {
					putpixel(i, u, BLACK);
				}
			}
			system("start https://www.luogu.com.cn/problem/P9478");
			getch();
			while (1) {
				long long ha1 = 0;
				unsigned long long ha2 = 0;
				char kai = getch();
				while (kai) {
					if (kai == 8) {
						break;
					}
					ha1 = ha1 * 131LL % 998244853 + kai;
					ha1 %= 998244853;
					ha2 = ha2 * 1145141LL + kai;
					kai = getch();
				}
				if (ha1 == 821633857 && ha2 == 9327832143477642014ULL) {
					break;
				}
			}
			scqk();
			for (ll i = 0; i < 9; i++) {
				scwp(i, (i == danwp));
			}
			scwpcd(wpl[danwp]);
			break;
		}
		case 'G': {
			if (qkidx[sjid] || qkidy[sjid])
				dd[3][0][0].hdosth();
			break;
		}
		case 'h': {
			if (!(qkidx[sjid] || qkidy[sjid]) || tzd || jzd) {
				return;
			}
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					scgz(i, u, 0, 0);
				}
			}
			ll xzid = 1;
			xyprintf(7, 7, "天赋点：%d", tfd);
			xyprintf(37, 1 * 30 + 7, "%d血量：1天赋点", tfx);
			xyprintf(37, 2 * 30 + 7, "%d攻击：1天赋点", tfg);
			xyprintf(37, 3 * 30 + 7, "离开");
			scgz(0, 1, 0, 1);
			char dsth = getch();
			while (dsth) {
				scgz(0, xzid, 0, 0);
				if (dsth == 13) {
					if (xzid == 1) {
						if (tfd) {
							tfd--;
							maxHp += tfx;
							Hp += tfx;
							tfx += 20;
						}
					} else if (xzid == 2) {
						if (tfd) {
							tfd--;
							Gong += tfg;
							tfg++;
						}
					} else if (xzid == 3) {
						break;
					}
					xyprintf(7, 7, "天赋点：%d  ", tfd);
					xyprintf(37, 1 * 30 + 7, "%d血量：1天赋点", tfx);
					xyprintf(37, 2 * 30 + 7, "%d攻击：1天赋点", tfg);
				} else if (dsth == '&') {
					xzid = max(1, xzid - 1);
				} else if (dsth == '(') {
					xzid = min(3, xzid + 1);
				}
				scgz(0, xzid, 0, 1);
				dsth = getch();
			}
			scqk();
			break;
		}
	}
}

void nhd() { //no have doing 没有做
	if (keystate(key_mouse_l) && cantp) {
		int kx, ky;
		mousepos(&kx, &ky);
		kx /= 30, ky /= 30;
		if (kx >= 0 && kx < 30 && ky >= 0 && ky < 20) {
			if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].a[kx][ky]) {
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = 0;
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 0);
				scgz(danx[sjid], dany[sjid], 0, 0);
				danx[sjid] = kx, dany[sjid] = ky;
				qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid]][dany[sjid]] = -1;
				scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
				     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
				scgz(danx[sjid], dany[sjid], -1, (danx[sjid] == kx + X[ve] && dany[sjid] == ky + Y[ve]));
				scgzhp(danx[sjid], dany[sjid]);
			}
		}
	}
//	if (keystate(key_control_l) || keystate(key_control_r)) {
//	}
	jishi++;
	if (jishi == 100000) {
		miao++;
		jishi = 0;
		if (miao % 3 == 0)
			for (ll i = 0; i < 30; i++) {
				for (ll u = 0; u < 20; u++) {
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 16 && (tzd || jzd || caid)) {
						unsigned long long djiax = dd[sjid][qkidx[sjid]][qkidy[sjid]].dmaxhp(i,
						                           u) - dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u];
						if (caid) {
							djiax = min(djiax, 100000000ull);
						} else if (dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u] == 4) {
							djiax = min(djiax, 10000000ull);
						} else if (dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u] == 6) {
							if (jzd) {
								djiax = min(djiax, 100000ull);
							} else {
								djiax = min(djiax, 10ull);
							}
						} else {
							djiax = min(100000ull, djiax);
						}
						dd[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] += djiax;
						if (miao % 27 == 0) {
							dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u] += caid;
							dd[sjid][qkidx[sjid]][qkidy[sjid]].xt[i][u] %= 8;
							scgz(i, u, 16, (i == danx[sjid] + X[ve]) && (u == dany[sjid] + Y[ve]));
							scgzhp(i, u);
						}
					} else if (nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
						nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]--;
						if (!nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u]) {
							if (nfw[sjid][qkidx[sjid]][qkidy[sjid]].bl) {
								nfw[sjid][qkidx[sjid]][qkidy[sjid]].hp[i][u] = 1;
								scgz(i, u, 0, (i == danx[sjid] + X[ve]) && (u == dany[sjid] + Y[ve]));
								scbhp(18, 1, 10000);
//								return;
							} else {
								qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] = 0;
								bag[19]++;
								yyzy[19]++;
								scgz(i, u, 0, (i == danx[sjid] + X[ve]) && (u == dany[sjid] + Y[ve]));
								scbhp(18, 0, 10000);
							}
						}
						if (miao % 27 == 0) {
							scgzhp(i, u);
						}
					}
				}
			}
		if (miao == 60) {
			if (wpl[danwp] == 2 && (ji_nid == 1 || ji_nid == 7)) {
				Hp = min(maxHp, Hp + (maxHp >> 7));
			}
			miao = 0;
			fen++;
			if (sjid != 3) {
//			if (!qk[sjid][qkidx[sjid]][qkidy[sjid]].bo) {
				stone[sjid][qkidx[sjid]][qkidy[sjid]].scs();
				tree[sjid][qkidx[sjid]][qkidy[sjid]].sct();
				mei[sjid][qkidx[sjid]][qkidy[sjid]].scmei();
				Fe[sjid][qkidx[sjid]][qkidy[sjid]].scFe();
				Au[sjid][qkidx[sjid]][qkidy[sjid]].scAu();
				C[sjid][qkidx[sjid]][qkidy[sjid]].scC();
//			} else {
				f_xie[sjid][qkidx[sjid]][qkidy[sjid]].scx();
			}
			fvvx[sjid][qkidx[sjid]][qkidy[sjid]].scfvvx();
			if (sjid != 3)
				fv[sjid][qkidx[sjid]][qkidy[sjid]].scg();
//			}
			if ((dd[sjid][qkidx[sjid]][qkidy[sjid]].bkills[danx[sjid]][1] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[1])
			        || (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkills[danx[sjid]][2] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[2])
			        || (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkillh[dany[sjid]][1] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[1])
			        || (dd[sjid][qkidx[sjid]][qkidy[sjid]].bkillh[dany[sjid]][2] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[2])) {
				getch();
				exit(0);
			}
			for (ll i = 0; i < 30; i++) {
				if ((dd[sjid][qkidx[sjid]][qkidy[sjid]].kills[i][1] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[1])
				        || (dd[sjid][qkidx[sjid]][qkidy[sjid]].kills[i][2] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[2])) {
					if (abs(i - danx[sjid]) <= 1) {
						exit(0);
					}
				}
				for (ll u = 0; u < 20; u++) {
					if ((dd[sjid][qkidx[sjid]][qkidy[sjid]].killh[u][1] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[1])
					        || (dd[sjid][qkidx[sjid]][qkidy[sjid]].killh[u][2] && dd[sjid][qkidx[sjid]][qkidy[sjid]].killbl[2])) {
						if (abs(u - dany[sjid]) <= 1) {
							exit(0);
						}
					}
					if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 3) {
						fv[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 4) {
						fvv[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 6) {
						F_fvv[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 13) {
						fx[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 14) {
						fvvx[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 15) {
						pv[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 16 && (tzd || jzd)) {
						dd[sjid][qkidx[sjid]][qkidy[sjid]].dsth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 17) {
						bing[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					} else if (qk[sjid][qkidx[sjid]][qkidy[sjid]].a[i][u] == 18) {
						nfw[sjid][qkidx[sjid]][qkidy[sjid]].dosth(i, u);
					}
				}
			}
			if (chixt) {
				if (but) {
					for (ll i = 0; i < 6; i++) {
						fchixt[i] = 0;
					}
				}
				if (--chixt == 0) {
					switch (wpl[danwp]) {
						case 1: {
							Jian.sjineng();
							break;
						}
						case 2: {
							dao.sjineng();
							break;
						}
						case 3: {
							qiang.sjineng();
							break;
						}
						case 4: {
							bian.sjineng();
							break;
						}
					}
					ji_nid = -2;
				}
			}
			if (fchixt[0]) {
				fchixt[0]--;
			}
			if (fchixt[1]) {
				fchixt[1]--;
				wj_jhp(min(Hp, maxHp >> 9), 1);
			}
			if (fchixt[2]) {
				fchixt[2]--;
			}
			for (ll i = 0; i < 10; i++) {
				wqlq(wpl[i]);
			}
			scwpcd(wpl[danwp]);
			if (fen == 60) {
				fvmod = min(60 + fvmod, 10000);
				fen = 0;
				xiaoshi++;
				if (xiaoshi == 24) {
					Hp = min(maxHp, Hp + (maxHp >> 2));
					xiaoshi = 0;
				}
			}
		}
	}
}

void kai_shi() { //开始 win10切 win11不切
	long long ha1 = 0;
	unsigned long long ha2 = 0;
//	char kai = getch();
	char kai;
//
//	while (kai) {
//		if (kai == 8) {
//			break;
//		}
////		w((ll)kai);
//		ha1 = ha1 * 131LL % 998244853 + kai;
//		ha1 %= 998244853;
//		ha2 = ha2 * 1145141LL + kai;
//		kai = getch();
//	}
////	w(ha1, ha2);
//	if (ha1 != 821633857 || ha2 != 9327832143477642014ULL) {
//		exit(0);
//	}
	ll xzid = 0;
	scgz(0, 0, 0, 1);
	xyprintf(1 * 30 + 7, 7, "登录");
	xyprintf(1 * 30 + 7, 1 * 30 + 7, "注册");
	kai = getch();

	while (kai) {
		if (kai == 13) {
			break;
		}
		scgz(0, xzid, 0, 0);
		if (kai == '&') {
			xzid = max(0, xzid - 1);
		} else if (kai == '(') {
			xzid = min(1, xzid + 1);
		}
		scgz(0, xzid, 0, 1);
		kai = getch();
	}

	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			scgz(i, u, 0, 0);
		}
	}
	xyprintf(7, 7, "输入名称（10字符以内）");
	kai = getch();

	while (kai) {
		if (kai == 13) {
			break;
		} else if (kai == 8) {
			if (user.size()) {
				user.erase(user.size() - 1);
				xyprintf(7, 1 * 30 + 7, "          ");
			}
		} else if (user.size() < 10) {
			user += kai;
		}
		xyprintf(7, 1 * 30 + 7, user.c_str());
		kai = getch();
	}
	long long hash1 = 0, base1 = 131, mod1 = 998244353;
	unsigned long long hash2 = 0, base2 = 11451, mod2 = 212370440130137957LL;

	for (ll i = 0; i < user.size(); i++) {
		hash1 = (hash1 * base1 % mod1 + user[i]) % mod1;
		hash2 = (hash2 * base2 + user[i]) % mod2 + base1;
	}

	user = to_string(hash1) + to_string(hash2) + ".fvalxq"; //fval=fvv all,x=chu,q=pin
	for (ll i = 0; i < 30; i++) {
		for (ll u = 0; u < 20; u++) {
			scgz(i, u, 0, 0);
		}
	}

	if (freopen(user.c_str(), "r", stdin) != nullptr) {
		if (xzid) {
			xyprintf(7, 7, "已注册");
			getch();
			exit(0);
		}
		//pzd
		r(yyjy);
		for (ll i = 0; i < 60; i++) {
			r(yyzy[i]);
		}
		xyprintf(7, 7, "1/19");
		//wj
		r(fvmod);
		for (ll i = 0; i < 4; i++) {
			r(danx[i], dany[i], qkidx[i], qkidy[i]);
		}
		r(sjid, xiaoshi, fen, miao, jishi, ve, dengji, Hp, Gong, maxHp);
		for (ll i = 0; i < 60; i++) {
			r(bag[i]);
		}
		for (ll i = 0; i < 10; i++) {
			r(wpl[i]);
		}
		r(danwp, ji_nid, chixt, can_do, tfd, tfx, tfg);
		xyprintf(7, 7, "2/19");
		//JIAN
		r(Jian.xt);
		for (ll i = 0; i < 8; i++) {
			r(Jian.do_jian[i]);
		}
		cin >> Jian.xishu >> Jian.x_xishu;
		r(Jian.ha);
		xyprintf(7, 7, "3/19");
		// DAO
		r(dao.xt);
		for (ll i = 0; i < 8; i++) {
			r(dao.do_jian[i]);
		}
		cin >> dao.xishu >> dao.x_xishu;
		r(dao.ha);
		xyprintf(7, 7, "4/19");
		//QIANG
		r(qiang.xt);
		for (ll i = 0; i < 8; i++) {
			r(qiang.do_jian[i]);
		}
		cin >> qiang.xishu >> qiang.x_xishu;
		r(qiang.ha);
		//BIAN
		r(bian.xt, bian.boxt);
		for (ll i = 0; i < 9; i++) {
			r(bian.do_jian[i]);
		}
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				r(bian.bo[i][u]);
			}
		}
		cin >> bian.xishu >> bian.x_xishu;
		r(bian.ha);
		//qk
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(qk[i][u][j].bo);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(qk[i][u][j].a[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "5/19");
		//FVVX
		/*for (ll i=0;i<4;i++){
			for (ll u=0;u<30;u++){
				for (ll j=0;j<30;j++){
					r(fvvx[i][u][j].cnt,fvv[i][u][j].jian_ge);
					for (ll k=0;k<30;k++){
						for (ll o=0;o<20;o++){
							ll siz;
							r(fvvx[i][u][j].do_jian[k][o],fvvx[i][u][j].bl[k][o],fvvx[i][u][j].id[k][o],siz);
							while(siz--){
								ll x;
								r(x);
								fvvx[i][u][j].op[k][o].insert(x);
							}
						}
					}
					for (ll k=0;k<1000;k++){
						r(fvvx[i][u][j].bo[k]);
					}
				}
			}
		}*/
		xyprintf(7, 7, "6/19");
		//D
		r(ptzdw);
		xyprintf(7, 7, "7/19");
		//TREE
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(tree[i][u][j].cnt, tree[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(tree[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "8/19");
		//STONE
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(stone[i][u][j].cnt, stone[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(stone[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "9/19");
		//ZZT
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(zzt[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "10/19");
		//MEI
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(mei[i][u][j].cnt, mei[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(mei[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "11/19");
		//FE
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(Fe[i][u][j].cnt, Fe[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(Fe[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "12/19");
		//AU
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(Au[i][u][j].cnt, Au[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(Au[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "13/19");
		//C
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(C[i][u][j].cnt, C[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(C[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "14/19");
		//ronglu
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(rong[i][u][j].hp[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "15/19");
		//FV
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(fv[i][u][j].cnt, fv[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(fv[i][u][j].hp[k][o], fv[i][u][j].do_jian[k][o], fv[i][u][j].xt[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "16/19");
		//Fvv
		for (ll i = 0; i < 4; i++) {
			for (ll u = 0; u < 30; u++) {
				for (ll j = 0; j < 30; j++) {
					r(fvv[i][u][j].bo, fvv[i][u][j].jian_ge);
					for (ll k = 0; k < 30; k++) {
						for (ll o = 0; o < 20; o++) {
							r(fvv[i][u][j].hp[k][o], fvv[i][u][j].do_jian[k][o]);
						}
					}
				}
			}
		}
		xyprintf(7, 7, "17/19");
		// FVV
		r(F_fvv[0][0][0].slm);
		/*for (ll i=0;i<4;i++){
			for (ll u=0;u<30;u++){
				for (ll j=0;j<30;j++){
					r(F_fvv[i][u][j].bl,F_fvv[i][u][j].slm);
					for (ll k=0;k<30;k++){
						for (ll o=0;o<20;o++){
							r(F_fvv[i][u][j].hp[k][o],F_fvv[i][u][j].do_jian[k][o],F_fvv[i][u][j].xt[k][o],F_fvv[i][u][j].bo[k][o]);
						}
					}
				}
			}
		}*/
		xyprintf(7, 7, "18/19");
		// FX
		r(fx[1][0][0].slm);
		/*for (ll i=0;i<4;i++){
			for (ll u=0;u<30;u++){
				for (ll j=0;j<30;j++){
					r(fx[i][u][j].bl,fx[i][u][j].slm);
					for (ll k=0;k<30;k++){
						for (ll o=0;o<20;o++){
							r(fx[i][u][j].hp[k][o],fx[i][u][j].do_jian[k][o],fx[i][u][j].xt[k][o],fx[i][u][j].bo[k][o]);
						}
					}
				}
			}
		}*/
		// Pv
		xyprintf(7, 7, "19/19");
		r(pv[2][0][0].slm);
		getch();
		for (ll i = 0; i < 30; i++) {
			for (ll u = 0; u < 20; u++) {
				scgz(i, u, 0, 0);
			}
		}

	} else if (!xzid) {
		xyprintf(7, 7, "请先注册");
		getch();
		exit(0);
	}
	freopen(nullptr, "r", stdin);
	scgz(0, 0, -1, 0), xyprintf(1 * 30 + 7, 7, "就是你");
	scgz(0, 1, 0, 0), xyprintf(1 * 30 + 7, 1 * 30 + 7, "空格子");
	scgz(0, 2, 0, 1), xyprintf(1 * 30 + 7, 2 * 30 + 7, "你选中的格子");
	scgz(0, 3, 1, 0), xyprintf(1 * 30 + 7, 3 * 30 + 7, "可以获得木头");
	scgz(0, 4, 2, 0), xyprintf(1 * 30 + 7, 4 * 30 + 7, "可以获得石头");
	scgz(0, 5, 3, 0), xyprintf(1 * 30 + 7, 5 * 30 + 7, "会攻击你");
//	scgz(0, 6, 4, 0), xyprintf(1 * 30 + 7, 6 * 30 + 7, "FVV的虚影,精英怪");
	scgz(0, 6, 4, 0), xyprintf(1 * 30 + 7, 6 * 30 + 7, "帝的虚影,精英怪");
//	scgz(1, 7, 0, 1);
//	xyprintf(1 * 30 + 3, 7 * 30 + 3, "make");
	getch();
}

int main() {
	initgraph(930, 660, 0);
	setfont(10, 5, "Fixedsys");
//	ptzdw=(1<<7)-1;
//	jgshu(0,0,900,600);
//	jgheng(0,0,900,600);
//	dd[0][0][0].hdh(6);
//	getch();
//	return 0;
//	xyprintf(300, 300, "ρ");
	for (ll i = 0; i < 4; i++) {
		qkidx[i] = qkidy[i] = 1;
		danx[i] = dany[i] = 15;
		qk[i][1][1].a[15][15] = -1;
		qk[i][0][0].bo = 1;
	}
	Gong = wjcsg;
	Hp = maxHp = wjcshp;
	wpl[0] = 1;
	Jian.xt = 7;
	Jian.ha = 1;
	sjid = 0;
	dao.xt = 7;
	dao.ha = 1;
	wpl[1] = 2;
	qiang.ha = 1;
	qiang.xt = 7;
	wpl[2] = 3;
	bian.ha = 1;
	bian.xt = 4;
	wpl[3] = 4;
//	setcolor(WHITE);
//	xyprintf(7,7,"帝");
////	scgz(0,0,4,0);
//	freopen("init.txt","w",stdout);
//	for (ll i=0;i<30;i++){
//		for (ll u=0;u<30;u++){
//			putchar((getpixel(u,i)==0xfcfcfc)+48);
////			xyprintf(30,7,"%lld %lld",i,u);
////			xyprintf(30,30,"%p",getpixel(i,u));
////			if ((getpixel(i,u)!=0xff000000))
////			getch();
//		}
//		putchar('\n');
//	}
//	getch();
//	return 0;
	kai_shi();
//	xyprintf(5, 5, "非科学人");
	scqk();
	bag[11] += 10000;
	bag[12] += 10000;
	yyzy[11] += 10000;
	yyzy[12] += 10000;
	bag[5] += 10000;
	yyzy[5] += 10000;
	bag[18] += 1000000000;
	for (ll i = 0; i < 10; i++) {
		scwp(i, i == danwp);
	}
	scwpcd(wpl[danwp]);
//	while (dengji<30000) {
//		dengji++;
//		tfd++;
//		maxHp += (dengji << 2);
//		Hp += (dengji << 2);
//		Gong += (dengji + 1 >> 1);
//	}
///	bag[0]=114;
//	scgz(danx[sjid] + X[ve], dany[sjid] + Y[ve],
//	     qk[sjid][qkidx[sjid]][qkidy[sjid]].a[danx[sjid] + X[ve]][dany[sjid] + Y[ve]], 1);
//	schp(15, 15, 1, 1);
	while (1) {
		while (!kbhit()) {
			nhd();
		}
		while (kbhit()) {
			char ch = getch();
//			cout << ch << "\n";
			sds(ch);
			nhd();
		}
	}
	return 0;
}