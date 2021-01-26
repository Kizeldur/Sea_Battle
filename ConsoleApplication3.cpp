#include <iostream>
#include "BoardLogic.h"
#include "PlayerLogic.h"
#include "ComputerLogic.h"
#include <ctime>
#include <stdlib.h>

using namespace std;


int main()
{
	//srand(time(NULL));
	srand(4);
	// Flags
	bool win_1 = false, win_2 = false;
	bool kill = false, hit = false, striken = false;
	bool hit_2 = false;
	bool hit_3 = false;

	// Board Size
	const int SIZE = 11;

	// Boards
	char board_Pl1T[SIZE][SIZE], board_Pl1F[SIZE][SIZE];
	char board_Pl2T[SIZE][SIZE], board_Pl2F[SIZE][SIZE];

	// Coordinates and counters
	int row, col;
	int row_1, col_1;
	int var;
	int count = 0;

	// Symbols
	int symLive = 'H';
	int symHit = 'X';
	int symDead = 'K';

	// Option
	int option;

	//Symbol for end of move
	char sym;

	// Creating boards
	cout << "Creating boards:\n\n";
	CreateMap(board_Pl1T);
	CopyTheBoard(board_Pl1T, board_Pl1F, SIZE);
	CreateMap(board_Pl2T);
	CreateMap(board_Pl2F);
	cout << "Done" << endl;

	// Putting ships
	cout << "Choose The Option:\n1 - Place The Ships Youself;\n2 - Place The Ships Automaticly" << endl;
	cin >> option;
	switch (option) {
	case 1:
		FillTheBoard(board_Pl1T);
		cout << "Done" << endl;
		break;
	case 2:
		cout << "Creating Player Board...\n";
		FillTheBoardAutomaticly(board_Pl1T);
		cout << "Done" << endl;
		break;
	}

	cout << "Creating Computers Board...\n";
	FillTheBoardAutomaticly(board_Pl2T);
	cout << "Done" << endl;
	PrintTheInterface(board_Pl1T, board_Pl2F, SIZE);
	cout << "Press Any Key To Start The Game" << endl;
	system("pause");
	system("cls");
	cout << endl << "Start Of The Game" << endl;
	PrintTheInterface(board_Pl1T, board_Pl2F, SIZE);
	//Game cycle
	while (!win_1 && !win_2)
	{
	//	PlayerLogic(board_Pl1T, board_Pl2T, board_Pl2F, SIZE, &win_1, &row_1, &col_1);

		ComputerLogic(board_Pl1T, board_Pl1F, board_Pl2T, board_Pl2F, SIZE, &win_2, &row, &col, &hit, &hit_2, &hit_3, &kill, &option);
	}

	PrintWin(win_1, win_2);

	cin >> row;

}

// TODO Логика компьютера условия кораблей около границ
// Интерфейс
// 