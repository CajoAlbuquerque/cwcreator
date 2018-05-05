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
	void Insert(const string & lcd, const string & userWord);
	void Remove(const string & lcd);
	void Show();

private:
	unsigned int lines;
	unsigned int columns;
	vector <vector <char>> Board_Cells;
	vector <char> indexes;
	void DefineIndexes();
	void BlackCells();
	bool CheckLcd(unsigned int & l, unsigned int & c, unsigned int & d, const string & lcd);
	bool CheckSize(unsigned int l, unsigned int c, unsigned int d, const string & word);
	bool CheckMatching(unsigned int l, unsigned int c, unsigned int d, const string & word);
};

#endif