#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

using namespace std;

class Dictionary
{
public:
	Dictionary();
	~Dictionary();
	void ExtractWords(ifstream &dictionaryFile);
	bool WordExists(string word);
	vector <string> MatchingWords();
	void EverythingToUpper(string &word);

private:
	map < string, vector <string> > wordList;

	void separateWords(string line, map < string, vector <string> > &wordList);
	bool validWord(string word);
	void trimWord(string &word);
};

#endif