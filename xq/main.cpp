#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;
pair<int, int>a[100][100], zj[10000][15][15];
int x = 1, y = 1, now, xn, yn1, cnt2;
bool vis[100][100];
bool ai_enabled = false;
int ai_side = 0;
int ai_think_time = 500;
int ai_difficulty = 1;

string ss[] = {"  ", "  ", "  ", "兵", "炮", "帅", "仕", "相", "马", "車"};

string sss[] = {"  ", "  ", "  ", "卒", "炮", "将", "士", "象", "马", "車"};

int piece_value[10] = {0, 0, 0, 100, 400, 10000, 200, 200, 400, 900};

int nxt[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-1, -2}, {-2, -1}};

int nxtt[4][2] = {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}};

void color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setCursorPos(int x, int y) {
	COORD coord = {static_cast<SHORT>(y - 1), static_cast<SHORT>(x - 1)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool check(int b, int c, int xx, int yy, int xxx, int yyy, bool bypassTurnCheck = false) {
	if (!bypassTurnCheck) {
		if (now == 0 && c == 2) {
			return 0;
		} else if (now == 1 && c == 1) {
			return 0;
		}
	}
	if (b == 9) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (xx != xxx) {
			if (xx < xxx) {
				for (int i = xx + 1; i < xxx; i++) {
					if (a[i][yy].second != 0) {
						return 0;
					}
				}
			} else {
				for (int i = xxx + 1; i < xx; i++) {
					if (a[i][yy].second != 0) {
						return 0;
					}
				}
			}
		}
		if (yy != yyy) {
			if (yy < yyy) {
				for (int i = yy + 1; i < yyy; i++) {
					if (a[xx][i].second != 0) {
						return 0;
					}
				}
			} else {
				for (int i = yyy + 1; i < yy; i++) {
					if (a[xx][i].second != 0) {
						return 0;
					}
				}
			}
		}
	} else if (b == 8) {
		bool f = 0;
		for (int i = 0; i < 8; i++) {
			if (xx + nxt[i][0] == xxx && yy + nxt[i][1] == yyy) {
				f = 1;
			}
		}
		if (f == 0) {
			return 0;
		}
		if (xxx + 2 == xx) {
			if (a[xxx + 1][yyy].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx) {
			if (a[xxx - 1][yyy].second != 0) {
				return 0;
			}
		}
		if (yyy - 2 == yy) {
			if (a[xxx][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (yyy + 2 == yy) {
			if (a[xxx][yyy + 1].second != 0) {
				return 0;
			}
		}
	} else if (b == 7) {
		bool f = 0;
		for (int i = 0; i < 4; i++) {
			if (xx + nxtt[i][0] == xxx && yy + nxtt[i][1] == yyy) {
				f = 1;
			}
		}
		if (f == 0) {
			return 0;
		}
		if (xxx + 2 == xx && yyy + 2 == yy) {
			if (a[xxx + 1][yyy + 1].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx && yyy + 2 == yy) {
			if (a[xxx - 1][yyy + 1].second != 0) {
				return 0;
			}
		}
		if (xxx + 2 == xx && yyy - 2 == yy) {
			if (a[xxx + 1][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx && yyy - 2 == yy) {
			if (a[xxx - 1][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 6) {
				return 0;
			}
		} else {
			if (xx > 5) {
				return 0;
			}
		}
	} else if (b == 6) {
		if (abs(xx - xxx) > 1 || abs(yy - yyy) > 1) {
			return 0;
		}
		if (xx == xxx || yy == yyy) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 8) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
		}
		if (a[xxx][yyy].second == 1) {
			if (xx > 3) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
		}
	} else if (b == 5) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (abs(yy - yyy) > 1 || abs(xx - xxx) > 1) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 8) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
			for (int i = xx - 1; i >= 1; i--) {
				if (a[i][yy].second != 0) {
					if (a[i][yy].second == 1 && a[i][yy].first == 5) {
						return 0;
					} else {
						break;
					}
				}
			}
		}
		if (a[xxx][yyy].second == 1) {
			if (xx > 3) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
			for (int i = xx + 1; i <= 10; i++) {
				if (a[i][yy].second != 0) {
					if (a[i][yy].second == 2 && a[i][yy].first == 5) {
						return 0;
					} else {
						break;
					}
				}
			}
		}
	} else if (b == 4) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (a[xx][yy].second == 0) {
			if (xx != xxx) {
				if (xx < xxx) {
					for (int i = xx + 1; i < xxx; i++) {
						if (a[i][yy].second != 0) {
							return 0;
						}
					}
				} else {
					for (int i = xxx + 1; i < xx; i++) {
						if (a[i][yy].second != 0) {
							return 0;
						}
					}
				}
			}
			if (yy != yyy) {
				if (yy < yyy) {
					for (int i = yy + 1; i < yyy; i++) {
						if (a[xx][i].second != 0) {
							return 0;
						}
					}
				} else {
					for (int i = yyy + 1; i < yy; i++) {
						if (a[xx][i].second != 0) {
							return 0;
						}
					}
				}
			}
		} else {
			int cnt = 0;
			if (xx != xxx) {
				if (xx < xxx) {
					for (int i = xx + 1; i < xxx; i++) {
						if (a[i][yy].second != 0) {
							cnt++;
						}
					}
				} else {
					for (int i = xxx + 1; i < xx; i++) {
						if (a[i][yy].second != 0) {
							cnt++;
						}
					}
				}
			}
			if (yy != yyy) {
				if (yy < yyy) {
					for (int i = yy + 1; i < yyy; i++) {
						if (a[xx][i].second != 0) {
							cnt++;
						}
					}
				} else {
					for (int i = yyy + 1; i < yy; i++) {
						if (a[xx][i].second != 0) {
							cnt++;
						}
					}
				}
			}
			if (cnt != 1) {
				return 0;
			}
		}
	} else if (b == 3) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (abs(xx - xxx) > 1 || abs(yy - yyy) > 1) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx > xxx) {
				return 0;
			}
			if (xx > 5) {
				if (yy != yyy) {
					return 0;
				}
			}
		} else {
			if (xx < xxx) {
				return 0;
			}
			if (xx < 6) {
				if (yy != yyy) {
					return 0;
				}
			}
		}
	}
	int mx = 0, my = 0;
	for (int i = 1; i <= 10; i++) {
		if (a[i][yyy].first == 5) {
			mx = i;
			break;
		}
	}
	for (int i = 10; i >= 1; i--) {
		if (a[i][yyy].first == 5) {
			my = i;
			break;
		}
	}
	int cntt = 0, cnt1 = 0;
	for (int i = mx; i <= my; i++) {
		if (a[i][yyy].first == 5) {
			cnt1++;
			cntt++;
		} else if (a[i][yyy].first != 0) {
			cntt++;
		}
	}
	if (yy != yyy && cnt1 == 2 && cntt == 3) {
		if (yy != yyy && a[xxx][yyy].first == 5) {
			return 1;
		}
		return 0;
	}
	return 1;
}

