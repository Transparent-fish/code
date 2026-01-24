#include <bits/stdc++.h>
using namespace std;

struct pig {
	int ID, Fl, hp, dead, zhuang;
	vector<char>card;
} a[15];
int n, m, leiF[15];
queue<char>cards;

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		a[i].dead = 0, a[i].hp = 4, a[i].zhuang = 0;
		string s;
		cin >> s;
		if (s == "MP")
			a[i].Fl = 1, a[i].ID = 0;
		else if (s == "FP")
			a[i].Fl = 0, a[i].ID = -1;
		else
			a[i].Fl = 0, a[i].ID = 1;
		for (int j = 0; j < 4; j++) {
			char c;
			cin >> c;
			a[i].card.emplace_back(c);
		}
	}
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;
		cards.push(c);
	}
}

void Print() {
	cout << (a[1].hp <= 0 ? "FP\n" : "MP\n");
	for (int i = 1; i <= n; i++) {
		if (a[i].hp <= 0) {
			cout << "DEAD\n";
			continue;
		}
		for (int j = 0; j < a[i].card.size(); j++)
			if (a[i].card[j] != 'U')
				cout << a[i].card[j] << " ";
		cout << "\n";
	}
}

void discard(int X, int Y) {
	a[X].card[Y] = 'U';
}

int Next(int X) {
	for (int i = X + 1;; i++) {
		if (i > n)
			i = 1;
		if (a[i].hp > 0)
			return i;
	}
}

int Ffind(int X, int Id) {
	for (int i = X + 1;; i++) {
		if (i > n)
			i = 1;
		if (i == X)
			return -1;
		if (a[i].hp > 0) {
			if (Id == 0) {
				if (leiF[i] || a[i].Fl < 0)
					return i;
			} else if (Id == 1) {
				if (a[i].Fl < 0)
					return i;
			} else if (Id == -1)
				if (a[i].Fl > 0)
					return i;
		}
	}
}

bool kcheck(int X) {
	for (int i = 0; i < a[X].card.size(); i++) {
		if (a[X].card[i] == 'D') {
			discard(X, i);
			return false;
		}
	}
	return true;
}

bool deadcheck(int X) {
	for (int i = 0; i < a[X].card.size(); i++) {
		if (a[X].card[i] == 'P') {
			discard(X, i);
			a[X].hp = 1;
			return false;
		}
	}
	return true;
}

bool Mwincheck() {
	for (int i = 1; i <= n; i++)
		if (a[i].ID == -1 && a[i].hp > 0)
			return false;
	return true;
}

int findJ(int X) {
	for (int i = 0; i < a[X].card.size(); i++) {
		if ((int)a[X].card[i] == (int)'J')
			return i;
	}
	return -1;
}

int findK(int X) {
	for (int i = 0; i < a[X].card.size(); i++)
		if (a[X].card[i] == 'K')
			return i;
	return -1;
}

int findD(int X) {
	for (int i = 0; i < a[X].card.size(); i++)
		if (a[X].card[i] == 'D')
			return i;
	return -1;
}

bool wxkjJ(int X) {
	bool Tmp = true;
	for (int i = X; ; i++) {
		if (i > n)
			i = 1;
		if ((i != X || Tmp) == false)
			break;
		if (a[i].hp <= 0)
			continue;
		if ((i == 1 && (a[X].Fl == -1 || leiF[X])) || (i != 1 && a[i].ID != a[X].Fl && a[X].Fl != 0)) {
			for (int j = 0; j < a[i].card.size(); j++) {
				if (a[i].card[j] == 'J') {
					a[i].card[j] = 'U', a[i].Fl = -a[X].Fl;
					if (i == 1)
						a[1].Fl = 1;
					if (wxkjJ(i))
						return false;
				}
			}
		}
		Tmp = false;
	}
	return true;
}

