#include "AddWords.h"

void AddWords(std::string& line, std::map<std::string, int>& wordFreq)
{
	size_t pos = 0;
	while (true)
	{
		if (line.length() == 0)
		{
			break;
		}
		size_t spacePos = line.find(" ", pos);
		if (spacePos != std::string::npos)
		{
			++wordFreq[line.substr(pos, spacePos - pos)];
			pos = spacePos + 1;
		}
		else
		{
			++wordFreq[line.substr(pos, line.length() - pos)];
			break;
		}
	}
}