void CurHide() {
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.dwSize = 1;
	curInfo.bVisible = FALSE;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &curInfo);
}

bool isGeneralThreatened(int side) {
	int generalX, generalY;
	bool found = false;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j].first == 5 && a[i][j].second == side) {
				generalX = i;
				generalY = j;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}
	if (!found)
		return false;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j].second != 0 && a[i][j].second != side) {
				if (check(a[i][j].first, a[generalX][generalY].second, generalX, generalY, i, j, true)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool hasAnyValidMove(int side) {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j].second == side) {
				for (int x2 = 1; x2 <= 10; x2++) {
					for (int y2 = 1; y2 <= 9; y2++) {
						int tempNow = now;
						if (side == 1)
							now = 1;
						else
							now = 0;
						if (check(a[i][j].first, a[x2][y2].second, x2, y2, i, j)) {
							pair<int, int>temp = a[x2][y2];
							a[x2][y2] = a[i][j];
							a[i][j] = make_pair(0, 0);
							bool stillInCheck = isGeneralThreatened(side);
							a[i][j] = a[x2][y2];
							a[x2][y2] = temp;
							now = tempNow;
							if (!stillInCheck) {
								return true;
							}
						} else {
							now = tempNow;
						}
					}
				}
			}
		}
	}
	return false;
}

bool isCheckmate(int side) {
	if (!isGeneralThreatened(side)) {
		return false;
	}
	return!hasAnyValidMove(side);
}

int evaluate() {
	int score = 0;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j].second != 0) {
				int value = piece_value[a[i][j].first];
				if (a[i][j].second == 2) {
					score += value;
				} else {
					score -= value;
				}
			}
		}
	}
	return score;
}

vector<tuple<int, int, int, int>>generateMoves(int side) {
	vector<tuple<int, int, int, int>>moves;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			if (a[i][j].second == side) {
				for (int x2 = 1; x2 <= 10; x2++) {
					for (int y2 = 1; y2 <= 9; y2++) {
						int tempNow = now;
						if (side == 1)
							now = 1;
						else
							now = 0;
						if (check(a[i][j].first, a[x2][y2].second, x2, y2, i, j)) {
							pair<int, int>temp = a[x2][y2];
							a[x2][y2] = a[i][j];
							a[i][j] = make_pair(0, 0);
							bool stillInCheck = isGeneralThreatened(side);
							a[i][j] = a[x2][y2];
							a[x2][y2] = temp;
							if (!stillInCheck) {
								moves.push_back(make_tuple(i, j, x2, y2));
							}
						}
						now = tempNow;
					}
				}
			}
		}
	}
	return moves;
}

