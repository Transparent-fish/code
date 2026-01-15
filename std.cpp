#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define DEbug
const int N = 2005;
int n, m, who_win = -1, FP_cnt, top = 1;
char cards[N];
struct node {
  int per, nex;
  int hp = 4, cnt;
  int dead, zgln, is_jump, leifan, MP_card_clear;
  bool vis[N];
  char card[N];
  string name, jump;
} a[N];
void DEBUG() {
#ifdef DEbug
#endif
}
void DEBUG_Print() {
#ifdef DEbug
  cout << "DEBUG Printf:\n";
  for (int i = 1; i <= n; i++) {
    cout << i << " " << a[i].hp << " ";
  }
  cout << "\nDEBUG_Print End\n";
#endif
}
void Scanf() { // 已完成
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].name;
    a[i].hp = 4;
    for (int j = 1; j <= 4; j++) {
      cin >> a[i].card[j];
      a[i].cnt++;
    }
    if (a[i].name == "FP") FP_cnt++;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      a[i].per = n;
    else
      a[i].per = i - 1;
    if (i == n)
      a[i].nex = 1;
    else
      a[i].nex = i + 1;
    a[i].hp = 4;
  }
  for (int i = 1; i <= m; i++) {
    cin >> cards[i];
  }
  // for (int i = 1; i <= n; i++) {
  // cout << a[i].name << "\n";
  // }
}
void init() { // 已完成
  a[1].is_jump = 1;
  Scanf();
}
void Printf() { // 已完成
  if (who_win == 0) { // FP Win
    cout << "FP\n";
  } else if (who_win == 1) {
    cout << "MP\n";
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].dead == 1) {
      cout << "DEAD\n";
      continue;
    } else {
      bool first = true;
      for (int j = 1; j <= a[i].cnt; j++) {
        if (a[i].vis[j] == 0) {
          if (!first) cout << " ";
          cout << a[i].card[j];
          first = false;
        }
      }
      cout << "\n";
    }
  }
}
int Zgln(int x) { // 已完成
  int Cnt = 0;
  for (int i = 1; i <= a[x].cnt; i++) {
    if (!a[x].vis[i] && a[x].card[i] == 'K') {
      Cnt++;
    }
  }
  return Cnt;
}
void Get_card(int x) { // 已完成
  if (top <= m) {
    a[x].card[++a[x].cnt] = cards[top];
    top++;
  } else {
    a[x].card[++a[x].cnt] = cards[m];
  }
}
bool Use_P(int x) { // 已完成
  if (a[x].hp < 4) {
    a[x].hp++;
    return 1;
  }
  return 0;
}
void Die(int x, int killer) { // 已完成
  while (a[x].hp <= 0) {
    bool used = false;
    for (int k = 1; k <= a[x].cnt; k++) {
      if (a[x].card[k] == 'P' && a[x].vis[k] == 0) {
        a[x].vis[k] = 1;
        a[x].hp++;
        used = true;
        break;
      }
    }
    if (!used) break;
  }
  if (a[x].hp <= 0) {
    a[x].dead = 1;
    a[a[x].per].nex = a[x].nex;
    a[a[x].nex].per = a[x].per;
    // cout << "Dead \n";
    if (a[x].name == "MP") {
      // FP win
      who_win = 0; // FP win
      return;
    } else if (a[x].name == "FP") {
      FP_cnt--;
      if (FP_cnt == 0) {
        who_win = 1; // ZP MP win
        return;
      }
      Get_card(killer), Get_card(killer), Get_card(killer);
    } else if (a[x].name == "ZP" && a[killer].name == "MP") {
      a[killer].cnt = 0;
      a[killer].zgln = 0;
      a[killer].MP_card_clear = 1;
      memset(a[killer].card, 0, sizeof(a[killer].card));
      memset(a[killer].vis, 0, sizeof(a[killer].vis));
    }
  }
}
void Use_D(int x) { // 已完成
  bool is_use_D = 0;
  for (int i = 1; i <= a[x].cnt; i++) {
    if (a[x].card[i] == 'D' && a[x].vis[i] == 0) {
      a[x].vis[i] = 1;
      is_use_D = 1;
      break;
    }
  }
  if (!is_use_D) {
    a[x].hp--;
  }
}
bool Use_Kill(int x) { // 已完成
  if (a[x].name == "FP") {
    if (a[a[x].nex].is_jump == 1 &&
        (a[a[x].nex].name == "MP" || a[a[x].nex].name == "ZP")) {
      a[x].is_jump = 1;
      Use_D(a[x].nex);
      if (a[a[x].nex].hp <= 0) Die(a[x].nex, x);
      return 1;
    }
  } else if (a[x].name == "ZP") {
    if (a[a[x].nex].is_jump == 1 && (a[a[x].nex].name == "FP")) {
      a[x].is_jump = 1 /*, a[x].jump = "ZP"*/; // 跳忠
      Use_D(a[x].nex);
      if (a[a[x].nex].hp <= 0) Die(a[x].nex, x);
      return 1;
    }
  } else { // MP
    if ((a[a[x].nex].is_jump == 1 && a[a[x].nex].name == "FP") ||
        a[a[x].nex].leifan) {
      a[x].is_jump = 1;
      Use_D(a[x].nex);
      if (a[a[x].nex].hp <= 0) Die(a[x].nex, x);
      return 1;
    }
  }
  return 0;
}
void implement_F(int x, int y) { // 执行 F 逻辑 x 对 y 已完成
  if (a[x].name == "MP" && a[y].name == "ZP") { // MP to Zp Zp hp--
    a[y].hp--;
    if (a[y].hp <= 0) Die(y, x);
    return;
  }
  int who_qi_kill = y;
  while (true) {
    bool qi_kill_is_use_kill = 0;
    for (int i = 1; i <= a[who_qi_kill].cnt; i++) {
      if (a[who_qi_kill].card[i] == 'K' && a[who_qi_kill].vis[i] == 0) {
        a[who_qi_kill].vis[i] = 1;
        qi_kill_is_use_kill = 1;
        who_qi_kill = (who_qi_kill == x ? y : x);
        break;
      }
    }
    if (qi_kill_is_use_kill == 0) {
      a[who_qi_kill].hp--;
      int who_kill_qi;
      if (who_qi_kill == x)
        who_kill_qi = y;
      else
        who_kill_qi = x;
      if (a[who_qi_kill].hp <= 0) Die(who_qi_kill, who_kill_qi);
      return;
    }
  }
}
bool use_J(int x, int y) { // x 对 y 用，x用 y是那方 已完成
  // y : 1 MP 2FP
  int now = x;
  do {
    if ((a[now].name == "MP" || a[now].name == "ZP") && y == 1) {
      for (int i = 1; i <= a[now].cnt; i++) {
        if (a[now].card[i] == 'J' && a[now].vis[i] == 0) {
          a[now].vis[i] = 1;
          if (a[now].is_jump == 0) a[now].is_jump = 1;
          return !use_J(now, 2);
        }
      }
    } else if ((a[now].name == "FP") && y == 2) {
      for (int i = 1; i <= a[now].cnt; i++) {
        if (a[now].card[i] == 'J' && a[now].vis[i] == 0) {
          a[now].vis[i] = 1;
          if (a[now].is_jump == 0) a[now].is_jump = 1;
          return !use_J(now, 1);
        }
      }
    }
    now = a[now].nex;
  } while (now != x);
  return 0;
}
bool Use_F(int x) { // x用 已完成
  if (a[x].name == "FP") { // FP find MP
    a[x].is_jump = 1; // 跳了
    bool is_use_J = use_J(x, 1);
    if (is_use_J == 0) {
      implement_F(x, 1);
      return 1;
    }
  } else if (a[x].name == "MP") { // MP find FP and LP
    for (int i = a[x].nex; i != x; i = a[i].nex) {
      if ((a[i].is_jump == 1 && a[i].name == "FP") || a[i].leifan == 1) {
        bool can_use_J = 0;
        if (a[i].is_jump == 1) can_use_J = use_J(x, 2);
        if (can_use_J == 0) {
          implement_F(1, i);
          return 1;
        }
      }
    }
  } else { // ZP find FP
    for (int i = a[x].nex; i != x; i = a[i].nex) {
      if (a[i].is_jump == 1 && a[i].name == "FP") {
        bool can_use_J = 0;
        if (a[i].is_jump == 1) can_use_J = use_J(x, 2);
        if (can_use_J == 0) {
          implement_F(x, i);
          return 1;
        }
      }
    }
  }
  return 0;
}
bool Use_N(int x) { // x用 已完成
  for (int i = a[x].nex; i != x; i = a[i].nex) {
    bool is_use_kill = 0;
    if (a[i].is_jump == 1) {
      int use_J_y = (a[i].name == "FP" ? 2 : 1);
      if (use_J(x, use_J_y)) continue;
    }
    for (int j = 1; j <= a[i].cnt; j++) {
      if (a[i].card[j] == 'K' && a[i].vis[j] == 0) {
        a[i].vis[j] = 1;
        is_use_kill = 1;
        break;
      }
    }
    if (is_use_kill == 0) {
      a[i].hp--;
      if (i == 1 && a[x].is_jump == 0) {
        a[x].leifan = 1;
      }
      if (a[i].hp <= 0) Die(i, x);
      if (who_win != -1) return 1;
    }
  }
  return 1;
}
bool Use_W(int x) { // 已完成
  for (int i = a[x].nex; i != x; i = a[i].nex) {
    bool is_use_kill = 0;
    if (a[i].is_jump == 1) {
      int use_J_y = (a[i].name == "FP" ? 2 : 1);
      if (use_J(x, use_J_y)) continue;
    }
    for (int j = 1; j <= a[i].cnt; j++) {
      if (a[i].card[j] == 'D' && a[i].vis[j] == 0) {
        a[i].vis[j] = 1;
        is_use_kill = 1;
        break;
      }
    }
    if (is_use_kill == 0) {
      a[i].hp--;
      if (i == 1 && a[x].is_jump == 0) {
        a[x].leifan = 1;
      }
      if (a[i].hp <= 0) Die(i, x);
      if (who_win != -1) return 1;
    }
  }
  return 1;
}
void game() {
  int start = 1;
  for (; who_win == -1;) {
    int now = start;
    do {
      if (!a[now].dead) {
        Get_card(now), Get_card(now);
        int use_kill_num = 0;
        for (int j = 1; j <= a[now].cnt; j++) {
          if (a[now].vis[j]) continue;
          bool is_use_card = 0;
          char c = a[now].card[j];
          if (c == 'P') {
            is_use_card = Use_P(now);
          }
          if (c == 'K') {
            if (use_kill_num == 0 || a[now].zgln) {
              is_use_card = Use_Kill(now);
            }
            if (is_use_card) use_kill_num++;
          }
          if (c == 'Z') {
            is_use_card = 1;
            a[now].zgln = 1;
          }
          if (c == 'F') {
            is_use_card = Use_F(now);
          }
          if (c == 'N') {
            is_use_card = Use_N(now);
          }
          if (c == 'W') {
            is_use_card = Use_W(now);
          }
          if (is_use_card) {
            if (now == 1 && a[1].MP_card_clear) {
              a[1].MP_card_clear = 0;
            } else {
              a[now].vis[j] = 1;
            }
            j = 0; // 注意j从0开始? Wait, for(j=1;), j=1 -1? No, j=1;
          }
          if (a[now].dead) break;
          if (who_win != -1) break;
        }
      }
      if (who_win != -1) break;
      now = a[now].nex;
    } while (now != start && who_win == -1);
  }
  DEBUG();
  DEBUG_Print();
  Printf();
}
signed main() {
  init(), game();
  // for (int i = 1; i <= n; i++) {
  // cout << a[i].name << " per: " << a[i].per << " nex: " << a[i].nex <<
  // "\n";
  // }
  return 0;
}