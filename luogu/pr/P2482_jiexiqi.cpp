#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11, debug = 1;

struct Pig {
  string type;
  bool Show, Z, Attack; // 是否跳, 是否装备了猪哥连弩, 是否用南猪入侵 / 万箭齐发对主猪造成伤害
  int hp;
  vector<char> card; // card[i] == 'A' 表示没有这张牌
  int prev, next;
} Player[MAXN];

int n, m, nowtop;
bool vis[MAXN];
vector<char> deck;

int GameOver() {
  if (!Player[0].hp) {
    return 2;
  }
  for (int i = Player[0].next; i != 0; i = Player[i].next) {
    if (Player[i].type == "FP") {
      return 0;
    }
  }
  return 1;
}

void GetCard(int x, int cnt) {
  for (int i = 1; i <= cnt; ++i) {
    if (debug) {
      cout << x << " Get Card " << deck[nowtop] << "\n";
    }
    Player[x].card.emplace_back(deck[nowtop++]);
    nowtop = min(nowtop, m - 1);
  }
}

bool Peach(int x) {
  int i = 0;
  for (char c : Player[x].card) {
    if (c == 'P') {
      if (debug) {
        cout << x << " Eat Peach, hp " << Player[x].hp << " -> " << Player[x].hp + 1 << "\n";
      }
      Player[x].card[i] = 'A', Player[x].hp++;
      return 1;
    }
    i++;
  }
  return 0;
}

bool Dead(int x) {
  (!Player[x].hp && Peach(x));
  if (Player[x].hp) {
    return 0;
  }
  Player[Player[x].prev].next = Player[x].next, Player[Player[x].next].prev = Player[x].prev;
  Player[x].card.clear(), Player[x].Z = 0;
  if (debug) {
    cout << x << " Died\n";
  }
  return 1;
}

bool Duck(int x) {
  int i = 0;
  for (char c : Player[x].card) {
    if (c == 'D') {
      Player[x].card[i] = 'A';
      if (debug) {
        cout << x << " Duck\n";
      }
      return 1;
    }
    i++;
  }
  return 0;
}

bool Kill(int x) {
  int y = Player[x].next;
  if (!x) {
    if (!(Player[y].Show || !Player[y].Attack) || (Player[y].Show && Player[y].type == "FP")) {
      if (debug) {
        cout << x << " Kill " << y << "\n";
      }
      if (debug) {
        if (!Duck(y)) {
          if (debug) {
            cout << y << " hp " << Player[y].hp << " -> " << Player[y].hp - 1 << "\n";
          }
          Player[y].hp--;
        }
      } else {
        Player[y].hp -= !Duck(y);
      }
      if (Dead(y)) {
        if (Player[y].type == "FP") {
          if (GameOver()) {
            return 1;
          }
          GetCard(x, 3);
        } else {
          Player[x].card.clear(), Player[x].Z = 0;
        }
      }
      return 1;
    }
    return 0;
  } else {
    if (Player[y].Show && Player[y].type != Player[x].type) {
      if (debug) {
        cout << x << " Kill " << y << "\n";
      }
      Player[y].hp -= !Duck(y), Player[x].Show = 1;
      if (Dead(y) && Player[y].type == "FP") {
        if (GameOver()) {
          return 1;
        }
        GetCard(x, 3);
      }
      return 1;
    }
    return 0;
  }
}

int dueling(int x, int y) { // x 对 y 出决斗, 返回获胜者
  int i = 0, j = 0;
  for (; ; ) {
    for (; i < int(Player[y].card.size()) && Player[y].card[i] != 'K'; ++i) {
    }
    if (i == int(Player[y].card.size())) {
      if (debug) {
        cout << x << " " << y << " deul end, " << x << " win\n";
      }
      return x;
    }
    if (debug) {
      cout << y << " Attack\n";
    }
    Player[y].card[i] = 'A';
    for (; j < int(Player[x].card.size()) && Player[x].card[j] != 'K'; ++j) {
    }
    if (j == int(Player[x].card.size())) {
      if (debug) {
        cout << x << " " << y << " duel end, " << y << " win\n";
      }
      return y;
    }
    if (debug) {
      cout << x << " Attack\n";
    }
    Player[x].card[j] = 'A';
  }
  if (debug) {
    cout << "Wrong Answer\n";
  }
  return -1;
}

bool Wuxie(int x) { // 从 x 开始, 无懈 x 出的无懈可击
  bool op = 1;
  for (int i = x; i != x || op; i = Player[i].next) {
    if ((!i && (!(Player[x].Show || !Player[x].Attack) || (Player[x].Show && Player[x].type == "FP"))) || (i
            && Player[i].type != Player[x].type && Player[x].Show)) {
      int j = 0;
      for (char c : Player[i].card) {
        if (c == 'J') {
          Player[i].card[j] = 'A', Player[i].Show = 1;
          if (debug) {
            cout << i << " Wuxie " << x << "'s Wuxie\n";
          }
          if (!Wuxie(i)) {
            return 1;
          }
        }
        j++;
      }
    }
    op = 0;
  }
  return 0;
}

