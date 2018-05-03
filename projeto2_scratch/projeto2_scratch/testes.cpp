#include <iostream>
#include "Board.h"

int main()
{
	Board gameBoard;
	unsigned int lines, columns;
	cout << "Lines Columns"; cin >> lines >> columns;

	gameBoard.create(lines, columns);
	gameBoard.show();

	system("pause");
	return 0;
}