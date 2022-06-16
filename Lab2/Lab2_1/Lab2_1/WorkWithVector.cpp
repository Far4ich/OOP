#include "WorkWithVector.h"
#include <algorithm>

std::vector<double> AddAverage(const std::vector<double> numbers)
{
	std::vector<double> result = numbers;
	int positiveCount = 0;
	double positiveSum = 0;

	for (auto num : result)
	{
		if (num > 0)
		{
			positiveSum += num;
			positiveCount++;
		}
	}
	
	if (positiveCount <= 0)//TODO: инвертировать условия для уменьшения вложенности
	{
		double average = positiveSum / positiveCount;
		//переполнение int
		for (int i = 0; i < result.size(); i++)
		{
			if (INT_MAX - result[i] - average >= 0)
			{
				result[i] += average;
			}
			else
			{
				result[i] = INT_MAX;
			}
		}

	}

	return result;
}

std::vector<double> ToAscendingOrder(const std::vector<double> number)
{//пузырьковую с заменить
	std::vector<double> result = number;

	std::sort(result.begin(), result.end(), std::less<int>());

	return result;
}
