#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::Open(unsigned int num_lines, unsigned int num_columns)
{
	lines = num_lines;
	columns = num_columns;

	Board_Cells.resize(lines);

	for (int i = 0; i < lines; i++)
	{
		Board_Cells[i].resize(columns, '.');
	}
}

void Board::DefineIndexes() //this function exists only to indicate the indexes that surround the board to help the user
{
	indexes[0] = ' '; //the first position of the index is meant to not be seen

	for (size_t i = 1; i <= columns; i++)  // we first write the indexes of the columns (that appear on top of the board)
		indexes[i] = (char)((int)'a' + i - 1);

	for (size_t i = columns + 1; i <= lines; i++) //then, we add the indexes of the lines (that appear on the left side of the board)
		indexes[i] = (char)((int)'A' + i - 1);
}

void Board::ShowBoard() //this function displays the board to the user
{
	for (size_t i = 0; i <= columns; i++) //
		cout << indexes[i] << setw(2);

	for (size_t i = 0; i <= lines; i++)
	{
		cout << indexes[i + columns + 1] << setw(2);

		for (size_t k = 0; k < columns; k++)
			cout << Board_Cells[i][k] << setw(2);
	}
}