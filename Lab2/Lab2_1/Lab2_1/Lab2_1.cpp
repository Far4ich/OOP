#include <iostream>
#include <vector>
#include <fstream>
#include "WorkWithVector.h"

using namespace std;

int main()
{
    vector<double> numbers(istream_iterator<double>(cin), (istream_iterator<double>()));

    vector<double> result = AddAverage(numbers);

    result = ToAscendingOrder(result);

    copy(result.begin(), result.end(), ostream_iterator<double>(cout, " "));

    return 0;
}