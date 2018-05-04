#include "Board.h"

Board::Board()
{
}

Board::~Board()
{
}

void Board::DefineIndexes() //this function exists only to indicate the indexes that surround the board to help the user
{
	indexes.resize(lines + columns + 1);

	indexes[0] = ' '; //the first position of the index is meant to not be seen

	for (size_t i = 1; i <= columns; i++)  // we first write the indexes of the columns (that appear on top of the board)
		indexes[i] = (char)((int)'a' + i - 1);

	for (size_t i = columns + 1; i <= columns + lines; i++) //then, we add the indexes of the lines (that appear on the left side of the board)
		indexes[i] = (char)((int)'A' + (i - columns - 1));
}

void Board::DecodeLcd(unsigned int & l, unsigned int & c, unsigned int & d,const string & lcd)//decodes user input lcd (line column and direction) returning l and c as indexes and d as flag (1 - Vertical; 0 - Horizontal)
{
	l = ((int)lcd[0] - (int)'A');
	c = ((int)lcd[1] - (int)'a');
	if (lcd[2] == 'V')
		d = 1;
	else
		d = 0;
}

void Board::Create(unsigned int num_lines, unsigned int num_columns)
{
	lines = num_lines;
	columns = num_columns;

	Board_Cells.resize(lines);

	for (size_t i = 0; i < lines; i++)
	{
		Board_Cells[i].resize(columns, '.');
	}

	DefineIndexes();
}

void Board::Show() //this function displays the board to the user
{
	for (size_t i = 0; i <= columns; i++) //displays the first line with the indexes
		cout << setw(2) << indexes[i];

	cout << endl;

	for (size_t i = 0; i < lines; i++) //displays the rest of the board, including the indexes
	{
		cout << setw(2) << indexes[i + columns + 1];

		for (size_t k = 0; k < columns; k++)
			cout << setw(2) << Board_Cells[i][k];

		cout << endl;
	}
}

void Board::Insert(const string & lcd, const string & word) //this function inserts a word into the board
{
	unsigned int l, c, d; //respectively: line, column, direction in which the user input will be written

	DecodeLcd(l, c, d, lcd);

	if (d)				  //writing vertically
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			Board_Cells[l + i][c] = word[i];
		}
	}
	else
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			Board_Cells[l][c + i] = word[i];
		}
	}

}