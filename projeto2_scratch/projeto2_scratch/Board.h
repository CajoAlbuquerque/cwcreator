#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

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
	void SaveBoard(ofstream &savingFile, string FileName);
	bool CheckLCD(const string & lcd);
	void ResumeBoard(ifstream &boardFile);

private:
	unsigned int lines;
	unsigned int columns;
	vector <vector <char>> Board_Cells;
	vector <char> indexes;
	vector < vector < string > > Words_on_Board;
	void DefineIndexes();
	void BlackCells();
	bool CheckSize(unsigned int l, unsigned int c, char d, const string & word);
	bool CheckMatching(unsigned int l, unsigned int c, unsigned int d, const string & word);
};

#endif