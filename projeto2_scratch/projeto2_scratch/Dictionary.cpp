#include "Dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

void Dictionary::Open()
{
	OpenFile(dictionaryFile);
	ExtractWords(dictionaryFile, wordList);
}

vector <string> Dictionary::MatchingWords()
{

}

void OpenFile(ifstream &dictionaryFile)
{
	std::string FileName;

	cout << "Dictionary file name ? ";
	cin >> FileName; //collects the file name of input (dictionary)

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

bool validWord(string word) //verifies if a word is valid
{
	size_t i = 0;

	while (i < word.length())
	{
		if (!(isalpha(word[i]) || word[i] == '\'' || word[i] == '-')) // it searches the entire word until it reaches the end or finds a char that is not an upper case letter
			return false;
		else i++;
	}

	return true;
}

void trimWord(string &word)
{
	int flag = 0; //this flag identifies which case we are dealing with
	size_t i = word.length() - 1; //index of the last char of the word

	while (word[0] == ' ' || word[0] == '\'' || word[0] == '-')
	{
		word = word.substr(1, i);
		i--;
	}

	while (word[i] == ' ' || word[i] == '\'' || word[i] == '-')
	{
		word = word.substr(0, i);
		i--;
	}
}

void separateWords(string line, map < string, vector <string> > &wordList)
{
	bool first_word = 1;
	string word = "";
	string keyword = "";
	vector <string> synonyms;

	for (size_t i = 0; i <= line.length(); i++) //searches the whole line, separating letters when it finds the end of the line or a ;
	{
		if ((i == line.length() && word != "") || line[i] == ':' || line[i] == ',' || line[i] == '\n')
		{
			trimWord(word); //trims the word

			if (validWord(word)) //if it is a valid word
			{
				if (first_word)
				{
					keyword = word;

					first_word = 0;
				}
				else synonyms.push_back(word); //it adds it to the end of the vector
			}
			word = ""; //reinitializes the word as null so it doesnt go accumulating characters
		}
		else
			word = word + line[i]; //accumulates chars to build a word
	}

	wordList.insert(pair < string, vector <string> > (keyword, synonyms));
}

void ExtractWords(ifstream &dictionaryFile, map < string, vector <string> > &wordList)
{
	string line;

	while (getline(dictionaryFile, line))//verify every line until the end of file
	{
		separateWords(line, wordList);
	}
}