int minimax(int depth, int alpha, int beta, bool maximizingPlayer, int side) {
	if (depth == 0) {
		return evaluate();
	}
	vector<tuple<int, int, int, int>>moves = generateMoves(maximizingPlayer ? side : (side == 2 ? 1 : 2));
	if (moves.empty()) {
		return evaluate();
	}
	if (maximizingPlayer) {
		int maxEval = -1000000;
		for (auto &move : moves) {
			int fromX = get<0>(move);
			int fromY = get<1>(move);
			int toX = get<2>(move);
			int toY = get<3>(move);
			pair<int, int>temp = a[toX][toY];
			a[toX][toY] = a[fromX][fromY];
			a[fromX][fromY] = make_pair(0, 0);
			bool stillInCheck = isGeneralThreatened(side);
			int eval;
			if (!stillInCheck) {
				eval = minimax(depth - 1, alpha, beta, false, side);
			} else {
				eval = -1000000;
			}
			a[fromX][fromY] = a[toX][toY];
			a[toX][toY] = temp;
			maxEval = max(maxEval, eval);
			alpha = max(alpha, eval);
			if (beta <= alpha) {
				break;
			}
		}
		return maxEval;
	} else {
		int minEval = 1000000;
		for (auto &move : moves) {
			int fromX = get<0>(move);
			int fromY = get<1>(move);
			int toX = get<2>(move);
			int toY = get<3>(move);
			pair<int, int>temp = a[toX][toY];
			a[toX][toY] = a[fromX][fromY];
			a[fromX][fromY] = make_pair(0, 0);
			bool stillInCheck = isGeneralThreatened(side == 2 ? 1 : 2);
			int eval;
			if (!stillInCheck) {
				eval = minimax(depth - 1, alpha, beta, true, side);
			} else {
				eval = 1000000;
			}
			a[fromX][fromY] = a[toX][toY];
			a[toX][toY] = temp;
			minEval = min(minEval, eval);
			beta = min(beta, eval);
			if (beta <= alpha) {
				break;
			}
		}
		return minEval;
	}
}

void out() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			setCursorPos(i, j * 2 - 1);
			if (i == xn && j == yn1) {
				if (a[i][j].second == 0) {
					if (vis[i][j] == 0)
						color(9 * 16 + 0);
					else
						color(9 * 16 + 10);
					cout << ". ";
					color(15);
				} else if (a[i][j].second == 2) {
					if (vis[i][j] == 0)
						color(9 * 16 + 4);
					else
						color(9 * 16 + 10);
					cout << ss[a[i][j].first];
					color(15);
				} else {
					if (vis[i][j] == 0)
						color(9 * 16 + 0);
					else
						color(9 * 16 + 10);
					cout << sss[a[i][j].first];
					color(15);
				}
			} else if (i == x && y == j) {
				if (a[i][j].second == 0) {
					if (vis[i][j] == 0)
						color(8 * 16 + 0);
					else
						color(8 * 16 + 10);
					cout << ". ";
					color(15);
				} else if (a[i][j].second == 2) {
					if (vis[i][j] == 0)
						color(8 * 16 + 4);
					else
						color(8 * 16 + 10);
					cout << ss[a[i][j].first];
					color(15);
				} else {
					if (vis[i][j] == 0)
						color(8 * 16 + 0);
					else
						color(8 * 16 + 10);
					cout << sss[a[i][j].first];
					color(15);
				}
			} else {
				if (a[i][j].second == 0) {
					if (vis[i][j] == 0)
						color(14 * 16 + 0);
					else
						color(14 * 16 + 10);
					cout << ". ";
					color(15);
				} else if (a[i][j].second == 2) {
					if (vis[i][j] == 0)
						color(14 * 16 + 4);
					else
						color(14 * 16 + 10);
					cout << ss[a[i][j].first];
					color(15);
				} else {
					if (vis[i][j] == 0)
						color(14 * 16 + 0);
					else
						color(14 * 16 + 10);
					cout << sss[a[i][j].first];
					color(15);
				}
			}
		}
		cout << endl;
	}
	setCursorPos(12, 1);
	cout << "                            ";
	setCursorPos(12, 1);
	if (ai_enabled) {
		string difficulty_names[] = {"", "简单", "中等", "困难"};
		string side_names[] = {"", "红方", "黑方"};
		cout << "AI: " << side_names[ai_side] << " 难度: " << difficulty_names[ai_difficulty];
	} else {
		cout << "AI: 关闭";
	}
	setCursorPos(13, 1);
	if (now == 0) {
		cout << "红方回合";
	} else {
		cout << "黑方回合";
	}
	if (isCheckmate(1)) {
		cout << "  黑方被绝杀！红方获胜！";
	} else if (isCheckmate(2)) {
		cout << "  红方被绝杀！黑方获胜！";
	} else if (isGeneralThreatened(1)) {
		cout << "  黑方被将军！";
	} else if (isGeneralThreatened(2)) {
		cout << "  红方被将军！";
	} else {
		cout << "                          ";
	}
	setCursorPos(14, 1);
	cout << "控制: WASD移动 N选择 M移动 O悔棋 I切换AI L切换难度";
}

