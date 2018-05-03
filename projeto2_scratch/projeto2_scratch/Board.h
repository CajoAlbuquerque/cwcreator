#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Board
{
public:
	Board();
	~Board();
	void Open(unsigned int num_lines, unsigned int num_columns);
	void DefineIndexes();
	void ShowBoard();

private:
	unsigned int lines;
	unsigned int columns;
	vector < vector < char > > Board_Cells;
	vector <char> indexes;
};

#endif