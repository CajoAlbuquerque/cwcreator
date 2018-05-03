#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Board
{
public:
	Board();
	~Board();
	void create(unsigned int lines, unsigned int columns);
	void show();
private:
	int _lines;
	int _columns;
	vector < vector < string > > cells;
};

#endif