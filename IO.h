#pragma once
#include<iostream>
#include "CheckLogic.h"
//#include "UsefulFuncs.h"

using namespace std;

int InputCoordinate() {
	int coordinet;
	cout << "Enter Coordinate 1 to 10";
	cin >> coordinet;
	return coordinet;
}

int ProperCoordinate() {
	int coordinate;
	do {
		coordinate = InputCoordinate();
	} while (coordinate < 1 || coordinate >= 11);
	return coordinate;
}


int RandomCoordinate(int num) {
	int coordinate = 1 + rand() % num;
	return coordinate;
}

int ProperCoordinateComp(int num) {
	int coordinate;
	do {
		coordinate = RandomCoordinate(num);
	} while (coordinate < 1 || coordinate >= 11);
	return coordinate;
}

void PrintBoard(char board[][11], int size) {
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size; b++) {
			cout << board[a][b] << "\t";
		}
		cout << endl;
	}
}

void ResultOfHit(bool kill, bool hit, int row, int col, int rowPr, int colPr) {
	cout << "Previous cell - " << rowPr << "-" << colPr << endl;
	if (kill) {
		cout << row << "-" << col << " - Killed" << endl;
	}
	else if (hit) {
		cout << row << "-" << col << " - Hit" << endl;
	}
	else {
		cout << row << "-" << col << " - Missed" << endl;
	}
}

void PrintWin(bool win1, bool win2) {
	if (win1) {
		cout << "You Win" << endl;

	}
	else if (win2) {
		cout << "Computer Wins" << endl;
	}
}

void RightHit(char board[][11], int size, bool kill, int row, int col) {
	bool flagVertical = CheckVertical(board, size, row, col);
	bool flagHorizontal = CheckHorizontal(board, size, row, col);

	if (kill && flagVertical) {
		// KillFucntion
		int y = row, x = col;
		while (board[y][x] != ' ') {
			board[y][x] = 'K';
			y++;
		}
		y = row;
		while (board[y][x] != ' ') {
			board[y][x] = 'K';
			y--;
		}
	}
	else if (kill && flagHorizontal) {
		int y = row, x = col;
		while (board[y][x] != ' ') {
			board[y][x] = 'K';
			x++;
		}
		x = row;
		while (board[y][x] != ' ') {
			board[y][x] = 'K';
			x--;
		}
	}
	else {
		board[row][col] = 'W';
	}
}

void PrintTheInterface(char board_Pl1T[][11], char board_Pl2F[][11], int SIZE) {
	cout << "Computer's board" << endl;
	PrintBoard(board_Pl2F, SIZE);
	cout << endl;
	cout << "Your Board" << endl << endl;
	PrintBoard(board_Pl1T, SIZE);
	cout << "--------------------------" << endl;
}
