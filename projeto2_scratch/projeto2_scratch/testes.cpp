#include <iostream>
#include "Board.h"

int main()
{
	Board myBoard;
	unsigned int lines, columns;
	
	cout << "lines columns??"; cin >> lines >> columns;

	myBoard.Create(lines, columns);

	myBoard.Show();

	system("pause");
	return 0;
}