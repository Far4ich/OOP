#include <iostream>
#include "AddWords.h"

using namespace std;

void FillMap(std::map<std::string, int>& wordFreq)
{
	string line;

	while (getline(cin, line))
	{
		AddWords(line, wordFreq);
	}
}

void PrintMap(std::map<std::string, int>& wordFreq)
{
	map <string, int> ::iterator j = wordFreq.begin();
	for (int i = 0; j != wordFreq.end(); i++, j++)
	{
		cout << j->first << " " << j->second << "\n";
	}
}

int main()
{
	map <string, int> wordFreq;

	FillMap(wordFreq);

	PrintMap(wordFreq);

	return 0;
}