bool wxkj(int X, int Y) {
	bool Tmp = true;
	for (int i = X; ; i++) {
		if (i > n)
			i = 1;
		if ((i != X || Tmp) == false)
			break;
		if (a[i].hp <= 0)
			continue;
		if ((i == 1 && a[Y].Fl == 1) || (i != 1 && a[i].ID == a[Y].Fl)) {
			for (int j = 0; j < a[i].card.size(); j++) {
				if (a[i].card[j] == 'J') {
					a[i].card[j] = 'U', a[i].Fl = a[Y].Fl;
					if (wxkjJ(i))
						return true;
				}
			}
		}
		Tmp = false;
	}
	return false;

}

void diejudge(int X, int Y, bool &sha) {
	a[Y].dead = true;
	if (X != 1) {
		if (Y == 1 || Mwincheck()) {
			Print();
			exit(0);
		}
		if (a[Y].ID < 0) {
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
		}
	} else {
		if (Y == 1 || Mwincheck()) {
			Print();
			exit(0);
		}
		if (a[Y].ID > 0) {
			while (!a[X].card.empty())
				a[X].card.pop_back();
			a[X].zhuang = 0;
		} else {
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			a[X].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
		}
	}
}

void duel(int X, int Y) {
	while (1) {
		bool fl1 = true, fl2 = true;
		if (X == 1 && a[Y].ID == 1) {
			a[Y].hp--;
			if (a[Y].hp <= 0) {
				if (deadcheck(Y)) {
					a[Y].dead = true;
					diejudge(X, Y, fl1);
				}
			}
			return ;
		}
		for (int i = 0; i < a[Y].card.size(); i++) {
			if (a[Y].card[i] == 'K') {
				fl1 = false;
				discard(Y, i);
				break;
			}
		}
		if (fl1) {
			a[Y].hp--;
			if (a[Y].hp <= 0) {
				if (deadcheck(Y)) {
					a[Y].dead = true;
					diejudge(X, Y, fl1);
				}
			}
			return ;
		}
		for (int i = 0; i < a[X].card.size(); i++) {
			if (a[X].card[i] == 'K') {
				fl2 = false;
				discard(X, i);
				break;
			}
		}
		if (fl2) {
			a[X].hp--;
			if (a[X].hp <= 0) {
				if (deadcheck(X)) {
					a[X].dead = true;
					diejudge(Y, X, fl1);
				}
			}
			return ;
		}
	}
}

void Ncheck(int X) {
	bool TTmp;
	for (int i = X + 1;; i++) {
		if (i > n)
			i = 1;
		if (i == X)
			return ;
		if (a[i].hp > 0) {
			if (!wxkj(X, i)) {
				int K = findK(i);
				if (K >= 0)
					discard(i, K);
				else {
					a[i].hp--;
					if (a[i].hp <= 0) {
						if (deadcheck(i)) {
							a[i].dead = true;
							if (i == 1 || Mwincheck()) {
								Print();
								exit(0);
							}
							diejudge(X, i, TTmp);
						}
					}
					if (i == 1 && a[X].Fl == 0)
						leiF[X] = 1;
				}
			}
		}
	}
}

void Wcheck(int X) {
	bool TTmp;
	for (int i = X + 1;; i++) {
		if (i > n)
			i = 1;
		if (i == X)
			return ;
		if (a[i].hp > 0) {
			if (!wxkj(X, i)) {
				int D = findD(i);
				if (D >= 0)
					discard(i, D);
				else {
					a[i].hp--;
					if (a[i].hp <= 0) {
						if (deadcheck(i)) {
							a[i].dead = true;
							if (i == 1 || Mwincheck()) {
								Print();
								exit(0);
							}
							diejudge(X, i, TTmp);
						}
					}
					if (i == 1 && a[X].Fl == 0)
						leiF[X] = 1;
				}
			}
		}
	}
}

