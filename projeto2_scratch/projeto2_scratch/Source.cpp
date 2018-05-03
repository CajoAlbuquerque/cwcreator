#include <iostream>
#include "Dictionary.h"
#include "Board.h"

void ProgramInterface(Dictionary &dictionary, Board &board)
{
	int option;

	cout << "CROSSWORDS PUZZLE CREATOR" << endl
		<< "============================================" << endl << endl
		<< "INSTRUCTIONS:" << endl
		<< "Position( LCD / CTRL + Z = stop )" << endl
		<< " LCD stands for Line Column and Direction" << endl << endl
		<< "--------------------------------------------" << endl;

	while (true)
	{
		cout << "Options:" << endl
			<< "1 - Create Puzzle" << endl
			<< "2 - Resume Puzzle" << endl
			<< "0 - Exit" << endl
			<< "Option ? ";

		cin >> option;

		while (cin.fail() || option < 0 || option > 2) //only  allowed to move forward when the user writes a valid input
		{
			cerr << "Invalid input. Choose an option from the menu!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> option;

			if (cin.eof())
				exit(0);
		}

		switch (option)
		{
		case 0: exit(0);
		case 1:
			dictionary.Open();
			dictionary.show();
			break;
		case 2:
			break;
		}
	}
}

int main()
{
	Dictionary dictionary;
	Board board;

	ProgramInterface(dictionary, board);

	system("pause");

	return 0;
}