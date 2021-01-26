#pragma once

#include <iostream>
#include "IO.h"
#include"ComputerNextMoveLogic.h"


using namespace std;



void ComputerLogic(char board1T[][11], char board1F[][11], char board2T[][11], char board2F[][11], int size, bool* win2, int* row, int* col, bool* hit, bool* hit_2, bool* hit_3, bool* kill, int* option) {
	int rowBU = *row;
	int colBU = *col;
	
	bool stricken = false;

	do {
		do {
			NextMoveLogic(board1T, size, row, col, hit, hit_2, hit_3, *kill, option);
		} while (*row < 1 || *row >= 11 || *col < 1 || *col >= 11);
		stricken = CheckAlreadyStricken(board1T, size, *row, *col);
	} while (stricken);

	*hit = CheckHit(board1T, size, *row, *col);
	board1T[*row][*col] = 'X';
	if (*hit) {
		board1F[*row][*col] = 'X';
		*kill = CheckKill(board1T, size, *row, *col);
	}
	else {
		*kill = false;
	}

	system("cls");
	cout << "Player 2" << endl;
	cout << "--------------------------" << endl;
	PrintTheInterface(board1T, board2F, size);
	ResultOfHit(*kill, *hit, *row, *col, rowBU, colBU);

	if (!(*hit)) {
		*row = rowBU;
		*col = colBU;
	}
	*win2 = CheckWin(board1T, size);
	cout << "End of the move" << endl << endl;
	cout << "--------------------------" << endl;
	system("pause");
}
