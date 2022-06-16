#include <iostream>
#include <fstream>
#include "FindAndReplace.h"

int main(int argc, char* argv[])
{
    if (argc == 3)
    {
        std::string searchStr = argv[1];
        std::string replaceStr = argv[2];
        std::string workStr;

        while (std::getline(std::cin, workStr))
        {
           std::cout << FindAndReplace(workStr, searchStr, replaceStr) << "\n";
        }

        return 0;
    }
    else
    {
        return 1;
    }
}
