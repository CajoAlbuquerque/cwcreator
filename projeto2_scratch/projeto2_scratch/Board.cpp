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


bool Board::CheckLCD(const string & lcd)//decodes user input lcd (line column and direction) returning l and c as indexes and d as flag (1 - Vertical; 0 - Horizontal)
{	//also verifies if the user lcd is valid

	unsigned int l, c;

	l = ((int)lcd[0] - (int)'A');
	if (l >= lines)
		return false;

	c = ((int)lcd[1] - (int)'a');
	if (c >= columns)
		return false;

	if (lcd[2] == 'V' || lcd[2] == 'v' || lcd[2] == 'H' || lcd[2] == 'h')
		return true;

	return false;
}

bool Board::CheckSize(unsigned int l, unsigned int c, char d, const string & word) //checks if the word fits in the board
{
	size_t i;

	if (d == 'V' || d == 'v')
	{
		i = l + word.length();
		if (i > lines)			//when writing vertically, we need to check if the length of the word plus the starting position is greater then the total number of columns
			return false;
	}
	else
	{
		i = c + word.length();
		if (i > columns)		//when writing horizontally, we need to check if the length of the word plus the starting position is greater then the total number of lines
			return false;
	}

	return true;
}

bool Board::CheckMatching(unsigned int l, unsigned int c, unsigned int d, const string & word) //checks if the user input can be matched with the words on the board (crosswords)
{
	size_t i;

	if (d == 'V' || d == 'v')				  //writing vertically
	{
		if (l != 0)
		{
			if (isalpha(Board_Cells[l - 1][c]))
				return false;
			else
				Board_Cells[l - 1][c] = '#'; //
		}


		for (i = 0; i < word.length(); i++)
		{
			if (Board_Cells[l + i][c] == '#')
			{
				return false;
			}
			else if (isalpha(Board_Cells[l + i][c]))
			{
				if (Board_Cells[l + i][c] != word[i])
					return false;
			}
		}

		if ((l + i) < lines)
		{
			if (isalpha(Board_Cells[l + i][c]))
				return false;
			else
				Board_Cells[l + i][c] = '#'; //
		}

	}
	else				 //writing horizontally
	{
		if (c != 0)
		{
			if (isalpha(Board_Cells[l][c - 1]))
				return false;
			else
				Board_Cells[l][c - 1] = '#'; //
		}

		for (i = 0; i < word.length(); i++)
		{
			if (Board_Cells[l][c + i] == '#')
			{
				return false;
			}
			else if (isalpha(Board_Cells[l][c + i]))
			{
				if (Board_Cells[l][c + i] != word[i])
					return false;
			}
		}

		if ((c + i) < columns)
		{
			if (isalpha(Board_Cells[l][c + i]))
				return false;
			else
				Board_Cells[l][c + i] = '#'; 
		}
	}

	return true;
}

void Board::BlackCells()
{

}

void Board::Create(unsigned int num_lines, unsigned int num_columns) //creates the board filled with dots
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
	unsigned int l = ((int)lcd[0] - (int)'A');
	unsigned int c = ((int)lcd[1] - (int)'a');
	char d = lcd[2];

	if (!CheckSize(l, c, d, word))
	{
		cerr << "Invalid size. Word is too long." << endl;
		return;
	}

	if (!CheckMatching(l, c, d, word))
	{
		cerr << "Invalid match. Word doesn't match the existing letters." << endl;
		return;
	}

	if (d == 'V' || d == 'v')				  //writing vertically
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			Board_Cells[l + i][c] = word[i];
		}
	}
	else //writing horizontally
	{
		for (size_t i = 0; i < word.length(); i++)
		{
			Board_Cells[l][c + i] = word[i];
		}
	}

	vector <string> pair_lcd_word(2);

	pair_lcd_word[0] = lcd;
	pair_lcd_word[1] = word;

	Words_on_Board.push_back(pair_lcd_word);
}

void Board::SaveBoard(ofstream &savingFile, string dictionaryFileName)
{
	savingFile << dictionaryFileName << endl << endl;

	for (size_t i = 0; i < lines; i++)
	{
		for (size_t k = 0; k < columns; k++)
			savingFile << setw(2) << Board_Cells[i][k];

		savingFile << endl;
	}

	savingFile << endl << endl;

	for (size_t i = 0; i < Words_on_Board.size(); i++)
	{
		savingFile << Words_on_Board[i][0] << " " << Words_on_Board[i][1] << endl;
	}
}

void Board::ResumeBoard(ifstream &boardFile)
{
	string line;
	unsigned int counter = 0;

	while (getline(boardFile, line))
	{
		counter++;
		if (isupper(line[0]) && islower(line[1]) && line[3] == ' ')
		{

		}
	}
}