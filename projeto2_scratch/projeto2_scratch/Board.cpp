#include "Board.h"

Board::Board()
{
	_lines = 0;
	_columns = 0;
}

Board::~Board()
{
}

void Board::create(unsigned int lines, unsigned int columns)
{
	_lines = lines;
	_columns = columns;
	cells.resize(lines);

	for (int i = 0; i < cells.size(); i++)
	{
		cells[i].resize(columns, ".");
	}
}

void Board::show()
{
	for (int i = 0; i < cells.size(); i++)
	{
		for (int j = 0; j < cells[i].size(); j++)
		{
			cout << cells[i][j];
		}
		cout << endl;
	}
}