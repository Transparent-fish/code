//处理牌用过没，用双端队列，这样能当数组用，也能 pop_front 和 push_back
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
const int M = 1e6 + 5;
int n, m;
int MP_id, FP_cnt;
char stack_card[N];
deque<char> cards;

struct node {
    int hp = 4;
    bool zgln = 0; //有无猪哥连弩 0没有 1有
    bool dead = 0; //死了没 0没 1死了
    bool leifan = 0;//是否被主猪认为类反猪
    bool vis[N];//标记 i 这张牌用了没 0没  1用了
    bool xxq, bqy, jump_z, jump_f;
    string name;
    deque<char> card;
} a[N];

void init() {
    /*Read Start*/
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].name;
        if (a[i].name == "MP") MP_id = i;
        if (a[i].name == "FP") FP_cnt++;
        for (int j = 1; j <= 4; j++) {
            char op;
            cin >> op;
            a[i].card.push_back(op);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> stack_card[i];
        cards.push_back(stack_card[i]);
    }
    /*Read End*/
}

/*游戏逻辑 Start*/

void Print() {//输出
    cout << (a[1].hp <= 0 ? "FP\n" : "MP\n");
    for (int i = 1; i <= n; i++) {
        if (a[i].hp <= 0) {
            cout << "DEAD\n";
            continue;
        }
        for (int j = 0; j < a[i].card.size(); j++) {
            if (a[i].card[j] != 'U') {
                cout << a[i].card[j] << " ";
            }
        }
        cout << "\n";
    }
}

bool game_end() {
    if (a[1].dead == 1 || FP_cnt <= 0) {
        Print();
        return 1;
    }
    return 0;
}

void draw(int id) {//拉牌
    for (int i = 1; i <= 2; i++) {
        if (cards.empty()) continue;
        a[id].card.push_back(cards.front());
        cards.pop_front();
    }
}

void Eet_p(int i) {//吃桃
    for (;a[i].hp < 4;) {
        bool vis = 0;
        for (auto it = a[i].card.begin();it != a[i].card.end();it++) {
            if (*it == 'P') {
                a[i].hp++;
                a[i].card.erase(it);
                vis = 1;
                break;
            }
        }
        if (!vis)break;
    }
}

void Use_nzrq(int i) {
    for(;;){
        
    }
}

/*游戏逻辑 End*/

//游戏主体
void game() {
    int now_pig = 1; //现在到谁出牌
    for (; game_end() != 1;) {
        //拉牌
        draw(now_pig);
        //出牌

        //吃桃
        Eet_p(now_pig);
    }
}


signed main() {
    init();
    game();
    return 0;
}