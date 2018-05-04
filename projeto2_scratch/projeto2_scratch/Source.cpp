#include <iostream>
#include "Dictionary.h"
#include "Board.h"

void OpenDictionary(string &FileName, ifstream &dictionaryFile)
{
	dictionaryFile.open(FileName); //open the text file (dictionary)

	while (!dictionaryFile.is_open()) //only allowed to move forward when the text file is opened
	{
		cerr << FileName << " not found, please verify it and introduce it again." << endl;
		cin.ignore(10000, '\n');
		cin >> FileName;

		if (cin.eof())
			exit(0);

		dictionaryFile.open(FileName);
	}
}

void CreatePuzzle()
{
	Dictionary dictionary;
	Board board;
	string FileName;
	ifstream dictionaryFile;
	unsigned int num_lines, num_columns;


	//creating the dictionary

	cout << "Dictionary file name ? ";
	cin >> FileName; //collects the file name of input (dictionary)

	OpenDictionary(FileName, dictionaryFile);
	dictionary.ExtractWords(dictionaryFile);
	dictionaryFile.close();


	// creating the board 

	cout << "Board size ? (lines columns) ";
	cin >> num_lines >> num_columns;

	while (cin.fail()) //if the input for lines and columns failed 
	{
		cin.ignore(1000000, '/n');
		cout << "Introduce a valid input for lines and columns. ";
		cin >> num_lines >> num_columns;
	}

	board.Create(num_lines, num_columns);
	board.Show();
}

void ResumePuzzle()
{

}

void ProgramInterface()
{
	int option;

	cout << "CROSSWORDS PUZZLE CREATOR" << endl
		<< "============================================" << endl << endl
		<< "INSTRUCTIONS:" << endl
		<< "Position( LCD / CTRL + Z = stop )" << endl
		<< " LCD stands for Line Column and Direction" << endl << endl
		<< "--------------------------------------------" << endl;

	while (true)
	{
		cout << "Options:" << endl
			<< "1 - Create Puzzle" << endl
			<< "2 - Resume Puzzle" << endl
			<< "0 - Exit" << endl
			<< "Option ? ";

		cin >> option;

		while (cin.fail() || option < 0 || option > 2) //only  allowed to move forward when the user writes a valid input
		{
			cerr << "Invalid input. Choose an option from the menu!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			cin >> option;

			if (cin.eof())
				exit(0);
		}

		switch (option)
		{
		case 0: exit(0);
		case 1:
			CreatePuzzle();
			break;
		case 2:
			ResumePuzzle();
			break;
		}
	}
}

int main()
{
	ProgramInterface();

	system("pause");

	return 0;
}