void aiMakeMove() {
	int current_side;
	if (now == 0) {
		current_side = 2;
	} else {
		current_side = 1;
	}
	setCursorPos(15, 1);
	cout << "AI正在思考...          ";
	int search_depth;
	switch (ai_difficulty) {
		case 1:
			search_depth = 3;
			break;
		case 2:
			search_depth = 4;
			break;
		case 3:
			search_depth = 5;
			break;
		default:
			search_depth = 1;
	}
	vector<tuple<int, int, int, int>>moves = generateMoves(current_side);
	if (moves.empty()) {
		setCursorPos(17, 1);
		cout << "AI无棋可走            ";
		return;
	}
	int best_score = (current_side == 2) ? -1000000 : 1000000;
	tuple<int, int, int, int>best_move;
	srand(time(NULL));
	best_move = moves[rand() % moves.size()];
	for (auto &move : moves) {
		int fromX = get<0>(move);
		int fromY = get<1>(move);
		int toX = get<2>(move);
		int toY = get<3>(move);
		pair<int, int>temp = a[toX][toY];
		a[toX][toY] = a[fromX][fromY];
		a[fromX][fromY] = make_pair(0, 0);
		int score;
		if (ai_difficulty == 1) {
			score = evaluate();
			if (temp.first != 0) {
				score += (current_side == 2 ? 1 : -1) * piece_value[temp.first] * 2;
			}
			if (isGeneralThreatened(current_side == 2 ? 1 : 2)) {
				score += (current_side == 2 ? 1 : -1) * 500;
			}
		} else {
			score = minimax(search_depth - 1, -1000000, 1000000, false, current_side);
		}
		a[fromX][fromY] = a[toX][toY];
		a[toX][toY] = temp;
		if (current_side == 2) {
			if (score > best_score) {
				best_score = score;
				best_move = move;
			}
		} else {
			if (score < best_score) {
				best_score = score;
				best_move = move;
			}
		}
	}
	int fromX = get<0>(best_move);
	int fromY = get<1>(best_move);
	int toX = get<2>(best_move);
	int toY = get<3>(best_move);
	cnt2++;
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			zj[cnt2][i][j].first = a[i][j].first;
			zj[cnt2][i][j].second = a[i][j].second;
		}
	}
	a[toX][toY] = a[fromX][fromY];
	a[fromX][fromY] = make_pair(0, 0);
	xn = 0;
	yn1 = 0;
	memset(vis, 0, sizeof(vis));
	now = 1 - now;
	setCursorPos(15, 1);
	string difficulty_names[] = {"", "简单", "中等", "困难"};
	cout << "AI移动 (" << difficulty_names[ai_difficulty] << "): (" << fromX << "," << fromY << ")->(" << toX << "," << toY
	     << ")   ";
	out();
}

