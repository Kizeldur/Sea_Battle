#pragma once

//#include "UsefulFuncs.h"
#include "IO.h"
#include "CheckLogic.h"

void MoveShift(int* row, int* col, int* option) {
	switch (*option)
	{
	case 1:
		(*row)++;
		break;
	case 2:
		(*row)--;
		break;
	case 3:
		(*col)++;
		break;
	case 4:
		(*col)--;
		break;
	default:
		break;
	}
}

void GiveMeOption(int* row, int* col, int* option) {
	int opt_1 = 7;
	int opt_2 = 7;
	int opt_true;
	if (*row == 10) {
		opt_1 = 1;
	}
	else if (*row == 1) {
		opt_1 = 2;
	}
	if (*col == 10) {
		opt_2 = 3;
	}
	else if (*col == 1) {
		opt_2 = 4;
	}
	do {
		opt_true = RandomCoordinate(4);
	} while (opt_true == opt_1 || opt_true == opt_2);
		*option = opt_true;
}

void NextMoveLogic(char board[][11], int size, int* row, int* col, bool* hit, bool* hit_2, bool* hit_3, bool kill, int* option) {
	if ((!(*hit) && !(*hit_2) && !(*hit_3)) || kill) {
		*row = RandomCoordinate(10);
		*col = RandomCoordinate(10);
		if (CheckHit(board, size, *row, *col)) {
			*hit_2 = true;
		}
		else {
			*hit_2 = false;
		}
		*hit_3 = false;
	}
	else  if (*hit_2 && !kill) {
		//*option = RandomCoordinate(4);
		GiveMeOption(row, col, option);
		MoveShift(row, col, option);
		if (CheckHit(board, size, *row, *col)) {
			*hit_2 = false;
			*hit_3 = true;
		}
	}
	else if (*hit_3 && *hit && !kill) {
		MoveShift(row, col, option);
		*hit_3 = true;
	}
	else if (*hit_3 && !(*hit) && !kill) {
		if (*option == 1) {
			*option = 2;
		}
		else if (*option == 2) {
			*option = 1;
		}
		else if (*option == 3) {
			*option = 4;
		}
		else if (*option == 4) {
			*option = 3;
		}

		while (board[*row][*col] != 'H') {
			MoveShift(row, col, option);
		}
	}
	else {
		cout << "Error" << " - hit - " << *hit << " hit_2 - " << *hit_2 << endl;
	}
}

void NextMoveLogic_2(char board[][11], int size, int* row, int* col, bool* hit, bool* hit_2, bool* hit_3, bool kill, int* option) {
	if (kill) {
		*row = RandomCoordinate(10);
		*col = RandomCoordinate(10);
		if (CheckHit(board, size, *row, *col)) {
			*hit_2 = true;
		}
		else {
			*hit_2 = false;
		}
		*hit_3 = false;
	}
	else if ((!(*hit) && !(*hit_2)) && !(*hit_3)) {
		*row = 3;
		*col = 1;
		if (CheckHit(board, size, *row, *col)) {
			*hit_2 = true;
		}
		else {
			*hit_2 = false;
		}
		*hit_3 = false;
	}
	else if (*hit_3 && *hit && !kill) {
		MoveShift(row, col, option);
		*hit_3 = true;
	}
	else if (*hit_3 && !(*hit) && !kill) {
		if (*option == 1) {
			*option = 2;
		}
		else if (*option == 2) {
			*option = 1;
		}
		else if (*option == 3) {
			*option = 4;
		}
		else if (*option == 4) {
			*option = 3;
		}

		while (board[*row][*col] != 'H') {
			MoveShift(row, col, option);
		}
	}
	else  if (*hit_2 && !kill) {
		*option = RandomCoordinate(4);
		MoveShift(row, col, option);
		if (CheckHit(board, size, *row, *col)) {
			*hit_2 = false;
			*hit_3 = true;
		} 
	}
}