void kill(int i, int j, int Nxt, bool &sha) {
	if (a[i].ID == 0 && (a[Nxt].Fl < 0 || leiF[Nxt])) {
		discard(i, j);
		if (a[i].zhuang == 0)
			sha = true;
		if (kcheck(Nxt)) {
			a[Nxt].hp--;
			if (a[Nxt].hp <= 0) {
				if (deadcheck(Nxt)) {
					a[Nxt].dead = true;
					if (Nxt == 1 || Mwincheck()) {
						Print();
						exit(0);
					}
					diejudge(i, Nxt, sha);
				}
			}
		}
	} else if (a[i].ID == 1 && a[Nxt].Fl < 0) {
		discard(i, j);
		leiF[i] = 0, a[i].Fl = 1;
		if (a[i].zhuang == 0)
			sha = true;
		if (kcheck(Nxt)) {
			a[Nxt].hp--;
			if (a[Nxt].hp <= 0) {
				if (deadcheck(Nxt)) {
					a[Nxt].dead = true;
					if (Nxt == 1 || Mwincheck()) {
						Print();
						exit(0);
					}
					diejudge(i, Nxt, sha);
				}
			}
		}
	} else if (a[i].ID == -1 && a[Nxt].Fl > 0) {
		discard(i, j);
		a[i].Fl = -1;
		if (a[i].zhuang == 0)
			sha = true;
		if (kcheck(Nxt)) {
			a[Nxt].hp--;
			if (a[Nxt].hp <= 0) {
				if (deadcheck(Nxt)) {
					a[Nxt].dead = true;
					if (Nxt == 1 || Mwincheck()) {
						Print();
						exit(0);
					}
					diejudge(i, Nxt, sha);
				}
			}
		}
	}
}

void play() {
	while (1) {
		for (int i = 1; ; i++) {
			if (a[1].hp < 0 || Mwincheck()) {
				Print();
				return ;
			}
			if (a[i].dead)
				continue;
			if (i > n)
				i = 1;
			a[i].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			a[i].card.emplace_back(cards.front());
			if (cards.size() != 1)
				cards.pop();
			bool sha = false;
			while (1) {
				bool Fll = false;
				for (int j = 0; j < a[i].card.size(); j++) {
					int Nxt = Next(i);
					if (j < a[i].card.size() && a[i].card[j] == 'P' && a[i].hp != 4) {
						a[i].hp++;
						discard(i, j);
						Fll = true;
						break;
					} else if (j < a[i].card.size() && a[i].card[j] == 'K' && sha == false) {
						int XX = a[i].card.size();
						kill(i, j, Nxt, sha);
						if (a[i].card.size() != XX) {
							Fll = true;
							break;
						}
					} else if (j < a[i].card.size() && a[i].card[j] == 'Z') {
						a[i].zhuang = 1;
						discard(i, j);
						Fll = true;
						sha = false;
						for (int k = 0; k < a[i].card.size(); k++) {
							if (k < a[i].card.size() && a[i].card[k] == 'K') {
								int XX = a[i].card.size();
								kill(i, k, Nxt, sha);
								if (a[i].card.size() != XX)
									Fll = true;
							}
						}
						if (a[i].card.size() == 0)
							break;
						break;
					} else if (j < a[i].card.size() && a[i].card[j] == 'F') {
						int Find = Ffind(i, a[i].ID);
						if (a[i].ID < 0 && a[1].hp > 0)
							Find = 1;
						if (Find == -1)
							continue;
						discard(i, j);
						if (i != 1) {
							if (a[Find].Fl > 0)
								a[i].Fl = -1;
							else if (a[Find].Fl < 0)
								a[i].Fl = 1, leiF[i] = 0;
						}
						Fll = true;
						if (wxkj(i, Find) == false) {
							duel(i, Find);
							if (a[i].hp <= 0)
								break;
						}
						if (a[i].card.size() == 0)
							break;
						break;
					} else if (j < a[i].card.size() && a[i].card[j] == 'N') {
						discard(i, j);
						Fll = true;
						Ncheck(i);
						if (a[i].card.size() == 0)
							break;
						break;
					} else if (j < a[i].card.size() && a[i].card[j] == 'W') {
						discard(i, j);
						Fll = true;
						Wcheck(i);
						if (a[i].card.size() == 0)
							break;
						break;
					}
				}
				if (Fll == false || a[i].hp <= 0)
					break;
			}
		}
	}
}

int main() {
	init();
	play();
	return 0;
}