int huitu(int b, int c, int xx, int yy, int xxx, int yyy) {
	if (now == 0 && c == 2) {
		return 0;
	} else if (now == 1 && c == 1) {
		return 0;
	}
	if (b == 9) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (xx != xxx) {
			if (xx < xxx) {
				for (int i = xx + 1; i < xxx; i++) {
					if (a[i][yy].second != 0) {
						return 0;
					}
				}
			} else {
				for (int i = xxx + 1; i < xx; i++) {
					if (a[i][yy].second != 0) {
						return 0;
					}
				}
			}
		}
		if (yy != yyy) {
			if (yy < yyy) {
				for (int i = yy + 1; i < yyy; i++) {
					if (a[xx][i].second != 0) {
						return 0;
					}
				}
			} else {
				for (int i = yyy + 1; i < yy; i++) {
					if (a[xx][i].second != 0) {
						return 0;
					}
				}
			}
		}
	} else if (b == 8) {
		bool f = 0;
		for (int i = 0; i < 8; i++) {
			if (xx + nxt[i][0] == xxx && yy + nxt[i][1] == yyy) {
				f = 1;
			}
		}
		if (f == 0) {
			return 0;
		}
		if (xxx + 2 == xx) {
			if (a[xxx + 1][yyy].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx) {
			if (a[xxx - 1][yyy].second != 0) {
				return 0;
			}
		}
		if (yyy - 2 == yy) {
			if (a[xxx][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (yyy + 2 == yy) {
			if (a[xxx][yyy + 1].second != 0) {
				return 0;
			}
		}
	} else if (b == 7) {
		bool f = 0;
		for (int i = 0; i < 4; i++) {
			if (xx + nxtt[i][0] == xxx && yy + nxtt[i][1] == yyy) {
				f = 1;
			}
		}
		if (f == 0) {
			return 0;
		}
		if (xxx + 2 == xx && yyy + 2 == yy) {
			if (a[xxx + 1][yyy + 1].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx && yyy + 2 == yy) {
			if (a[xxx - 1][yyy + 1].second != 0) {
				return 0;
			}
		}
		if (xxx + 2 == xx && yyy - 2 == yy) {
			if (a[xxx + 1][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (xxx - 2 == xx && yyy - 2 == yy) {
			if (a[xxx - 1][yyy - 1].second != 0) {
				return 0;
			}
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 6) {
				return 0;
			}
		} else {
			if (xx > 5) {
				return 0;
			}
		}
	} else if (b == 6) {
		if (abs(xx - xxx) > 1 || abs(yy - yyy) > 1) {
			return 0;
		}
		if (xx == xxx || yy == yyy) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 8) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
		}
		if (a[xxx][yyy].second == 1) {
			if (xx > 3) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
		}
	} else if (b == 5) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (abs(yy - yyy) > 1 || abs(xx - xxx) > 1) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx < 8) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
			for (int i = xx - 1; i >= 1; i--) {
				if (a[i][yy].second != 0) {
					if (a[i][yy].second == 1 && a[i][yy].first == 5) {
						return 0;
					} else {
						break;
					}
				}
			}
		}
		if (a[xxx][yyy].second == 1) {
			if (xx > 3) {
				return 0;
			}
			if (yy < 4) {
				return 0;
			}
			if (yy > 6) {
				return 0;
			}
			for (int i = xx + 1; i <= 10; i++) {
				if (a[i][yy].second != 0) {
					if (a[i][yy].second == 2 && a[i][yy].first == 5) {
						return 0;
					} else {
						break;
					}
				}
			}
		}
	} else if (b == 4) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (a[xx][yy].second == 0) {
			if (xx != xxx) {
				if (xx < xxx) {
					for (int i = xx + 1; i < xxx; i++) {
						if (a[i][yy].second != 0) {
							return 0;
						}
					}
				} else {
					for (int i = xxx + 1; i < xx; i++) {
						if (a[i][yy].second != 0) {
							return 0;
						}
					}
				}
			}
			if (yy != yyy) {
				if (yy < yyy) {
					for (int i = yy + 1; i < yyy; i++) {
						if (a[xx][i].second != 0) {
							return 0;
						}
					}
				} else {
					for (int i = yyy + 1; i < yy; i++) {
						if (a[xx][i].second != 0) {
							return 0;
						}
					}
				}
			}
		} else {
			int cnt = 0;
			if (xx != xxx) {
				if (xx < xxx) {
					for (int i = xx + 1; i < xxx; i++) {
						if (a[i][yy].second != 0) {
							cnt++;
						}
					}
				} else {
					for (int i = xxx + 1; i < xx; i++) {
						if (a[i][yy].second != 0) {
							cnt++;
						}
					}
				}
			}
			if (yy != yyy) {
				if (yy < yyy) {
					for (int i = yy + 1; i < yyy; i++) {
						if (a[xx][i].second != 0) {
							cnt++;
						}
					}
				} else {
					for (int i = yyy + 1; i < yy; i++) {
						if (a[xx][i].second != 0) {
							cnt++;
						}
					}
				}
			}
			if (cnt != 1) {
				return 0;
			}
		}
	} else if (b == 3) {
		if (xx != xxx && yy != yyy) {
			return 0;
		}
		if (abs(xx - xxx) > 1 || abs(yy - yyy) > 1) {
			return 0;
		}
		if (a[xxx][yyy].second == 2) {
			if (xx > xxx) {
				return 0;
			}
			if (xx > 5) {
				if (yy != yyy) {
					return 0;
				}
			}
		} else {
			if (xx < xxx) {
				return 0;
			}
			if (xx < 6) {
				if (yy != yyy) {
					return 0;
				}
			}
		}
	}
	int mx = 0, my = 0;
	for (int i = 1; i <= 10; i++) {
		if (a[i][yyy].first == 5) {
			mx = i;
			break;
		}
	}
	for (int i = 10; i >= 1; i--) {
		if (a[i][yyy].first == 5) {
			my = i;
			break;
		}
	}
	int cntt = 0, cnt1 = 0;
	for (int i = mx; i <= my; i++) {
		if (a[i][yyy].first == 5) {
			cnt1++;
			cntt++;
		} else if (a[i][yyy].first != 0) {
			cntt++;
		}
	}
	if (yy != yyy && cnt1 == 2 && cntt == 3) {
		if (yy != yyy && a[xxx][yyy].first == 5) {
			vis[xx][yy] = 1;
			return 1;
		}
		return 0;
	}
	vis[xx][yy] = 1;
	return 0;
}

