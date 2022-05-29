#pragma once

class CPoint
{
public:
	double x;
	double y;

	double GetDistance(CPoint target) const
	{
		return sqrt(pow(target.x - x, 2) + pow(target.y - y, 2));
	}
};