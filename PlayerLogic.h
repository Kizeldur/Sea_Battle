#pragma once

#include <iostream>
#include "IO.h"
#include "CheckLogic.h"

using namespace std;

bool hit = false;
bool kill = false;
bool stricken = false;
//int row;
//int col;

void PlayerLogic(char board1T[][11], char board2T[][11], char board2F[][11], int size, bool* win1, int *row, int *col) {
	int rowBU = *row;
	int colBU = *col;

	cout << "Player 1" << endl;
	do {
		cout << "--------------------------" << endl;
		*row = ProperCoordinate();
		*col = ProperCoordinate();
		stricken = CheckAlreadyStricken(board2F, size, *row, *col);
		if (stricken) {
			cout << "Already Hit" << endl;
		}
	} while (stricken);
	hit = CheckHit(board2T, size, *row, *col);
	board2F[*row][*col] = 'X';
	if (hit) {
		board2T[*row][*col] = 'X';
		kill = CheckKill(board2T, size, *row, *col);
	}
	else {
		kill = false;
	}
	system("cls");
	cout << "Player 1" << endl;
	PrintTheInterface(board1T, board2F, size);
	ResultOfHit(kill, hit, *row, *col, rowBU, colBU);
	*win1 = CheckWin(board2T, size);
	cout << "End of the move" << endl << endl;
	cout << "--------------------------" << endl;
	system("pause");

}
 