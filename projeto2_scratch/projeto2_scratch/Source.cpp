#include <iostream>
#include "Dictionary.h"
#include "Board.h"

void OpenFile(string &FileName, ifstream &File)
{
	File.open(FileName); //open the text file (dictionary)

	while (!File.is_open()) //only allowed to move forward when the text file is opened
	{
		cerr << FileName << " not found, please verify it and introduce it again." << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> FileName;

		if (cin.eof())
			exit(0);

		File.open(FileName);
	}
}

void SaveCrosswords(Board board, string dictionaryFileName)
{
	char option;

	cin.ignore(10000, '\n');
	cin.clear();

	cout << "Do you wish to save the current board? (Y/N)  ";
	cin >> option;

	while (cin.fail() || !(option == 'Y' || option == 'N'))
	{
		cerr << "Invalid input. Do you wish to save the current board? (Y/N)  ";
		cin.ignore(10000, '\n');
		cin.clear();
		cin >> option;
	}

	if (option == 'N')
		return;

	string FileName;
	ofstream savingFile;

	while (true)
	{
		cout << "Insert name of the file you want to save the board in. (It must be \"bXXX\", X being numbers.)  ";
		cin >> FileName;

		if (FileName.length() == 4 && FileName[0] == 'b' && isdigit(FileName[1]) && isdigit(FileName[2]) && isdigit(FileName[3]))
			break;
		else cout << "Invalid name. " << endl;
	}

	FileName = FileName + ".txt";

	savingFile.open(FileName);

	board.SaveBoard(savingFile, dictionaryFileName);

	savingFile.close();

	cout << endl << "Board has been saved.";
}

void Game(Dictionary dictionary, Board board, string FileName)
{
	string user_lcd, user_word;

	while (true)
	{
		cout << endl << endl;
		board.Show();

		cout << "Position ( LCD / CTRL-Z = stop ) ? ";
		cin >> user_lcd;

		if (cin.eof())
		{
			SaveCrosswords(board, FileName);

			cout << endl << endl;

			break;
		}

		while (!board.CheckLCD(user_lcd))
		{
			cout << "Invalid input for position." << endl
				<< "Verify if you are using the indexes shown in the order: Line(upper) Column(lower) Direction(V or H).  ";
			cin >> user_lcd;
		}

		cout << "Word ( - = remove / ? = help ) ? "; 
		cin >> user_word;

		if (user_word == "-")
		{

		}
		else if (user_word == "?")
		{

		}
		else
		{
			dictionary.EverythingToUpper(user_word);

			if (dictionary.WordExists(user_word))
			{
				board.Insert(user_lcd, user_word);
			}
			else cout << "Invalid word." << endl;
		}
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

	OpenFile(FileName, dictionaryFile);

	cout << "Text file is loading...Please wait." << endl << endl;

	dictionary.ExtractWords(dictionaryFile);
	dictionaryFile.close();

	// creating the board 

	cout << "Board size ? (lines columns, max. 26) ";
	cin >> num_lines >> num_columns;

	while (cin.fail() || num_lines > 26 || num_columns > 26) //if the input for lines and columns failed 
	{
		cerr << "Introduce a valid input for lines and columns. ";
		cin.clear();
		cin.ignore(10000, '\n');
		cin >> num_lines >> num_columns;
	}

	board.Create(num_lines, num_columns);

	Game(dictionary, board, FileName);
}

void ResumePuzzle()
{
	Dictionary dictionary;
	Board board;
	string FileName;
	ifstream dictionaryFile, boardFile;

	//loading board
	cout << "Board file name ? ";
	cin >> FileName; //collects the file name of input (board)

	OpenFile(FileName, boardFile); //opens the board using that file name

	getline(boardFile, FileName); //collects the file name of input (dictionary), now the variable FileName holds the name of the dictionary file

	OpenFile(FileName, dictionaryFile); //opens the dictionary using that file name

	cout << "Text file is loading...Please wait." << endl;

	dictionary.ExtractWords(dictionaryFile); //extracts the words from the dictionary
	dictionaryFile.close(); //closes the dictionary

	board.ResumeBoard(boardFile); //extracts the words present in the board
	boardFile.close(); // closes the board file

	Game(dictionary, board, FileName); //remember that the string saved in FileName is the name of the dictionary
}

void ProgramInterface()
{
	int option;

	cout << "CROSSWORDS PUZZLE CREATOR" << endl
		<< "============================================" << endl << endl
		<< "INSTRUCTIONS:" << endl
		<< "- This program let's you build crosswords freely. All you need to introduce is a dictionary file." << endl
		<< "- You may choose how many lines and columns the board will have (having a maximum of 26 each)." << endl
		<< "- To write on the board it will appear Position( LCD / CTRL + Z = stop ), whereas LCD stands for Line Column and Direction, the indexes of the line are marked in the left side of the board,"
		<< "the indexes of the column are marked on top of the board, you should introduce it as they are seen: lines in upper case, columns in lower case. "
		<< "This first two letters for lines and columns demark the spot where the first letter of the word will be written. The direction may be V (for vertical) or H (for horizontal)." << endl
		<< "- Then, it will ask you for a word, it will only accept it if the word exists on the dictionary you have given." << endl
		<< "- After inserting a certain position in the first question ( Position ? ), when asked for a word, you may also introduce '-' (hiphen) or '?' (exclamation point)."
		<< "The first means you want to remove the word you have introduced before in the position, the second, gives you a list of words that fit in the position you have required, taking in consideration the availability of the board." << endl
		<< "- If you want to leave in the middle of building the board you should press 'Ctrl + Z', if you can then choose to save it or not." << endl
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