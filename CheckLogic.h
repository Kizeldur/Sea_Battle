#pragma once
#include <iostream>
using namespace std;

bool CheckForSym(char element, char sym) {
	if (element == sym) { return true; }
	return false;
}

bool CheckWin(char board[][11], int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			bool flag = CheckForSym(board[i][j], 'H');
			if (flag) {
				return false;
			}
		}
	}
	return true;
}

bool CheckHit(char board[][11], int size, int y, int x) {
	return CheckForSym(board[y][x], 'H');
}

bool CheckForBorder(char board[][11], int size, int* row, int* col) {
	if (*row == 1 || *row == 10 || *col == 1 || *col == 10) {
		return true;
	}
	return false;
}

int BorderOptionHorizontal(int* row, int* col) {
	if (*row == 1 || *row == 10 || *col == 1 || *col == 10) {
		return true;
	}
	else if (*row == 10) {

	}


}


/*
bool CheckHit(char board[][11], int size, int y, int x) {
	bool flag1 = CheckForSym(board[y][x], 'V');
	bool flag2 = CheckForSym(board[y][x], '>');
	if(flag1 || flag2){
		return true;
	}
	return false;
}
*/
bool CheckAlreadyStricken(char board[][11], int size, int y, int x) {
	return CheckForSym(board[y][x], 'X');
}

bool CheckKillHorizontal(char board[][11], int size, int y, int x) {
	int row = y, col = x;
	while (board[row][col] != '.' && col < 11) {
		if (CheckForSym(board[row][col], 'H')) {
			return false;
		}
		col++;
	}
	col = x;
	while (board[row][col] != '.' && col > 0) {
		if (CheckForSym(board[row][col], 'H')) {
			return false;
		}
		col--;
	}
	return true;
}

bool CheckKillVertical(char board[][11], int size, int y, int x) {
	int row = y, col = x;
	while (board[row][col] != '.' && row < 11) {
		if (CheckForSym(board[row][col], 'H')) {
			return false;
		}
		row++;
	}
	row = y;
	while (board[row][col] != '.' && row > 0) {
		if (CheckForSym(board[row][col], 'H')) {
			return false;
		}
		row--;
	}
	return true;
}

bool CheckVertical(char board[][11], int size, int y, int x) {
	bool flagUp = false, flagDown = false, flagUpHit = false, flagDownHit = false;

	if (y < 10) {
		flagUp = CheckForSym(board[y + 1][x], 'H');
		flagUpHit = CheckForSym(board[y + 1][x], 'X');
	}

	if (y > 1) {
		flagDown = CheckForSym(board[y - 1][x], 'H');
		flagDownHit = CheckForSym(board[y - 1][x], 'X');
	}

	if (flagUp || flagDown || flagUpHit || flagDownHit) {
		return true;
	}

	return false;
}

bool CheckHorizontal(char board[][11], int size, int y, int x) {
	bool flagLeft = false, flagRight = false, flagLeftHit = false, flagRightHit = false;

	if (x < 10) {
		flagRight = CheckForSym(board[y][x + 1], 'H');
		flagRightHit = CheckForSym(board[y][x + 1], 'X');
	}

	if (x > 1) {
		flagLeft = CheckForSym(board[y][x - 1], 'H');
		flagLeftHit = CheckForSym(board[y][x - 1], 'X');
	}

	if (flagRight || flagLeft || flagRightHit || flagLeftHit) {
		return true;
	}

	return false;
}

bool CheckKillOne(char board[][11], int size, int y, int x) {
	bool flagUp, flagDown, flagRight, flagLeft;

	if (y == 10) {
		flagUp = true;
	}
	else {
		flagUp = CheckForSym(board[y + 1][x], '.');
	}

	if (y == 1) {
		flagDown = true;
	}
	else {
		flagDown = CheckForSym(board[y - 1][x], '.');
	}

	if (x == 10) {
		flagRight = true;
	}
	else {
		flagRight = CheckForSym(board[y][x + 1], '.');
	}

	if (x == 1) {
		flagLeft = true;
	}
	else {
		flagLeft = CheckForSym(board[y][x - 1], '.');
	}

	if (flagUp && flagDown && flagRight && flagLeft) {
		return true;
	}
	return false;
}

int CheckKill(char board[][11], int size, int y, int x) {
	bool flagVertical = CheckVertical(board, size, y, x);
	bool flagHorizontal = CheckHorizontal(board, size, y, x);
	bool flagEmpty = CheckKillOne(board, size, y, x);

	if (flagVertical) {
		return CheckKillVertical(board, size, y, x);

	}
	else if (flagHorizontal) {
		return CheckKillHorizontal(board, size, y, x);

	}
	else if (flagEmpty) {
		return true;
	}
	else {
		return false;
	}
}