bool Wuxie(int x, int y) { // 从 x 开始, 为 y 出无懈可击
  bool op = 1;
  for (int i = x; i != x || op; i = Player[i].next) {
    if (Player[i].type == Player[y].type && Player[y].Show) {
      int j = 0;
      for (char c : Player[i].card) {
        if (c == 'J') {
          Player[i].card[j] = 'A', Player[i].Show = 1;
          if (debug) {
            cout << i << " Help " << y << " Wuxie " << x << "'s Attack\n";
          }
          if (!Wuxie(i)) {
            if (debug) {
              cout << i << " Help " << y << " Wuxie " << x << "'s Attack OK\n";
            }
            return 1;
          } else {
            if (debug) {
              cout << i << " Help " << y << " Wuxie " << x << "'s Attack NO\n";
            }
          }
        }
        j++;
      }
    }
    op = 0;
  }
  return 0;
}

bool duel(int x) {
  if (Player[x].type == "FP") {
    Player[x].Show = 1;
    if (debug) {
      cout << x << " " << 0 << " duel\n";
    }
    if (!Wuxie(x, 0))  {
      int win = dueling(x, 0);
      if (win == x) {
        if (debug) {
          cout << 0 << " hp " << Player[0].hp << " -> " << Player[0].hp - 1 << "\n";
        }
        Player[0].hp--;
        Dead(0);
      } else {
        if (debug) {
          cout << x << " hp " << Player[x].hp << " -> " << Player[x].hp - 1 << "\n";
        }
        Player[x].hp--;
        if (Dead(x)) {
          if (GameOver()) {
            return 1;
          }
          GetCard(0, 3);
        }
      }
    }
    return 1;
  }
  for (int i = Player[x].next; i != x; i = Player[i].next) {
    if (!x) {
      if (!(Player[i].Show || !Player[i].Attack) || (Player[i].Show && Player[i].type == "FP")) {
        if (debug) {
          cout << x << " " << i << " duel\n";
        }
        if (!Wuxie(0, i)) {
          if (Player[i].type == "FP") {
            int win = dueling(0, i);
            if (win == 0) {
              if (debug) {
                cout << i << " hp " << Player[i].hp << " -> " << Player[i].hp - 1 << "\n";
              }
              Player[i].hp--;
              if (Dead(i)) {
                if (GameOver()) {
                  return 1;
                }
                GetCard(0, 3);
              }
            } else {
              if (debug) {
                cout << 0 << " hp " << Player[0].hp << " -> " << Player[0].hp - 1 << "\n";
              }
              Player[0].hp--;
              Dead(0);
            }
          } else {
            if (debug) {
              cout << i << " hp " << Player[i].hp << " -> " << Player[i].hp - 1 << "\n";
            }
            Player[i].hp--;
            if (Dead(i)) {
              Player[0].card.clear(), Player[0].Z = 0;
            }
          }
        }
        return 1;
      }
    } else {
      if (Player[i].Show && Player[i].type != Player[x].type) {
        Player[x].Show = 1;
        if (!Wuxie(x, i))  {
          int win = dueling(x, i);
          if (win == x) {
            if (debug) {
              cout << i << " hp " << Player[i].hp << " -> " << Player[i].hp - 1 << "\n";
            }
            Player[i].hp--;
            if (Dead(i) && Player[i].type == "FP") {
              if (GameOver()) {
                return 1;
              }
              GetCard(x, 3);
            }
          } else {
            if (debug) {
              cout << x << " hp " << Player[x].hp << " -> " << Player[x].hp - 1 << "\n";
            }
            Player[x].hp--;
            if (Dead(x)) {
              if (Player[x].type == "FP") {
                if (GameOver()) {
                  return 1;
                }
                GetCard(i, 3);
              } else {
                if (!i) {
                  Player[0].card.clear(), Player[0].Z = 0;
                }
              }
            }
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

bool KillNan(int x) {
  int i = 0;
  for (char c : Player[x].card) {
    if (c == 'K') {
      Player[x].card[i] = 'A';
      if (debug) {
        cout << x << " KillNan\n";
      }
      return 1;
    }
    i++;
  }
  return 0;
}

void Nan(int x) {
  if (debug) {
    cout << x << " Nan\n";
  }
  fill(vis, vis + n, 0);
  vis[x] = 1;
  for (int i = Player[x].next; i != x && !GameOver(); i = Player[i].next) {
    if (!Wuxie(x, i)) {
      vis[i] = 1;
      if (!KillNan(i)) {
        if (debug) {
          cout << i << " hp " << Player[i].hp << " -> " << Player[i].hp - 1 << "\n";
        }
        Player[i].hp--;
        if (!i) {
          Player[x].Attack = 1;
        }
        if (Dead(i)) {
          if (GameOver()) {
            return;
          }
          if (Player[i].type == "FP") {
            GetCard(x, 3);
          }
          if (!x && Player[i].type == "ZP") {
            if (debug) {
              cout << x << " Clear Card\n";
            }
            Player[0].card.clear(), Player[0].Z = 0;
          }
        }
      }
    }
  }
}

void Wan(int x) {
  if (debug) {
    cout << x << " Wan\n";
  }
  fill(vis, vis + n, 0);
  vis[x] = 1;
  for (int i = Player[x].next; i != x && !GameOver(); i = Player[i].next) {
    if (!Wuxie(x, i)) {
      vis[i] = 1;
      if (!Duck(i)) {
        if (debug) {
          cout << i << " hp " << Player[i].hp << " -> " << Player[i].hp - 1 << "\n";
        }
        Player[i].hp--;
        if (!i) {
          Player[x].Attack = 1;
        }
        if (Dead(i)) {
          if (GameOver()) {
            return;
          }
          if (Player[i].type == "FP") {
            GetCard(x, 3);
          }
          if (!x && Player[i].type == "ZP") {
            if (debug) {
              cout << x << " Clear Card\n";
            }
            Player[0].card.clear(), Player[0].Z = 0;
          }
        }
      }
    }
  }
}

void Play(int x) {
  if (debug) {
    cout << x << " play card\n";
  }
  bool kill = 0;
  for (; ; ) {
    bool ok = 0;
    for (int i = 0; i < int(Player[x].card.size()); ++i) {
      char c = Player[x].card[i];
      if (c == 'P' && Player[x].hp < 4) {
        ok = 1, Peach(x);
        break;
      } else if (c == 'K' && (Player[x].Z || !kill) && Kill(x)) {
        ok = 1, Player[x].card[i] = 'A', kill = 1;
        break;
      } else if (c == 'F' && duel(x)) {
        ok = 1, Player[x].card[i] = 'A';
        break;
      } else if (c == 'N') {
        ok = 1, Player[x].card[i] = 'A', Nan(x);
        break;
      } else if (c == 'W') {
        ok = 1, Player[x].card[i] = 'A', Wan(x);
        break;
      } else if (c == 'Z') {
        if (debug) {
          cout << x << " ZhuGe\n";
        }
        ok = 1, Player[x].card[i] = 'A', Player[x].Z = 1;
        break;
      }
    }
    if (!ok || GameOver()) {
      break;
    }
  }
}

int main() {
  // freopen("P2482_10.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> Player[i].type;
    Player[i].type = (Player[i].type == "MP" ? "ZP" : Player[i].type);
    Player[i].hp = 4, Player[i].Show = !i;
    Player[i].prev = (i - 1 + n) % n, Player[i].next = (i + 1) % n;
    for (int j = 1; j <= 4; ++j) {
      char c;
      cin >> c;
      Player[i].card.emplace_back(c);
    }
  }
  for (int i = 1; i <= m; ++i) {
    char c;
    cin >> c;
    deck.emplace_back(c);
  }
  for (; !GameOver(); ) {
    for (int i = 0; i < n && !GameOver(); ++i) {
      if (Player[i].hp) {
        GetCard(i, 2);
        Play(i);
      }
    }
  }
  cout << (GameOver() == 1 ? "MP\n" : "FP\n");
  for (int i = 0; i < n; ++i) {
    if (!Player[i].hp) {
      cout << "DEAD\n";
      continue;
    }
    for (char &c : Player[i].card) {
      if (c == 'A') {
        continue;
      }
      cout << c << " ";
    }
    cout << "\n";
  }
  return 0;
}
/*
x Get Card X: x 获得牌 X
x play card: x 进入出牌阶段
x Died: x 死亡
0 Clear Card: 主公弃掉所有手牌
x Kill y: x 对 y 出杀
x Duck: x 闪
x y duel: x 对 y 决斗
x Attack: x 在决斗中出杀
x y duel end, x/y win: x 和 y 的决斗结束, x/y 获胜
x hp a -> (a - 1): x 的血量从 a 变成了 (a - 1)
x Eat Peach, hp a -> (a + 1): x 吃桃, 血量从 a 变成了 (a + 1)
x ZhuGe: x 装备猪哥连弩
x Wan: x 使用万箭齐发
x Nan: x 使用南猪入侵
x KillNan: x 用杀抵御南猪入侵
x Wuxie y's Wuxie: x 无懈可击了 y 的无懈可击
x Help y Wuxie z's Attack: x 帮 y 无懈可击了 z 的攻击
x Help y Wuxie z's Attack OK/NO: x 帮 y 无懈可击 z 的攻击成功/失败
(这里全部使用 0 下标)
*/