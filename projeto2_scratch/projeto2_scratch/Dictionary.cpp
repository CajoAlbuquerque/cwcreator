#include "Dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::~Dictionary()
{
}

void Dictionary::ExtractWords(ifstream &dictionaryFile)
{
	string line;

	while (getline(dictionaryFile, line))//verify every line until the end of file
	{
		separateWords(line, wordList, counter);
	}

	cout << "num of wwords: " << counter << endl;
}

/*
bool Dictionary::WordExists(string word)
{
	if (wordList.find(word) != wordList.end())
	{
		return true;
	}
	else if ()
		return true;
	else return false;
}

vector <string> Dictionary::MatchingWords()
{

}
*/

bool Dictionary::validWord(string word) //verifies if a word is valid
{
	size_t i = 0;

	while (i < word.length())
	{
		if (!(isalpha(word[i]) || word[i] == ' ')) // it searches the entire word until it reaches the end or finds a char that is not an upper case letter
			return false;
		else i++;
	}

	return true;
}

void Dictionary::trimWord(string &word)
{
	int flag = 0; //this flag identifies which case we are dealing with
	size_t i = word.length() - 1; //index of the last char of the word

	while (word[0] == ' ')
	{
		word = word.substr(1, i);
		i--;
	}

	while (word[i] == ' ')
	{
		word = word.substr(0, i);
		i--;
	}
}

void Dictionary::EverythingToUpper(string &word) // this function simply puts all letters in upper case
{
	size_t i = 0;

	while (i < word.length())
	{
		if (islower(word[i])) //if it is a letter and is in lower case, it makes it upper
		{
			word[i] = toupper(word[i]);
		}

		i++;
	}
}

void Dictionary::separateWords(string line, map < string, vector <string> > &wordList, unsigned int &counter)
{
	bool first_word = 1;
	string word = "";
	string keyword = "";
	vector <string> synonyms;

	for (size_t i = 0; i < line.length(); i++) //searches the whole line, separating letters when it finds the end of the line or a ;
	{
		if (i == line.length() - 1 || line[i] == ':' || line[i] == ',' || line[i] == '\n')
		{
			trimWord(word); //trims the word

			if (validWord(word)) //if it is a valid word
			{
				EverythingToUpper(word);

				counter++;
				
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