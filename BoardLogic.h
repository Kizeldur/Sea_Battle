#pragma once

#include <iostream>
#include "IO.h"

using namespace std;

const int SIZE = 11;


//Function creates maps
void CreateMap(char arr[][SIZE])
{
	char letters[SIZE - 1] = { 'A','B','C','D','E','F','G','H','I','J' };
	char digits[SIZE - 1] = { '1','2','3','4','5','6','7','8','9','0' };
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == 0 && j > 0) {
				arr[i][j] = digits[j - 1];
			}
			else if (i > 0 && j == 0) {
				arr[i][j] = digits[i - 1];
			}
			else {
				arr[i][j] = '.';
			}
		}
	}
	arr[0][0] = '+';
	arr[10][0] = '0';
}


// Function for placing ships
void PlantSomeShips(char arr[][SIZE], int shipLen, int row, int col, int var)
{
	if (var == 1)
	{

		for (int i = 0; i < shipLen; i++) {

			arr[row + i][col] = 'H';
		}
	}
	else if (var == 2)
	{

		for (int i = 0; i < shipLen; i++) {

			arr[row][col + i] = 'H';
		}
	}
}

//Function that does some shit
void InputArr(char arr[][SIZE], int shipLen, int row, int col, int var, int* count)
{
	if (var == 1)
	{
		bool flag = true;

		if (row + shipLen - 1 > SIZE - 1) {
			flag = false;
		}
		if (flag) {
			for (int i = row - 1; i < row + shipLen + 1; i++) {
				for (int j = col - 1; j < col + 2; j++) {
					if (arr[i][j] == 'H') {
						flag = false;
					}

				}

			}
		}
		if (flag) {
			PlantSomeShips(arr, shipLen, row, col, 1);
			*count += 1;
		}
	}
	else if (var == 2) {
		bool flag = true;
		if (col + shipLen - 1 > SIZE - 1) {
			flag = false;
		}

		if (flag) {
			for (int i = row - 1; i < row + 2; i++) {
				for (int j = col - 1; j < col + shipLen + 1; j++) {
					if (arr[i][j] == 'H') {
						flag = false;
					}
				}
			}
		}

		if (flag) {
			PlantSomeShips(arr, shipLen, row, col, 2);
			*count = *count + 1;
		}
	}
	else cout << "\n\nWrong Option.\n\n";
}

void FillTheBoardAutomaticly(char board[][SIZE]) {
	int count = 0;
	int row, col;
	int var;

	for (int shipLen = 1; shipLen < 5; shipLen++)
	{
		do
		{
			row = RandomCoordinate(10);
			col = RandomCoordinate(10);
			var = RandomCoordinate(2);

			InputArr(board, shipLen, row, col, var, &count);
		} while (count != 5 - shipLen);
		count = 0;
	}
}

void FillTheBoard(char board[][SIZE]) {
	int count = 0;
	int row, col; int var = rand() % 2 + 1;
	for (int shipLen = 1; shipLen < 5; shipLen++)
	{
		do
		{
			cout << "Your Board" << endl;
			PrintBoard(board, SIZE);
			cout << "\n\nEnter Coordinates Of " << shipLen << "-deck Ship: (1:10, Row/Collumn)\n\n";
			row = InputCoordinate();
			col = InputCoordinate();
			if (shipLen > 1)
			{
				cout << "\n\nPositioning Of The Ship?\n\n\n1.Vertical;\n\n2.Horizontal\n\n";
				cin >> var;
			}
			InputArr(board, shipLen, row, col, var, &count);
		} while (count != 5 - shipLen);

		count = 0;
	}
}

void CopyTheBoard(char board1T[][11], char board1F[][11], int size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			board1F[i][j] = board1T[i][j];
		}
	}
}