void ww(int tt) {
	if (tt == 1) {
		if (x > 1) {
			x--;
		} else {
			return;
		}
	}
	if (tt == 2) {
		if (x < 10) {
			x++;
		} else {
			return;
		}
	}
	if (tt == 3) {
		if (y > 1) {
			y--;
		} else {
			return;
		}
	}
	if (tt == 4) {
		if (y < 9) {
			y++;
		} else {
			return;
		}
	}
	int i = x, j = y;
	setCursorPos(i, j * 2 - 1);
	if (i == xn && j == yn1) {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(9 * 16 + 0);
			else
				color(9 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(9 * 16 + 4);
			else
				color(9 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(9 * 16 + 0);
			else
				color(9 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	} else if (i == x && y == j) {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(8 * 16 + 0);
			else
				color(8 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(8 * 16 + 4);
			else
				color(8 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(8 * 16 + 0);
			else
				color(8 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	} else {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(14 * 16 + 0);
			else
				color(14 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(14 * 16 + 4);
			else
				color(14 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(14 * 16 + 0);
			else
				color(14 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	}
	if (tt == 1) {
		i++;
	}
	if (tt == 2) {
		i--;
	}
	if (tt == 3) {
		j++;
	}
	if (tt == 4) {
		j--;
	}
	setCursorPos(i, j * 2 - 1);
	if (i == xn && j == yn1) {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(9 * 16 + 0);
			else
				color(9 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(9 * 16 + 4);
			else
				color(9 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(9 * 16 + 0);
			else
				color(9 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	} else if (i == x && y == j) {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(8 * 16 + 0);
			else
				color(8 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(8 * 16 + 4);
			else
				color(8 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(8 * 16 + 0);
			else
				color(8 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	} else {
		if (a[i][j].second == 0) {
			if (vis[i][j] == 0)
				color(14 * 16 + 0);
			else
				color(14 * 16 + 10);
			cout << ". ";
			color(15);
		} else if (a[i][j].second == 2) {
			if (vis[i][j] == 0)
				color(14 * 16 + 4);
			else
				color(14 * 16 + 10);
			cout << ss[a[i][j].first];
			color(15);
		} else {
			if (vis[i][j] == 0)
				color(14 * 16 + 0);
			else
				color(14 * 16 + 10);
			cout << sss[a[i][j].first];
			color(15);
		}
	}
	setCursorPos(13, 1);
	cout << "                ";
}


int main() {
	int bbxx = 0;
	CurHide();
	while (1) {
		system("cls");
		cout << "欢迎游玩中国象棋" << endl;
		cout << "按1：进入模式选择" << endl;
		cout << "按2：新手教程" << endl;
		cout << "按3：游戏介绍" << endl;
		cout << "按4：退出游戏" << endl;
		char pp;
		while (1) {
			pp = getch();
			if (pp != '1' && pp != '2' && pp != '3' && pp != '4') {
				continue;
			} else {
				if (pp == '1') {
					system("cls");
					cout << "请选择模式：" << endl;
					cout << "按1：传统象棋" << endl;
					cout << "按2：自己摆棋" << endl;
					cout << "按3：返回主界面" << endl;
					while (1) {
						pp = getch();
						if (pp == '1') {
							bbxx = 1;
							break;
						} else if (pp == '2') {
							bbxx = 2;
							break;
						} else if (pp == '3') {
							bbxx = 3;
							break;
						}
					}
					break;
				} else if (pp == '3') {
					system("cls");
					cout << "这是一个基于windowsAPI开发的c++游戏，是关于中国象棋的，并在其中引入了AI下棋的功能,拥有完整的规则判定（棋子移动规则，马别马脚，将不对帅等），可对将军，绝杀，送将等行为作出正确判定，";
					cout << "自带AI下棋功能，提供红黑方，不同难度等选项，并提供传统模式，和自己摆棋模式，玩法多样" << endl;
					cout << "为增加游玩体验：可将窗口放大，Win10，11，按住Ctrl通过鼠标滚轮放大，Win7右键窗口，属性，字体，来操作" << endl <<
					     endl;
					cout << "祝游玩愉快！！！" << endl << endl;
					cout << "按任意键退出" << endl;
					pp = getch();
					system("cls");
					cout << "欢迎游玩中国象棋" << endl;
					cout << "按1：进入模式选择" << endl;
					cout << "按2：新手教程" << endl;
					cout << "按3：游戏介绍" << endl;
					cout << "按4：退出游戏" << endl;
				} else if (pp == '4') {
					system("cls");
					cout << "是否退出：" << endl;
					cout << "按1：是" << endl;
					cout << "按2：不是" << endl;
					while (1) {
						pp = getch();
						if (pp == '1') {
							system("cls");
							cout << "欢迎下次游玩！！！" << endl;
							return 0;
						} else if (pp == '2') {
							system("cls");
							cout << "欢迎游玩中国象棋" << endl;
							cout << "按1：进入模式选择" << endl;
							cout << "按2：新手教程" << endl;
							cout << "按3：游戏介绍" << endl;
							cout << "按4：退出游戏" << endl;
							break;
						}
					}
				} else {
					system("cls");
					cout << "基础操作：" << endl;
					cout << "通过WSAD来移动棋盘上的光标" << endl;
					cout << "通过N来选中光标处的棋子，同时，那个地方会变蓝，并将可以移动的地方标记为绿色，再通过M来落下选中的棋子" << endl;
					cout << "按O来悔棋" << "      " << "注意：当前回合只能移动当前方的棋子" << endl << endl;
					cout << "AI方面操作：" << endl;
					cout << "通过按I来切换AI模式      按L来切换AI难度" << endl;
					cout << "AI操作帮助:如果要和红方AI下棋，就先按I，切换红方AI，再调整难度，最后再按O悔棋，等AI下棋就可以了，     AI操作帮助:如果要和黑方AI下棋，就先把自己的棋走好，再像红方AI一样操作"
					     << endl;
					cout << "注意：AI模式不支持在AI下棋时悔棋" << endl << endl;
					cout << "自己摆棋模式介绍：" << endl;
					cout << "在摆棋界面，通过3~9按键来切换棋子类型，通过K来切换阵营，M来放子，N删除子，准备好后，按G确认" << endl;
					cout << "注意：确认后将无法回到摆棋界面" << endl;
					cout << "棋子摆放注意：红方棋子摆放在棋盘下方，黑方棋子摆放在棋盘上方，帅将只能摆一个，士只能摆在九宫格内，相只能摆在河内，不然会出问题"
					     << endl << endl;
					cout << "祝游玩愉快！！！" << endl << endl;
					cout << "按任意键退出";
					pp = getch();
					system("cls");
					cout << "欢迎游玩中国象棋" << endl;
					cout << "按1：进入模式选择" << endl;
					cout << "按2：新手教程" << endl;
					cout << "按3：游戏介绍" << endl;
					cout << "按4：退出游戏" << endl;
				}
			}
		}
		if (bbxx == 1 || bbxx == 2) {
			break;
		}
	}
	if (bbxx == 2) {
		out();
		int no = 1, p = 5 + '0', xx = 1, yy = 1;
		setCursorPos(20, 1);
		cout << "当前棋子:";
		if (p == '9') {
			cout << "车";
		}
		if (p == '8') {
			cout << "马";
		}
		if (p == '7') {
			cout << "象";
		}
		if (p == '6') {
			cout << "士";
		}
		if (p == '5') {
			cout << "帅";
		}
		if (p == '4') {
			cout << "炮";
		}
		if (p == '3') {
			cout << "兵";
		}
		setCursorPos(21, 1);

		if (no == 1) {
			cout << "当前势力：黑";
		} else {
			cout << "当前势力：红";
		}
		while (1) {
			char op = getch();
			if (op >= '3' && op <= '9') {
				setCursorPos(20, 1);
				p = op ;
				cout << "当前棋子:";
				if (p == '9') {
					cout << "车";
				}
				if (p == '8') {
					cout << "马";
				}
				if (p == '7') {
					cout << "象";
				}
				if (p == '6') {
					cout << "士";
				}
				if (p == '5') {
					cout << "帅";
				}
				if (p == '4') {
					cout << "炮";
				}
				if (p == '3') {
					cout << "兵";
				}
			}
			if (op == 'k') {
				setCursorPos(21, 1);
				if (no == 2) {
					no = 1;
				} else {
					no = 2;
				}
				if (no == 1) {
					cout << "当前势力：黑";
				} else {
					cout << "当前势力：红";
				}
			}
			if (op == 'm') {
				a[x][y].first = p - '0';
				a[x][y].second = no;
				out();
			}
			if (op == 'n') {
				a[x][y].first = 0;
				a[x][y].second = 0;
				out();
			}
			if (op == 'w') {
				ww(1);
			}
			if (op == 's') {
				ww(2);
			}
			if (op == 'a') {
				ww(3);
			}
			if (op == 'd') {
				ww(4);
			}
			if (op == 'g') {
				setCursorPos(20, 1);
				cout << "                   ";
				setCursorPos(21, 1);
				cout << "                   ";
				break;
			}
		}
	} else {
		a[1][1].first = 9;
		a[1][2].first = 8;
		a[1][3].first = 7;
		a[1][4].first = 6;
		a[1][5].first = 5;
		a[1][6].first = 6;
		a[1][7].first = 7;
		a[1][8].first = 8;
		a[1][9].first = 9;
		a[3][2].first = 4;
		a[3][8].first = 4;
		a[4][1].first = 3;
		a[4][3].first = 3;
		a[4][5].first = 3;
		a[4][7].first = 3;
		a[4][9].first = 3;
		a[1][1].second = 1;
		a[1][2].second = 1;
		a[1][3].second = 1;
		a[1][4].second = 1;
		a[1][5].second = 1;
		a[1][6].second = 1;
		a[1][7].second = 1;
		a[1][8].second = 1;
		a[1][9].second = 1;
		a[3][2].second = 1;
		a[3][8].second = 1;
		a[4][1].second = 1;
		a[4][3].second = 1;
		a[4][7].second = 1;
		a[4][9].second = 1;
		a[10][1].first = 9;
		a[4][5].second = 1;
		a[10][3].first = 7;
		a[10][2].first = 8;
		a[10][4].first = 6;
		a[10][5].first = 5;
		a[8][2].first = 4;
		a[8][8].first = 4;
		a[7][1].first = 3;
		a[7][3].first = 3;
		a[7][5].first = 3;
		a[10][6].first = 6;
		a[10][7].first = 7;
		a[10][8].first = 8;
		a[10][9].first = 9;
		a[7][7].first = 3;
		a[7][9].first = 3;
		a[10][1].second = 2;
		a[10][2].second = 2;
		a[10][3].second = 2;
		a[10][4].second = 2;
		a[10][5].second = 2;
		a[10][6].second = 2;
		a[10][7].second = 2;
		a[10][8].second = 2;
		a[10][9].second = 2;
		a[8][2].second = 2;
		a[8][8].second = 2;
		a[7][1].second = 2;
		a[7][3].second = 2;
		a[7][5].second = 2;
		a[7][7].second = 2;
		a[7][9].second = 2;
	}
	out();
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			zj[cnt2][i][j].first = a[i][j].first;
			zj[cnt2][i][j].second = a[i][j].second;
		}
	}
	setCursorPos(15, 1);
	cout << "按I键切换AI模式 L键切换难度 (当前: 双人对战)";
	while (1) {
		if (ai_enabled) {
			if ((ai_side == 1 && now == 0) || (ai_side == 2 && now == 1)) {
				aiMakeMove();
				continue;
			}
		}
		char op = getch();
		if (op == 'w' || op == 'W') {
			ww(1);
		} else if (op == 's' || op == 'S') {
			ww(2);
		} else if (op == 'a' || op == 'A') {
			ww(3);
		} else if (op == 'd' || op == 'D') {
			ww(4);
		} else if (op == 'n' || op == 'N') {
			if (now == 0) {
				if (a[x][y].second != 2) {
					continue;
				} else {
					memset(vis, 0, sizeof(vis));
					xn = x, yn1 = y;
					for (int i = 1; i <= 10; i++) {
						for (int j = 1; j <= 9; j++) {
							huitu(a[xn][yn1].first, a[i][j].second, i, j, xn, yn1);
						}
					}
					out();
				}
			} else {
				if (a[x][y].second != 1) {
					continue;
				} else {
					memset(vis, 0, sizeof(vis));
					xn = x, yn1 = y;
					for (int i = 1; i <= 10; i++) {
						for (int j = 1; j <= 9; j++) {
							huitu(a[xn][yn1].first, a[i][j].second, i, j, xn, yn1);
						}
					}
					out();
				}
			}
		} else if (op == 'm' || op == 'M') {
			if (xn == 0) {
				continue;
			}
			if (check(a[xn][yn1].first, a[x][y].second, x, y, xn, yn1)) {
				memset(vis, 0, sizeof(vis));
				if (!isCheckmate(1) && !isCheckmate(2)) {
					int xxxx = a[x][y].first;
					int yyyy = a[x][y].second;
					a[x][y].first = a[xn][yn1].first;
					a[x][y].second = a[xn][yn1].second;
					a[xn][yn1].first = 0;
					a[xn][yn1].second = 0;
					if (now == 1) {
						if (isGeneralThreatened(1)) {
							a[xn][yn1].first = a[x][y].first;
							a[xn][yn1].second = a[x][y].second;
							a[x][y].first = xxxx;
							a[x][y].second = yyyy;
							for (int i = 1; i <= 10; i++) {
								for (int j = 1; j <= 9; j++) {
									huitu(a[xn][yn1].first, a[i][j].second, i, j, xn, yn1);
								}
							}
							out();
							cout << "不能送将，请变招";
							continue;
						} else {
							xn = 0;
							yn1 = 0;
							now = 1 - now;
							out();
							cout << "                  ";
						}
					} else {
						if (isGeneralThreatened(2)) {
							a[xn][yn1].first = a[x][y].first;
							a[xn][yn1].second = a[x][y].second;
							a[x][y].first = xxxx;
							a[x][y].second = yyyy;
							for (int i = 1; i <= 10; i++) {
								for (int j = 1; j <= 9; j++) {
									huitu(a[xn][yn1].first, a[i][j].second, i, j, xn, yn1);
								}
							}
							out();
							cout << "不能送将，请变招";
							continue;
						} else {
							xn = 0;
							yn1 = 0;
							now = 1 - now;
							out();
							cout << "                  ";
						}
					}
				} else {
					xn = 0;
					yn1 = 0;
					out();
					continue;
				}
				cnt2++;
				for (int i = 1; i <= 10; i++) {
					for (int j = 1; j <= 9; j++) {
						zj[cnt2][i][j].first = a[i][j].first;
						zj[cnt2][i][j].second = a[i][j].second;
					}
				}
			}
		} else if (op == 'o' || op == 'O') {
			if (cnt2 != 0) {
				memset(vis, 0, sizeof(vis));
				xn = 0;
				yn1 = 0;
				cnt2--;
				for (int i = 1; i <= 10; i++) {
					for (int j = 1; j <= 9; j++) {
						a[i][j].first = zj[cnt2][i][j].first;
						a[i][j].second = zj[cnt2][i][j].second;
					}
				}
				now = 1 - now;
				out();
			}
		} else if (op == 'i' || op == 'I') {
			if (!ai_enabled) {
				ai_enabled = true;
				ai_side = 1;
				setCursorPos(15, 1);
				cout << "AI已启用 (控制红方,难度:简单) 按I切换 L切换难度";
			} else {
				if (ai_side == 1) {
					ai_side = 2;
					setCursorPos(15, 1);
					string difficulty_names[] = {"", "简单", "中等", "困难"};
					cout << "AI已启用 (控制黑方,难度:" << difficulty_names[ai_difficulty] << ") 按I切换 L切换难度";
				} else if (ai_side == 2) {
					ai_side = 0;
					ai_enabled = false;
					setCursorPos(15, 1);
					cout << "AI已关闭 (双人对战) 按I开启";
				}
			}
			out();
		} else if (op == 'l' || op == 'L') {
			ai_difficulty++;
			if (ai_difficulty > 3) {
				ai_difficulty = 1;
			}
			string difficulty_names[] = {"", "简单", "中等", "困难"};
			setCursorPos(18, 1);
			string side_names[] = {"", "红方", "黑方"};
			cout << "AI难度已切换为" << difficulty_names[ai_difficulty] << " (控制" << side_names[ai_side] << ")";
			out();
		}
		setCursorPos(13, 1);
		if (now == 0) {
			cout << "红方回合";
		} else {
			cout << "黑方回合";
		}
	}
	return 0;
}