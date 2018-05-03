#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	void Open();
	bool validWord();
	vector <string> MatchingWords();

private:

	ifstream dictionaryFile;
	map < string, vector <string> > wordList;
};

#endif