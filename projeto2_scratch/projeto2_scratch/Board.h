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
	void Create(unsigned int num_lines, unsigned int num_columns);
	void Insert(string lcd, string userWord);
	void Remove(string lcd);
	void Show();

private:
	unsigned int lines;
	unsigned int columns;
	vector <vector <char>> Board_Cells;
	vector <char> indexes;
	void BlackCells();
	void DefineIndexes();
};

#endif